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

#include "../../includes/all_includes.h"

void		horizon_left_right2(t_fig_2 fig2, t_mlx_data mlx_data)
{
	int y;

	y = fig2->y_1;
	while (y < fig2->y_2)
	{
		fill_pixel(mlx_data->str_img, fig2->x_1, y, fig2->color);
		y += 1;
	}
}

void		recangle(t_fig_2 fig2, t_mlx_data mlx_data)
{
	while (fig2->x_1 < fig2->x_2)
	{
		horizon_left_right2(fig2, mlx_data);
		fig2->x_1++;
	}
}

void		fill_pixel(char *img, long x, long y, int color)
{
	y = (x * 4) + (4 * y * Y_WINDOW);
	img[y] = color & 0xff;
	img[y + 1] = color >> 8 & 0xff;
	img[y + 2] = color >> 16;
}

void		the_legende(t_mlx_data mlx_data, t_rec_link rec, t_fig_2 fig2)
{
	char	tab[25];
	int		middle;

	middle = ((fig2->x_2 - fig2->x_1) / 2) + fig2->x_1 - 10;
	ft_putnbr_str(rec->quick, tab);
	mlx_string_put(mlx_data->mlx, mlx_data->window, middle, fig2->y_2 + 10,
					fig2->color, tab);
	ft_putnbr_str(rec->max - rec->min, tab);
	mlx_string_put(mlx_data->mlx, mlx_data->window, middle, fig2->y_2 + 30,
					fig2->color, tab);
	ft_putnbr_str(rec->min, tab);
	ft_strcat(tab, "-");
	mlx_string_put(mlx_data->mlx, mlx_data->window, middle, fig2->y_2 + 60,
				fig2->color, tab);
	ft_putnbr_str(rec->max, tab);
	mlx_string_put(mlx_data->mlx, mlx_data->window, middle, fig2->y_2 + 80,
					fig2->color, tab);
}
