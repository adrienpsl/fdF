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

void do_seg(int x1, int y1, int x2, int y2, t_mlx mlx)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int e;


	ft_printf("%d %d \n", dx, dy);
	dy = (y1 - y2) * 2;
	e = dx;
	dx = e * 2;

	while (x1 < x2)
	{
		++x1;
		fill_pixel(mlx, x1, y1, 0xFFFFFF);
		if (e -= dy >= 0)
		{
			++y1;
			e += dx;
		}
		x2--;
	}
}


// get les coordoner de la souris

int get_souris_click(int button, int x, int y, void *param)
{
	static int i = 2;
	static int x1 = 0;
	static int x2 = 0;
	static int y1 = 0;
	static int y2 = 0;
	t_mlx mlx = param;

	(void) button;
	(void) param;
	(void) x;
	(void) y;
	//
	//	if (i == 0)
	//	{
	//		x1 = x;
	//		y1 = y;
	//		++i;
	//	}
	//
	//	else if (i == 1)
	//	{
	//		x2 = x;
	//		y2 = y;
	//		++i;
	//	}

	if (i == 2)
	{
		//		do_seg(x1, y1, x2, y2, param);
		do_seg(150, 300, 500, 150, param);
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
		i = 0;
	}
	ft_printf("%d %d %d %d %d \n", i, x1, y1, x2, y2);

	return (TRUE);
}

int main()
{
	t_mlx mlx;

	mlx = new_mlx(1000, 1000, "lala");

	do_seg(150, 150, 500, 300, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);

	mlx_mouse_hook(mlx->window, get_souris_click, mlx);

	mlx_loop(mlx->mlx);
	return 0;
}