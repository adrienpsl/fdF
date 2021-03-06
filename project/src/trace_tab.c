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
//{œ
//	return (*(pixel + (sizeof(double) * xyz)));
//}

#define dist 100

int     set(int a)
{
	return (a * dist) + 500;
}


void set_d_line(t_pixel pxl_1, t_pixel pxl_2, t_fdf fdf)
{
	t_line line;
	static int  a = 0;
	static int b = dist;
	a++;

	if (a == 8)
	{
		b += dist;
		ft_printf("%d  %d\n", b, a);
		a = 0;
	}
	line = &fdf->line;
	line->x_1 = set(pxl_1->x);
	line->y_1 = set(pxl_1->y);
	line->x_2 = set(pxl_2->x);
	line->y_2 = set(pxl_2->y);
	printf("--%d %d %d %d-- \n", line->x_1, line->y_1, line->x_2,line->y_2 );
}

// si le prochain match trace un trait
int trace_horizon(t_fdf fdf)
{
	t_data data;

	data = &fdf->data;
	set_d_line(data->pixel_tab + data->pxl_where,
			   data->pixel_tab + data->pxl_where + 1,
			   fdf);
	trace_line(fdf);

	return (TRUE);
}

int trace_vertical(t_fdf fdf)
{
	t_data data;

	data = &fdf->data;
	set_d_line(data->pixel_tab + data->pxl_where,
			   data->pixel_tab +  data->pxl_where + data->nb_line,
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
	int line = 0;
	int col = 0;
	t_data data;

	data = &fdf->data;
	while (line < data->nb_line)
	{
		// je regarde si right
		if (col < data->nb_col - 1)
			trace_horizon(fdf);
		// je regarde si bottom
		if (line < data->nb_line - 1)
			trace_vertical(fdf);
		++col;
		if (col == data->nb_col)
		{
			++line;
			col = 0;
		}
		data->pxl_where++;
	}
	data->pxl_where = 0;
	return (1);
}