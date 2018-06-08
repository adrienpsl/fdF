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

#include "../includes/fdf_header.h"

// bcq moins chiant de le faire en faisaint poiter les trucs.

//double get_coord_pxl(t_pixel pixel, int xyz)
//{
//	return (*(pixel + (sizeof(double) * xyz)));
//}

#define dist 50;

void set_d_line(t_pixel pxl_1, t_pixel pxl_2, t_trace trace)
{
	t_line line;

	line = &trace->draw_l;
	line->x_1 = pxl_1->x * dist;
	line->y_1 = pxl_1->y * dist;
	line->x_1 = pxl_2->x * dist;
	line->y_1 = pxl_2->y * dist;
}

// si le prochain match trace un trait
int trace_horizon(t_fdf fdf, t_trace trace)
{
	set_d_line(fdf->pixel_tab + fdf->all_pxl, fdf->pixel_tab + fdf->all_pxl + 1,
			   trace);

	return (TRUE);
}

int trace_vertical(t_fdf fdf, t_trace trace)
{
	set_d_line(fdf->pixel_tab, fdf->pixel_tab + fdf->nb_line,
			   trace);
	return (TRUE);
}

/*
 * boucle une premier fois sur le tab et s'incrente a chaque fois
 *  utiliser la precedente structure? rester avec des static pour la phase de dev
 *  va set send
 * */

int trace_tab(t_fdf fdf)
{
	t_trace_00 trace;

	ft_memset(&trace, 0, sizeof(t_trace_00));
	while (trace.line < fdf->nb_line)
	{
		// je regarde si right
		if (trace.col < fdf->nb_col)
			trace_vertical(fdf, &trace);
		// je regarde si bottom
		if (trace.linee < fdf->nb_line);

		++trace.col;
		if (trace.col == fdf->nb_col)
		{
			++trace.line;
			trace.col = 0;
		}
	}
	return (1);
}