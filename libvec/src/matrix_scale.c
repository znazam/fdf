/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:17:43 by znazam            #+#    #+#             */
/*   Updated: 2019/08/15 14:17:45 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libvec.h"

t_matrix	matrix_scale(t_vector v)
{
	t_matrix m;

	init_to_zero(&m);
	m.m[0][0] = v.x;
	m.m[1][1] = v.y;
	m.m[2][2] = v.z;
	m.m[3][3] = v.w;
	return (m);
}