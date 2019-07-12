/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 08:54:21 by znazam            #+#    #+#             */
/*   Updated: 2019/07/12 07:37:12 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "libft/libft.h"
# include "GNL/get_next_line.c"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

# define ABS(X) (X < 0 ? -X : X)
# define PIXEL mlx_pixel_put (mlx, win, right, down, 0x0ffffff)
typedef struct	s_pixel
{
	int x;
	int y;
}				t_pixel;

typedef struct	s_env
{
	void *mlx_ptr;
	void *win_ptr;
	float map[3][3];
}				t_env;

typedef struct size
{
	float x;
	float y;
	float z;
}				size;
#endif
