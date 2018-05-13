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

void horizon_left_right(t_fig_2 fig2, t_mlx_data mlx_data)
{
	int x;

	x = fig2->x_1;
	while (x < fig2->x_2)
	{
		mlx_pixel_put(mlx_data->mlx, mlx_data->window, x, fig2->y_1,
					  fig2->color);
		x += 1;
	}
}

//void static
//the_leg_draw(t_mlx_data mlx_data, t_fig_2 fig2, int middle, char *tab)
//{
//
//}

void the_legende(t_mlx_data mlx_data, t_rec_link rec, t_fig_2 fig2)
{
	(void) rec;
	char tab[25];
	int middle;

	middle = ((fig2->y_2 - fig2->y_1) / 2) + fig2->y_1 - 10;

	ft_putnbr_str(rec->quick, tab);
	mlx_string_put(mlx_data->mlx, mlx_data->window,
				   fig2->x_2 + 10,
				   middle - 20,
				   fig2->color, tab);


	ft_putnbr_str(rec->min, tab);
	mlx_string_put(mlx_data->mlx, mlx_data->window,
				   fig2->x_2 + 10,
				   middle,
				   fig2->color, tab);

	ft_putnbr_str(rec->max, tab);
	mlx_string_put(mlx_data->mlx, mlx_data->window,
				   fig2->x_2 + 10,
				   middle + 20,
				   fig2->color, tab);
}

void trace_legend_rec(t_fig_2 fig2, t_mlx_data visu, t_rec_link rec)
{
	the_legende(visu, rec, fig2);
	recangle(fig2, visu);
}

void recangle(t_fig_2 fig2, t_mlx_data mlx_data)
{
	while (fig2->y_1 < fig2->y_2)
	{
		horizon_left_right(fig2, mlx_data);
		fig2->y_1++;
	}
}