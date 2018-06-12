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


# include "../../includes/fdf_header.h"

void		fill_pixel(t_mlx mlx, long x, long y, int color)
{
	char *img;

	img = mlx->str_img;
	y = (x * 4) + (4 * y * 1000);
	img[y] = color & 0xff;
	img[y + 1] = color >> 8 & 0xff;
	img[y + 2] = color >> 16;
}

int		new_color(void)
{
	int a;

	a = rand() % 255;
	a = a << 8;
	a += rand() % 255;
	a = a << 8;
	a += rand() % 255;
	return (a);
}