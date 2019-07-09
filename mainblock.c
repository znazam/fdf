#include <mlx.h>

#define PIXEL mlx_pixel_put (mlx, win, right, down, 0x0ffffff)

int	main()
{
    void    *mlx;
    void    *win;
    
    mlx = mlx_init();
	win = mlx_new_window (mlx, 500, 500, "test");

    int right = 100;
    int down = 100;

       while (right < 300)
    {
        PIXEL;
        right ++;
    }

    while (down < 300)
    {
        PIXEL;
        down ++;
    }

    while (right > 100)
    {
        PIXEL;
        right --;
    }

    while (down > 100)
    {
        PIXEL;
        down --;
    }
       mlx_loop(mlx);
       return(0);
}