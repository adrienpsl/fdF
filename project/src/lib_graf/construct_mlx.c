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

t_mlx new_mlx(int x, int y, char *name)
{
	int a;
	int b;
	int c;
	t_mlx mlx;

	mlx = ft_malloc_protect(sizeof(t_mlx_00));
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		errno_exit();
	mlx->x = x - 25;
	mlx->y = y - 25;
	mlx->window = mlx_new_window(mlx->mlx, x, y, name);
	if (mlx->window == NULL)
		errno_exit();
	mlx->img = mlx_new_image(mlx->mlx, x - 25, y - 25);
	if (mlx->img == NULL)
		errno_exit();
	mlx->str_img = mlx_get_data_addr(mlx->img, &a, &b, &c);
	return (mlx);
}
