#include <mlx.h>
#include <stdlib.h>
# define PIXEL mlx_pixel_put(mlx, win, x, y, 0x0ffffff)
# define ABS abs()
int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 500, 500, "test");
    int r0;
    int r1;
    int d0;
    int d1;
    int dr = r0 - r1;
    int dd = d0 - d1; 
    int steps;
    int xi;
    int yi;
    int v = 0;
    int x;
    int y;

    r0 = 250;
    r1 = 300;
    d0 = 250;
    d1 = 300;
    if (ABS(dr) > ABS(dd))
        steps = ABS(dr);
    else
        steps = ABS(dd);
    xi = dr / (float) steps;
    yi = dd / (float) steps;
    if (v < steps)
    {
        x = x + xi;
        y = y + yi;
        PIXEL;
    }

    mlx_loop(mlx);
    return (0);
}