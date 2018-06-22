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

void init_window(int x, int y, char *name, t_mlx mlx)
{
	t_window window;

	window = &mlx->window;
	window->ptr = mlx_new_window(mlx->ptr, x, y, name);
	raise_errno(window->ptr);
	window->nb_pixel_x = x;
	window->nb_pixel_y = y;
}

void init_img(int x, int y, t_mlx mlx)
{
	int a;
	int b;
	int c;
	t_img img;

	img = &mlx->img;
	img->ptr = mlx_new_image(mlx->ptr, x, y);
	raise_errno(img->ptr);
	img->str = mlx_get_data_addr(img->ptr, &a, &b, &c);
	raise_errno(img->str);
	mlx->img.size_ligne = x;
}

void clear_img(t_mlx mlx)
{
	ft_memset(&mlx->img.str, 0, mlx->window.nb_pixel_x *
								mlx->window.nb_pixel_y);
}

t_mlx new_mlx(int x, int y, char *name)
{
	t_mlx mlx;

	mlx = ft_malloc_protect(sizeof(t_mlx_00));
	mlx->ptr = mlx_init();
	raise_errno(mlx->ptr);
	init_window(x, y, name, mlx);
	init_img(x, y, mlx);

	return (mlx);
}
