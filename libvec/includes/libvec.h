/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:15:29 by znazam            #+#    #+#             */
/*   Updated: 2019/08/15 14:24:52 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H
# define FILL_VECTOR(V, X, Y, Z, W) V.x = X, V.y = Y, V.z = Z, V.w = W
# include <math.h>
# include "../../libft/libft.h"

typedef struct	s_vector
{
	double x;
	double y;
	double z;
	double w;
}				t_vector;

typedef struct	s_matrix
{
	double m[4][4];
}				t_matrix;

t_vector		vector_add(t_vector v1, t_vector v2);
t_vector		vector_subtract(t_vector v1, t_vector v2);
t_vector		vector_multiply(t_vector v, double k);
t_vector		vector_divide(t_vector v, double k);
double			vector_dot_product(t_vector v1, t_vector v2);
double			vector_length(t_vector v);
t_vector		vector_normalise(t_vector v);
t_vector		vector_cross_product(t_vector v1, t_vector v2);

t_vector		matrix_vector_multiply(t_vector vector, t_matrix m);
t_matrix		matrix_make_identity();
t_matrix		matrix_rotate_x(double theta);
t_matrix		matrix_rotate_y(double theta);
t_matrix		matrix_rotate_z(double theta);
t_matrix		matrix_translate(t_vector v);
t_matrix		matrix_projection(double fov, double a_r,
				double near, double far);
t_matrix		matrix_matrix_multiply(t_matrix m1, t_matrix m2);
t_matrix		matrix_rotate(t_vector v);
t_matrix		matrix_scale(t_vector v);
void			init_to_zero(t_matrix *m);
#endif
