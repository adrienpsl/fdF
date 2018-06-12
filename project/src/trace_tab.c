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

void set_d_line(t_pixel pxl_1, t_pixel pxl_2, t_fdf fdf)
{
	t_line line;

	line = &fdf->line;
	line->x_1 = pxl_1->x * dist;
	line->y_1 = pxl_1->y * dist;
	line->x_2 = pxl_2->x * dist;
	line->y_2 = pxl_2->y * dist;
}

// si le prochain match trace un trait
int trace_horizon(t_fdf fdf)
{
	set_d_line(fdf->pixel_tab + fdf->all_pxl, fdf->pixel_tab + fdf->all_pxl + 1,
			   fdf);
	//	ft_printf("%d \n", trace.);
	trace_line(fdf);

	return (TRUE);
}

int trace_vertical(t_fdf fdf)
{
	set_d_line(fdf->pixel_tab, fdf->pixel_tab + fdf->nb_line,
			   fdf);
	trace_line(fdf);
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
//		if (trace.col < fdf->nb_col)
//			trace_horizon(fdf);
		// je regarde si bottom
		if (trace.line < fdf->nb_line)
			trace_vertical(fdf);
		++trace.col;
		mlx_put_image_to_window(fdf->mlx->mlx, fdf->mlx->window, fdf->mlx->img, 50,
		 							50);
		mlx_loop(fdf->mlx->mlx);

		if (trace.col == fdf->nb_col)
		{
			++trace.line;
			trace.col = 0;
		}
		fdf->all_pxl++;
	}
//	mlx_put_image_to_window(fdf->mlx->mlx, fdf->mlx->window, fdf->mlx->img, 50,
//							50);
	return (1);
}