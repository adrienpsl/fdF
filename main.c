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
#include "mlx/mlx.h"

//int deal_key(int key, void *param)
//{
//
//	mlx_pixel_put(((t *) param)->M, ((t *) param)->widow, 250, 250, 0xFFFFFF);
//	printf("%d \n", key);
//	return (1);
//}
//
//int deal_mouse(int button, int x, int y, void *param)
//{
//
//	mlx_pixel_put(((t *) param)->M, ((t *) param)->widow, 250, 250, 0xFFFFFF);
//	printf("%d %d %d\n", button, x, y);
//	return (1);
//}

void dx_p_dy_p(t_fdf fdf)
{
	t_line l;

	l = &fdf->line;
	l->e = l->dx;
	l->dx = l->dx << 2;
	l->dy = l->dy << 2;

	while (++l->x_1 < l->x_2)
	{
		ft_printf("%d \n", l->e);
		fill_pixel(fdf->mlx, l->x_1, l->y_1, 0xFFFFFF);
		if ((l->e -= l->dy) < 0)
		{
			++l->y_1;
			l->e += l->dx;
		}
	}
}

void dy_p_dx_p(t_fdf fdf)
{
	t_line l;

	l = &fdf->line;
	l->e = l->dy;
	l->dy = l->dy << 2;
	l->dx = l->dx << 2;

	while (++l->y_1 < l->y_2)
	{
		ft_printf("%d \n", l->e);
		fill_pixel(fdf->mlx, l->x_1, l->y_1, 0xFFFFFF);
		if ((l->e -= l->dx) < 0)
		{
			++l->x_1;
			l->e += l->dy;
		}
	}
}

void trace_line(t_fdf fdf)
{
	t_line line;

	line = &fdf->line;
	if (line->dx >= line->dy)
		dx_p_dy_p(fdf);
	else
		dy_p_dx_p(fdf);
}


// get les coordoner de la souris

int get_souris_click(int button, int x, int y, void *param)
{
	static int i = 0;
	t_fdf fdf = param;
	t_mlx mlx = fdf->mlx;
	t_line line = &fdf->line;

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
	ft_printf("%d \n", button);

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