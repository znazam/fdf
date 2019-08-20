/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znazam <znazam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:25:29 by znazam            #+#    #+#             */
/*   Updated: 2019/08/20 09:12:17 by znazam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error_check(int error)
{
	if (error == 0)
	{
		ft_putendl("file doesn't exist.");
		exit(0);
	}
	if (error == 1)
	{
		ft_putendl("file is empty.");
		exit(0);
	}
	if (error == 2)
	{
		ft_putendl("didn't select one file.");
		exit(0);
	}
}
