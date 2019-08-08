/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 08:30:38 by znazam            #+#    #+#             */
/*   Updated: 2019/08/08 14:45:33 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw_liney(t_env *env, t_pixel a, t_pixel b)
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
	rotation += 0.00001;
	tempy = p->z * s + p->y * c;
	p->z = p->z * c - p->y * s;
	p->y = tempy;
	p->x *= 30;
	p->y *= 30;
	p->x += SCREEN_W * 0.5;
	p->y += SCREEN_H * 0.5;
}

int			fun(void *data)
{
	t_points_data pd;

	pd.env = (t_env *)data;
	pd.y = 0;
	clear_image(&pd.env->img, 0x000000);
	pd.result = ft_memalloc(sizeof(t_pixel) * pd.env->sizet);
	while (pd.y < pd.env->sizey)
	{
		pd.x = 0;
		while (pd.x < pd.env->sizex)
		{
			ft_memcpy(&pd.p, &pd.env->map[pd.x + pd.y * pd.env->sizex],
			sizeof(t_coord));
			rotation(&pd.p);
			pd.result[pd.x + pd.y * pd.env->sizex].x = pd.p.x;
			pd.result[pd.x + pd.y * pd.env->sizex].y = pd.p.y;
			pd.x++;
		}
		pd.y++;
	}
	draw_faces(pd.env, pd.result);
	put_image(pd.env, &pd.env->img);
	free(pd.result);
	return (0);
}
