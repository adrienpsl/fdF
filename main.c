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

#include "includes/fdf_header.h"





// get les coordoner de la souris

int get_souris_click(int button, int x, int y, void *param)
{
	static int i = 0;
	t_fdf fdf = param;
	t_mlx mlx = fdf->mlx;
	t_line line = &fdf->line;

	(void) button;
	if (i == 0)
	{
		set_line_1(x, y, line);
		++i;
	}

	else if (i == 1)
	{
		set_line_2(x, y, line);
		++i;
	}

	if (i == 2)
	{
		trace_line(fdf);
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
		i = 0;
	}
	//	ft_printf("%d \n", button);

	return (TRUE);
}

int main()
{
	t_mlx mlx;
	t_fdf_00 fdf;

	mlx = new_mlx(1000, 1000, "lala");
	fdf.mlx = mlx;

	mlx_mouse_hook(mlx->window, get_souris_click, &fdf);

	mlx_loop(mlx->mlx);
	return 0;
}