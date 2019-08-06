/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 08:54:21 by znazam            #+#    #+#             */
/*   Updated: 2019/08/05 16:02:10 by znazam           ###   ########.fr       */
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
# include <fcntl.h>

# define ABS(X) (X < 0 ? -X : X)
# define PIXEL mlx_pixel_put (mlx, win, right, down, 0x0ffffff)
# define DR(N) (change < 0 ? (-N) : N)

# define SCREEN_W 1000
# define SCREEN_H 1000

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

typedef struct s_info
{
    int        x_size;
    int        total_size;
    int        y_size;
    int        fd;
    char    *line;
    char    **inf;
}                t_info;

typedef struct	s_mlx_image
{
	void		*img_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	char		*raw_data;
	int			width;
	int			height;
	t_pixel		pos;
}				t_mlx_image;
typedef struct	s_env
{
	t_mlx_image	img;
	void		*mlx_ptr;
	void		*win_ptr;
	t_coord		*map;
	int			sizex;
	int			sizey;
	int			sizet;
	t_coord		*coord;

}				t_env;


void	put_image(t_env *env, t_mlx_image *img);
void	init_image(t_env *env, t_mlx_image *img, int width, int height);
void	clear_image(t_mlx_image *img, int colour);
void	pixel_put_image(t_mlx_image *img, int colour, int x, int y);
void	line_delete(void *content, size_t size);
void	draw_line_y(t_env *env, t_pixel a, t_pixel b);
void	draw_line(t_env *env, t_pixel a, t_pixel b);
int		grid(t_env *env, const char *filename);
int		fun(void *data);
int		exitfun(void *data);
int		exitb(int button);
void	interpreter(const char *path, t_env *env);
#endif
