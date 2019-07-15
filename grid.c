/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 07:37:40 by znazam            #+#    #+#             */
/*   Updated: 2019/07/12 09:20:25 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int		grid(t_env *env, const char *filename)
{
	int fd;
	char *line;
	char **split;
	
	env->sizey = 0;
	env->sizet = 0;

	fd = open(filename, O_RDONLY);
	while(get_next_line(fd, &line))
	{
		split = ft_strsplit(line, ' ');
		env->sizex = 0;
		while (split[env->sizex])
		{
			printf("%s, %i, %i\n", split[env->sizex], env->sizex, env->sizey);
			env->sizex++;
			env->sizet++;
		}
		env->sizey++;
	}
	env->map = ft_memalloc(sizeof(t_coord) * env->sizet);
	return(0);
}

int		fill()
{
	return(0);
}
