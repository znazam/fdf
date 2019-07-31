/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 08:30:38 by znazam            #+#    #+#             */
/*   Updated: 2019/07/29 13:30:37 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_liney(t_env *env, t_pixel a, t_pixel b)
{
	double	change;
	double	grad;
	double	i;

	change = b.y - a.y;
	grad = (b.x - a.x) / change;
	i = -1;
	while (++i < (ABS(change)))
        pixel_put_image(&env->img, 0xFFFF00, a.x + (DR(i)) * grad, a.y + (DR(i)));
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
			pixel_put_image(&env->img, 0xFF00FF, a.x + DR(i), a.y + DR(i) * grad);
	}
}

int fun(void *data)
{
    t_pixel b;
    t_pixel e;
    b.x = 0;
    b.y = 0;
    e.x = 1000;
    e.y = 1000;
    static float rotation = -0.9;
    rotation += 0.01;
    float c = cos(rotation);
    float s = sin(rotation);
    t_env * env = (t_env *)data;
    clear_image(&env->img, 0x000000);
    int x;
    int y;
    t_coord p;
    t_pixel *result;

    y = 0;
    result = ft_memalloc(sizeof(t_pixel) * env->sizet);
    while (y < env->sizey)
    {
        x = 0;
        while (x < env->sizex)
        {
            ft_memcpy(&p, &env->map[x + y * env->sizex], sizeof(t_coord));
            double tempy;
            tempy = p.z * s + p.y * c;
            p.z = p.z * c - p.y * s;
            p.y = tempy;
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
    
    for (int i = 0; i < (env->sizet - 1); i++)
     {
         if (((i + 1) % env->sizex) != 0)
             draw_line(env, result[i], result[i + 1]);
         if (i < (env->sizet - env->sizex))
             draw_line(env, result[i], result[i + env->sizex]);
    }
    put_image(env, &env->img);
    free(result);
    return 0;
}