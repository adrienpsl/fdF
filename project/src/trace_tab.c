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


// compare entre la place de ma function ?
int get_coord_pxl(t_pixel pixel, int coo)
{
	return (*(pixel + (sizeof(double) * )
}

int     trace_col_fdf(int x, int y, t_fdf fdf)
{
    t_dll pixel_pile;

	pixel_pile = fdf->pixel_pile;
	return (TRUE);
}

int     trace_line_fdf(int x, int y, t_fdf fdf)
{

	return (TRUE);
}

/*
 * boucle une premier fois sur le tab et s'incrente a chaque fois
 *  utiliser la precedente structure? rester avec des static pour la phase de dev
 *  va set send
 * */

int trace_tab(t_fdf fdf)
{
	static int col = 0;
	static int line = 0;
	static int where = 0;
	
	while (line < fdf->nb_line)
	{
		if (col < fdf->nb_col);
			trace_col_fdf(col, line, fdf);
		if (col < fdf->nb_line);
			// trace
		++col;
		if (col == fdf->nb_col)
		{
			++line;
			col = 0;
		}
	}
	return (1);
}