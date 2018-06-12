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

# include "../../../includes/fdf_header.h"

void dx_sup_0(t_fdf fdf)
{
	t_line line;

	line = &fdf->line;
	if (line->dy != 0)
	{
		if (line->dy > 0)
		{
			if (line->dx >= line->dy)
				dx_p_dy_p(fdf);
			else
				dy_p_dx_p(fdf);
		}
		else
		{
			if (line->dx >= -(line->dy))
				dx_p_dy_n(fdf);
			else
				dy_n_dx_p(fdf);
		}
	}
	else
		dx_p_dy_0(fdf);
}

void     dx_low_0(t_fdf fdf)
{
	t_line line;

	line = &fdf->line;
	if (line->dy != 0)
	{
		if (line->dy > 0)
		{
			if (-(line->dx) >= line->dy)
				dx_n_dy_p(fdf);
			else
				dy_p_dx_n(fdf);
		}
		else if (line->dy < 0)
		{
			if (line->dy >= line->dx)
				dy_n_dx_n(fdf);
			else
				dx_n_dy_n(fdf);
		}
	}
	else
		dy_0_dx_n(fdf);
}

void trace_line(t_fdf fdf)
{
	t_line line;


	// set dx
	line = &fdf->line;
	line->dx = line->x_2 - line->x_1;
	line->dy = line->y_2 - line->y_1;
	if (line->dx > 0)
	{
		dx_sup_0(fdf);
	}
	else if (line->dx < 0)
	{
		dx_low_0(fdf);
	}
	else
	{
		if (line->dy > 0)
			dy_p_dx_0(fdf);
		else
			dx_0_dy_n(fdf);
	}
}