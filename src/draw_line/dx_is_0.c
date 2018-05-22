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

void dy_p_dx_0(t_fdf fdf)
{
	t_line l;

	l = &fdf->line;
	while (l->y_1 != l->y_2)
	{
		fill_pixel(fdf->mlx, l->x_1, l->y_1, 0xFFFFFF);
		++l->y_1;
	}
}

void dx_0_dy_n(t_fdf fdf)
{
	t_line l;

	l = &fdf->line;
	while (l->y_1 != l->y_2)
	{
		fill_pixel(fdf->mlx, l->x_1, l->y_1, 0xFFFFFF);
		--l->y_1;
	}
}