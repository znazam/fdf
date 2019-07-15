/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 08:30:38 by znazam            #+#    #+#             */
/*   Updated: 2019/07/15 15:43:20 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdlib.h>
# define ABS(X) (X < 0 ? -X : X) 

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
    int x;
    int y;
    t_coord p;
    t_pixel *result;

    y = 0;
    result = ft_memalloc(sizeof(t_pixel) * env->sizet);
    printf("=================\n\n");
    while (y < env->sizey)
    {
        x = 0;
        while (x < env->sizex)
        {
            ft_memcpy(&p, &env->map[x + y * env->sizex], sizeof(t_coord));
            printf("%f, %f, %f\n", p.x, p.y, p.z);
            p.x *= 50;
            p.y *= 50;
            p.x += SCREEN_W * 0.5;
            p.y += SCREEN_H * 0.5;
            result[x + y * env->sizex].x = p.x;
            result[x + y * env->sizex].y = p.y;
            x++;
        }
        y++;
    }
    printf("=================\n\n");
    for (int i = 0; i < (env->sizet - 1); i++)
    {
        draw_line(env, result[i], result[i + 1]);
    }
    free(result);

    return 0;
}

int exitfun(void *data)
{
    (void)data;
    exit(0);
    return 0;
}