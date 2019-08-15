/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:17:29 by znazam            #+#    #+#             */
/*   Updated: 2019/08/15 14:17:31 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libvec.h"

t_matrix	matrix_projection(double fov, double a_r, double near, double far)
{
	t_matrix	m;
	double		fov_rad;

	init_to_zero(&m);
	fov_rad = 1 / tan(fov * 0.5 / 180 * M_PI);
	m.m[0][0] = near / (a_r * fov_rad);
	m.m[1][1] = near / fov_rad;
	m.m[2][2] = -(far + near) / (far - near);
	m.m[3][2] = (-2 * far * near) / (far - near);
	m.m[2][3] = -1;
	return (m);
}
