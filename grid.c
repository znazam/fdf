/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 07:37:40 by znazam            #+#    #+#             */
/*   Updated: 2019/07/15 11:20:15 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int		grid(t_env *env, const char *filename)
{
	int fd;
	char *line;
	t_list *split;
	t_list *head;
	
	head = NULL;
	env->sizey = 0;
	env->sizet = 0;

	fd = open(filename, O_RDONLY);
	while(get_next_line(fd, &line))
	{
		split = ft_lstnew(NULL, 0);
		split->content = ft_strsplit(line, ' ');
		ft_lstadd(&head, split);
		env->sizex = 0;
		while (((char**)split->content)[env->sizex])
		{
			env->sizex++;
			env->sizet++;
		}
		env->sizey++;
	}
	env->map = ft_memalloc(sizeof(t_coord) * (env->sizet + 1));
	t_list *cur;
	cur = head;
	int j = 0;
	while (cur)
	{
		int i = -1;
		while(((char**)cur->content)[++i])
		{
			env->map[j * env->sizex + i].x = i - (env->sizex - 1) * 0.5;
			env->map[j * env->sizex + i].y = j - (env->sizey - 1) * 0.5;
			env->map[j * env->sizex + i].z = ft_atoi(((char**)cur->content)[i]);
		}
		j++;
		cur = cur->next;
	}
	return(0);
}

int		fill()
{
	return(0);
}
