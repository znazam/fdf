/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 07:37:40 by znazam            #+#    #+#             */
/*   Updated: 2019/07/15 10:26:02 by znazam           ###   ########.fr       */
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
		printf("Hello\n");
		ft_lstadd(&head, split);
		printf("Bye\n");
		env->sizex = 0;
		while (((char**)split->content)[env->sizex])
		{
			env->sizex++;
			env->sizet++;
		}
		env->sizey++;
	}
	env->map = ft_memalloc(sizeof(t_coord) * env->sizet);
	t_list *cur;
	cur = head;
	while (cur)
	{
		int i = -1;
		while(((char**)split->content)[++i])
			printf("%i: %s\n", i, ((char**)split->content)[i]);
		cur = cur->next;
	}
	return(0);
}

int		fill()
{
	return(0);
}
