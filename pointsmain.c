#include <mlx.h>
#include <stdlib.h>
# define PIXEL mlx_pixel_put(mlx, win, x, y, 0x0ffffff)
# define ABS(X) (X < 0 ? -X : X) 

typedef struct  s_pixel
{
    int x;
    int y;
}               t_pixel;

typedef struct  s_env
{
    void *mlx_ptr;
    void *win_ptr;
}               t_env;

#include <stdio.h>

void draw_box(t_env *env, t_pixel a, t_pixel b)
{
    int x;
    int y;

    if (a.x > b.x)
    {
        int temp = a.x;
        a.x = b.x;
        b.x = temp;
    }
    if (a.y > b.y)
    {
        int temp = a.y;
        a.y = b.y;
        b.y = temp;
    }
    y = a.y;
    while (y < b.y)
    {
        x = a.x;
        while (x < b.x)
        {
            mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, 0xffffff);
            x++;
        }
        y++;
    }
}
void draw_line_y(t_env *env, t_pixel a, t_pixel b)
{
    double x;
    double y;

    int dx;
    int dy;

    double gradient;

    dx = b.x - a.x;
    dy = b.y - a.y;

    gradient = (double)dx / (double)dy;
    y = 0;
    x = 0;
    while (y < ABS(dy))
    {
        mlx_pixel_put(env->mlx_ptr, env->win_ptr, a.x + y * gradient, a.y + y, 0xffffff);
        y++;
    }
}

void draw_line(t_env *env, t_pixel a, t_pixel b)
{
    double x;
    double y;

    int dx;
    int dy;

    double gradient;

    dx = b.x - a.x;
    dy = b.y - a.y;

    gradient = (double)dy / (double)dx;
    if (gradient > 1)
        draw_line_y(env, a, b);
    y = 0;
    x = 0;
    while (x < ABS(dx))
    {
        mlx_pixel_put(env->mlx_ptr, env->win_ptr, a.x + x, a.y + x * gradient, 0xffffff);
        x++;
    }
}

int fun(void *data)
{
    t_env * env = (t_env *)data;
    t_pixel p;
    p.x = 50;
    p.y = 50;
    t_pixel p1;
    p1.x = 100;
    p1.y = 300;

    draw_line(env, p, p1);

    return 0;
}

int exitfun(void *data)
{
    exit(0);
    return 0;
}

int main()
{
    t_env env;
    env.mlx_ptr = mlx_init();
    env.win_ptr = mlx_new_window(env.mlx_ptr, 500, 500, "test");

    mlx_loop_hook(env.mlx_ptr, fun, &env);
    mlx_hook(env.win_ptr, 17, 0L, exitfun, &env);
    mlx_loop(env.mlx_ptr);
    return (0);
}