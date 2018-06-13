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

#include "../../../includes/fdf_header.h"

void dx_n_dy_p(t_fdf fdf)
{
	t_line l;

	l = &fdf->line;
	l->e = l->dx;
	l->dy = l->dy << 2;
	l->dx = l->dx << 2;

	while (l->x_1 != l->x_2)
	{
		fill_pixel(fdf->mlx, l->x_1, l->y_1, 0xFFFFFF);
		if ((l->e += l->dy) >= 0)
		{
			++l->y_1;
			l->e += l->dx;
		}
		l->x_1--;
	}
	ft_printf(" \n");
}

void dy_p_dx_n(t_fdf fdf)
{
	t_line l;

	l = &fdf->line;
	l->e = l->dy;
	l->dy = l->dy << 2;
	l->dx = l->dx << 2;

	while (l->y_1 != l->y_2)
	{
		fill_pixel(fdf->mlx, l->x_1, l->y_1, 0xFFFFFF);
		if ((l->e += l->dx) <= 0)
		{
			--l->x_1;
			l->e += l->dy;
		}
		l->y_1++;
	}
}

void dy_n_dx_n(t_fdf fdf)
{
	t_line l;

	l = &fdf->line;
	l->e = l->dx;
	l->dy = l->dy << 2;
	l->dx = l->dx << 2;

	while (l->x_1 != l->x_2)
	{
		fill_pixel(fdf->mlx, l->x_1, l->y_1, 0xFFFFFF);
		if ((l->e -= l->dy) >= 0)
		{
			--l->y_1;
			l->e += l->dx;
		}
		l->x_1--;
	}
}

void dy_0_dx_n(t_fdf fdf)
{
	t_line l;

	l = &fdf->line;
	while (l->x_1 != l->x_2)
	{
		fill_pixel(fdf->mlx, l->x_1, l->y_1, 0xFFFFFF);
		--l->x_1;
	}
}

void dx_n_dy_n(t_fdf fdf)
{
	t_line l;

	l = &fdf->line;
	l->e = l->dy;
	l->dy = l->dy << 2;
	l->dx = l->dx << 2;

	while (l->y_1 != l->y_2)
	{
		fill_pixel(fdf->mlx, l->x_1, l->y_1, 0xFFFFFF);
		if ((l->e -= l->dx) >= 0)
		{
			--l->x_1;
			l->e += l->dy;
		}
		--l->y_1;
	}
}
