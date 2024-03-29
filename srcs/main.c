/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 09:02:43 by znazam            #+#    #+#             */
/*   Updated: 2019/08/20 09:15:03 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	exitb(int button)
{
	if (button == 53)
		exit(0);
	return (0);
}

int	exitfun(void *data)
{
	(void)data;
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	env;
	int		fd;

	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, SCREEN_W, SCREEN_H, "test");
	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		error_check(2);
	else
	{
		if (fd == -1)
			error_check(0);
		init_image(&env, &env.img, SCREEN_W, SCREEN_H);
		grid(&env, av[1]);
		mlx_loop_hook(env.mlx_ptr, fun, &env);
		mlx_hook(env.win_ptr, 17, 0L, exitfun, &env);
		mlx_key_hook(env.win_ptr, exitb, 0);
		mlx_loop(env.mlx_ptr);
	}
	return (0);
}
