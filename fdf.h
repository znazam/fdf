/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 08:54:21 by znazam            #+#    #+#             */
/*   Updated: 2019/07/19 13:43:59 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "GNL/get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define ABS(X) (X < 0 ? -X : X)
# define PIXEL mlx_pixel_put (mlx, win, right, down, 0x0ffffff)

# define SCREEN_W 500
# define SCREEN_H 500

typedef struct	s_pixel
{
	int x;
	int y;
}				t_pixel;

typedef struct s_coord
{
	float x;
	float y;
	float z;
}				t_coord;

typedef struct	s_env
{
	void *mlx_ptr;
	void *win_ptr;
	t_coord *map;
	int sizex;
	int sizey;
	int sizet;

}				t_env;

int		grid(t_env *env, const char *filename);
int		fun(void *data);
int		exitfun(void *data);
int		exitb(int button);
#endif
