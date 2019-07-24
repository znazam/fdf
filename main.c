/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 09:02:43 by znazam            #+#    #+#             */
/*   Updated: 2019/07/24 08:49:11 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "GNL/get_next_line.h"
#include <fcntl.h>

int	exitb(int button)
{
	if (button == 53)
		exit(0);
	return (0);
}

// void  p(t_env *env)
// {
//   t_pixel middle;
//   t_pixel right;
//   t_pixel left;
//   t_pixel down;
//   t_pixel ul;
//   t_pixel ur;
//   t_pixel dl;
//   t_pixel dr;
//   t_pixel up;

//   middle.x = 250;
//   middle.y = 250;

//   right.x = 500;
//   right.y = 250;
//   left.x = 0;
//   left.y = 250;
//   down.x = 250;
//   down.y = 500;
//   up.x = 250;
//   up.y = 0;
//   ul.x = 0;
//   ul.y = 0;
//   ur.x = 500;
//   ur.y = 0;
//   dl.x = 0;
//   dl.y = 500;
//   dr.x = 500;
//   dr.y = 500;
//   draw_line(env, middle, left);
//   draw_line(env, middle, right);
//   draw_line(env, middle, up);
//   draw_line(env, middle, down);
//   draw_line(env, middle, ur);
//   draw_line(env, middle, dl);
  
//   draw_line(env, middle, ul);
//   draw_line(env, middle, dr);
// }
int main(int ac, char **av)
{
    t_env env;
    // char *line;

    env.mlx_ptr = mlx_init();
    env.win_ptr = mlx_new_window(env.mlx_ptr, SCREEN_W, SCREEN_H, "test");

    if (ac < 2)
      return (0);
    // int fd = open("hello.txt", O_RDONLY);
    // while (get_next_line(fd, &line) > 0)
    // {
    //   free(line);
    // }
    
    (void) av;
  
    grid(&env, av[1]);
    mlx_loop_hook(env.mlx_ptr, fun, &env);
    mlx_hook(env.win_ptr, 17, 0L, exitfun, &env);
  	mlx_key_hook(env.win_ptr, exitb, 0);
    //p(&env);
    mlx_loop(env.mlx_ptr);
    return (0);
}