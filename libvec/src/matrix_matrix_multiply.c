/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_matrix_multiply.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:17:20 by znazam            #+#    #+#             */
/*   Updated: 2019/08/15 14:17:22 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libvec.h"

t_matrix	matrix_matrix_multiply(t_matrix m1, t_matrix m2)
{
	t_matrix	m;
	int			r;
	int			c;

	init_to_zero(&m);
	c = 0;
	while (c < 4)
	{
		r = 0;
		while (r < 4)
		{
			m.m[r][c] = m1.m[r][0] * m2.m[0][c] + m1.m[r][1] * m2.m[1][c] +
			m1.m[r][2] * m2.m[2][c] + m1.m[r][3] * m2.m[3][c];
			r++;
		}
		c++;
	}
	return (m);
}
