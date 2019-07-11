#include "fdf.h"

int	main()
{
    void    *mlx;
    void    *win;
    
    mlx = mlx_init();
	win = mlx_new_window (mlx, 500, 500, "test");

    int right = 250;
    int down = 250;

       while (right > 1)
    {
        PIXEL;
        right --;
        down ++;
    }

   while (right < 500)
    {
        PIXEL;
        right ++;
    }

    while (right > 250)
    {
        PIXEL;
        down --;
        right --;
    }
    mlx_loop(mlx);
    return(0);
}
