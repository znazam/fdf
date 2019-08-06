/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 07:37:40 by znazam            #+#    #+#             */
/*   Updated: 2019/08/06 14:16:43 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_delete(void *content, size_t size)
{
	size_t	i;
	char	**lines;

	(void)size;
	lines = (char **)content;
	i = 0;
	while (lines[i])
	{
		ft_putendl(lines[i]);
		free(lines[i++]);
	}
	free(lines);
}

void	gline(t_env *env, t_list *head)
{
	int		i;
	int		j;
	t_list	*cur;

	cur = head;
	j = 0;
	env->map = ft_memalloc(sizeof(t_coord) * (env->sizet + 1));
	while (cur)
	{
		i = -1;
		while (((char**)cur->content)[++i])
		{
			env->map[j * env->sizex + i].x = i - (env->sizex - 1) * 0.5;
			env->map[j * env->sizex + i].y = j - (env->sizey - 1) * 0.5;
			env->map[j * env->sizex + i].z = ft_atoi(((char**)cur->content)[i]);
		}
		j++;
		cur = cur->next;
	}
}

int		grid(t_env *env, const char *filename)
{
	t_grid_data gd;

	gd.head = NULL;
	env->sizey = 0;
	env->sizet = 0;
	gd.fd = open(filename, O_RDONLY);
	while (get_next_line(gd.fd, &gd.line) > 0)
	{
		gd.split = ft_lstnew(NULL, 0);
		gd.split->content = ft_strsplit(gd.line, ' ');
		ft_lstadd(&gd.head, gd.split);
		free(gd.line);
		env->sizex = 0;
		while (((char**)gd.split->content)[env->sizex])
		{
			env->sizex++;
			env->sizet++;
		}
		env->sizey++;
	}
	gline(env, gd.head);
	ft_lstdel(&gd.split, line_delete);
	return (0);
}
