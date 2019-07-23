/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 08:30:38 by znazam            #+#    #+#             */
/*   Updated: 2019/07/23 09:29:11 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdlib.h>
# define ABS(X) (X < 0 ? -X : X) 
#include <stdio.h>

void draw_box(t_env *env, t_pixel a, t_pixel b)
{
    int x;
    int y;

    if (a.x > b.x)
    {
        int temp = a.x;
        a.x = b.x;
        b.x = temp;
    }
    if (a.y > b.y)
    {
        int temp = a.y;
        a.y = b.y;
        b.y = temp;
    }
    y = a.y;
    while (y < b.y)
    {
        x = a.x;
        while (x < b.x)
        {
            mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, 0x000000);
            x++;
        }
        y++;
    }
}

void draw_line_y(t_env *env, t_pixel a, t_pixel b)
{
    double x;
    double y;

    int dx;
    int dy;
    int tmp;

    double gradient;

    dx = b.x - a.x;
    dy = b.y - a.y;

    gradient = (double)dx / (double)dy;
    y = 0;
    x = 0;
    if (a.y > b.y)
    {
        tmp = a.y;
        a.y = b.y;
        b.y = tmp;
    }
    while (y < ABS(dy))
    {
        mlx_pixel_put(env->mlx_ptr, env->win_ptr, a.x + y * gradient, a.y + y, 0xff00ff);
        y++;//y+=0.1;
    }
}

void draw_line(t_env *env, t_pixel a, t_pixel b)
{
    double x;
    double y;

    int dx;
    int dy;

    double gradient;

    dx = b.x - a.x;
    dy = b.y - a.y;

    gradient = ABS((double)dy / (double)dx);
    if (gradient > 1)
    {
        draw_line_y(env, a, b);
        return ;
    }
    if (dx < 0)
    {
        ft_swap(&a, &b, sizeof(t_pixel));
    }
    y = 0;
    x = 0;
    while (x < ABS(dx))
    {
        mlx_pixel_put(env->mlx_ptr, env->win_ptr, a.x + x, a.y - x * gradient, 0x00ffff);
        x++;
    }
}

/* void draw_line(t_env *env, t_pixel a, t_pixel b)
{
    //double x;
    //double y;
    float i;
    float dx;
    float dy;

    double gradient;

    dx = b.x - a.x;
    dy = b.y - a.y;

    if (fabsf(dx) >= fabsf(dy))
        gradient = fabsf(dx);
    else
        gradient = fabsf(dy);
    dx = dx/gradient;
    dy = dy/gradient;
    //gradient = (double)dy / (double)dx;
    //if (gradient > 1)
           //draw_line_y(env, a, b);
    //y = 0;
    //x = 0;
    i = 1;
    while (i < gradient)
    {
        mlx_pixel_put(env->mlx_ptr, env->win_ptr, a.x, a.y, 0xffffff);
        a.x = a.x + dx;
        a.y = a.y + dy;
        i++;
    }
    mlx_pixel_put(env->mlx_ptr, env->win_ptr, a.x, a.y, 0xffffff);
}*/

int fun(void *data)
{
    t_pixel b;
    t_pixel e;
    b.x = 0;
    b.y = 0;
    e.x = 500;
    e.y = 500;
    draw_box(data, b, e);
    static float rotation = 0;
    rotation += 0.5;
    float c = cos(rotation);
    float s = sin(rotation);
    t_env * env = (t_env *)data;
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
            p.x *= 50;
            p.y *= 50;
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
    /*for (int i = 0; i < (env->sizet - 1) ; i++)
    {
        draw_line(env, result[i], result[i + env->sizex + 1]);
    }*/
    free(result);
    return 0;
}

int exitfun(void *data)
{
    (void)data;
    exit(0);
    return 0;
}