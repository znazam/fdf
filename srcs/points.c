/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 08:30:38 by znazam            #+#    #+#             */
/*   Updated: 2019/08/06 16:23:21 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_liney(t_env *env, t_pixel a, t_pixel b)
{
	double	change;
	double	grad;
	double	i;

	change = b.y - a.y;
	grad = (b.x - a.x) / change;
	i = -1;
	while (++i < (ABS(change)))
		pixel_put_image(&env->img, 0xFFFF00, a.x + (DR(i)) * grad, a.y +
		(DR(i)));
}

void		draw_line(t_env *env, t_pixel a, t_pixel b)
{
	double	change;
	double	ychange;
	double	grad;
	double	i;

	change = b.x - a.x;
	ychange = b.y - a.y;
	if (ABS(ychange) > (ABS(change)))
		draw_liney(env, a, b);
	else
	{
		grad = ychange / change;
		i = -1;
		while (++i < ABS(change))
			pixel_put_image(&env->img, 0xFF00FF, a.x + DR(i), a.y + DR(i) *
			grad);
	}
}

void		draw_faces(t_env *env, t_pixel *result)
{
	int i;

	i = 0;
	while (i < (env->sizet - 1))
	{
		if (((i + 1) % env->sizex) != 0)
			draw_line(env, result[i], result[i + 1]);
		if (i < (env->sizet - env->sizex))
			draw_line(env, result[i], result[i + env->sizex]);
		i++;
	}
}

void		rotation(t_coord *p)
{
	double			tempy;
	static float	rotation = -0.9;
	float			c;
	float			s;

	c = cos(rotation);
	s = sin(rotation);
	rotation += 0.0001;
	tempy = p->z * s + p->y * c;
	p->z = p->z * c - p->y * s;
	p->y = tempy;
}

int			fun(void *data)
{
	t_env	*env;
	int		x;
	int		y;
	t_coord	p;
	t_pixel	*result;

	env = (t_env *)data;
	y = 0;
	clear_image(&env->img, 0x000000);
	result = ft_memalloc(sizeof(t_pixel) * env->sizet);
	while (y < env->sizey)
	{
		x = 0;
		while (x < env->sizex)
		{
			ft_memcpy(&p, &env->map[x + y * env->sizex], sizeof(t_coord));
			rotation(&p);
			p.x *= 30;
			p.y *= 30;
			p.x += SCREEN_W * 0.5;
			p.y += SCREEN_H * 0.5;
			result[x + y * env->sizex].x = p.x;
			result[x + y * env->sizex].y = p.y;
			x++;
		}
		y++;
	}
	draw_faces(env, result);
	put_image(env, &env->img);
	free(result);
	return (0);
}
