/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 09:02:43 by znazam            #+#    #+#             */
/*   Updated: 2019/07/18 08:26:27 by znazam           ###   ########.fr       */
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
    
    grid(&env, av[1]);
    mlx_loop_hook(env.mlx_ptr, fun, &env);
    mlx_hook(env.win_ptr, 17, 0L, exitfun, &env);
  	mlx_key_hook(env.win_ptr, exitb, 0);
    mlx_loop(env.mlx_ptr);
    return (0);
}