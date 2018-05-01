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

//void do_seg(int x1, int y1, int x2, int y2, t *param)
//{
//	int dx;
//	int dy;
//	int e;
//
//	e = x2 - x1;
//	dx = e * 2;
//	dy = (y2 - y1) * 2;
//
//	while (x1 < x2)
//	{
//		++x1;
//		printf("%d %d\n", x1, y1);
//		mlx_pixel_put(param->M, (param)->widow, x1, y1, 0xFFFFFF);
//		if (e - dy >= 0)
//		{
//			printf("%d \n", dx);
//			++y1;
//			e += dx;
//		}
//		x2--;
//	}
//}

//int main()
//{
//	t_under under;
//	t_pos pos;
//
//	under = malloc(sizeof(t_underr));
//	pos = &under->pos;
//
//	under->mlx = mlx_init();
//	under->widow = mlx_new_window(under->mlx, 300, 300, "test");
//
////	d_set_pos(50, 50, 200, 50, pos);
////	horizon_left_right(under);
//
//
//	//	mlx_key_hook(window, deal_key, &l);
//	//	mlx_mouse_hook(window, deal_mouse, &l);
//	//
//	mlx_loop(under->mlx);
//	return 0;
//}