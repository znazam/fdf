/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 07:37:40 by znazam            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/06 08:08:24 by znazam           ###   ########.fr       */
=======
/*   Updated: 2019/08/02 09:09:47 by znazam           ###   ########.fr       */
>>>>>>> 4ccc67fa559d632256f486aad925522ebeba577c
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void line_delete(void *content, size_t size)
{
	size_t i;
	char **lines;

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

void	get_sizes(const char *path, t_env *env)
{
	int fd;
	char *line;
	int counter = 0;

	fd = open(path, O_RDONLY);
	env->sizey = 0;
	env->sizex = 0;
	while (get_next_line(fd, &line) > 0)
	{
		env->sizex = 0;
		counter = 0;
		while (line[counter] != '\0')
		{
			if (line[counter] != ' ' && line[counter] != '-')
			{
				env->sizex++;
				env->sizet++;
			}
			counter++;
		}
		env->sizey++;
	}
	write(1, "HERE", 4);
}

int		grid(t_env *env, const char *filename)
{
	int fd;
	char *line;
	//t_list *split;
	t_list *head;
	t_list	*tmp;
	
<<<<<<< HEAD
	head = NULL;
	env->sizey = 0;
	env->sizet = 0;
	fd = open(filename, O_RDONLY);
=======
	//head = NULL;
	//env->sizey = 0;
	//env->sizet = 0;

	head = ft_lstnew(NULL, 0);
	fd = open(filename, O_RDONLY);
	//write(1, "REACH", 5);
	printf("REACH!");
>>>>>>> 4ccc67fa559d632256f486aad925522ebeba577c
	while (get_next_line(fd, &line) > 0)
	{
		tmp = head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_lstnew(line, ft_strlen(line));
		//split->content = ft_strsplit(line, ' ');
		//ft_lstadd(&head, split);
		free(line);
	}
	tmp = head;
    tmp = tmp->next;
    free(head);
    head = tmp;
	/*while(head->next != NULL)
	{
		env->sizex = 0;
		while (head->content[env->sizey][env->sizex])
		{
			env->sizex++;
			env->sizet++;
		}
		env->sizey++;
		split = split->next;
	}*/
	while (head->next != NULL)
	{
		char *c;
		c = head->content;
		ft_putstr(c);
		write(1, "\n", 1);
		head = head->next;
	}
<<<<<<< HEAD
=======
	get_sizes(filename, env);
	write(1, "REACH!", 5);
>>>>>>> 4ccc67fa559d632256f486aad925522ebeba577c
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
	ft_lstdel(&head, line_delete);
	return(0);
}

/*void		ft_lstnew_fdf(t_env *env, int x_size, int y_size, int total_size)
{
	env->sizex = x_size;
	env->sizey = y_size;
	env->sizet = total_size;
}

void		get_sizes(t_env *env, char *path)
{
	t_info			info;

	info.total_size = 0;
	info.y_size = 0;
	info.fd = open(path, O_RDONLY);
	while (get_next_line(info.fd, &info.line) > 0)
	{
		info.x_size = 0;
		info.inf = ft_strsplit(info.line, ' ');
		while (info.inf[info.x_size])
		{
			free(info.inf[info.x_size]);
			info.total_size++;
			info.x_size++;
		}
		free(info.inf);
		free(info.line);
		info.y_size++;
	}
	ft_lstnew_fdf(env, info.x_size, info.y_size, info.total_size);
}

void				m_func(t_env *env)
{
	env->coord = (t_coord *)malloc(sizeof(t_coord) * env->sizet);
	//master->s_cords = (t_point *)malloc(sizeof(t_point) * master->grid.num_tot);
}

void				free_func(t_info info)
{
	free(info.inf);
	free(info.line);
}

void				interpreter(const char *path, t_env *env)
{
	t_info	info;

	info.total_size = 0;
	info.y_size = 0;
	m_func(env);
	info.fd = open(path, O_RDONLY);
	while (get_next_line(info.fd, &info.line) > 0)
	{
		info.x_size = 0;
		info.inf = ft_strsplit(info.line, ' ');
		//checker(maste, info);
		while (info.x_size < env->sizex)
		{
			env->coord[info.total_size].x = info.x_size -
			(env->sizex - 1) * 0.5;
			env->coord[info.total_size].y = info.y_size -
			(env->sizey - 1) * 0.5;
			env->coord[info.total_size].z = ft_atoi(info.inf[info.x_size]);
			free(info.inf[info.x_size]);
			info.x_size++;
			info.total_size++;
		}
		free_func(info);
		info.y_size++;
	}
}*/