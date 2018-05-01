/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_header.h"


void horizon_left_right(t_fig_2 fig2, t_visu visu)
{
	int x;

	x = fig2->x_1;
	while (x < fig2->x_2)
	{
		mlx_pixel_put(visu->mlx, visu->window.ptr, x, fig2->y_1,
					  fig2->color);
		x += 1;
	}
}

void    recangle(t_fig_2 fig2, t_visu visu)
{
	fig2->y_2 += fig2->y_1;
	while (fig2->y_1 < fig2->y_2)
	{
		horizon_left_right(fig2, visu);
		fig2->y_1++;
	}
}