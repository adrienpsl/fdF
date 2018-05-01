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

//void horizon_left_right(t_fig_2 under)
//{
//	t_pos pos;
//
//	pos = &under->pos;
//	while (pos->x_1 < pos->x_2)
//	{
//		print_pxl(under);
//		pos->x_1 += 1;
//	}
//}

//void horizon_right_left(t_under under)
//{
//	t_pos pos;
//
//	pos = &under->pos;
//	while (pos->x_1 != pos->x_2)
//	{
//		print_pxl(under);
//		pos->x_1 -= 1;
//	}
//}
//
//void verticaly_up_end(t_under under)
//{
//	t_pos pos;
//
//	pos = &under->pos;
//	while (pos->y_1 != pos->y_2)
//	{
//		print_pxl(under);
//		pos->y_1 += 1;
//	}
//}
//
//
//void verticaly_end_up(t_under under)
//{
//	t_pos pos;
//
//	pos = &under->pos;
//	while (pos->y_1 != pos->y_2)
//	{
//		print_pxl(under);
//		pos->y_1 -= 1;
//	}
//}
//
//void test_(t_under under)
//{
//	t_pos pos;
//
//	pos = &under->pos;
//	print_pos(pos);
//
//	pos->err = pos->dx;
//	pos->dx = pos->err * 2;
//	pos->dy = (pos->y_2 - pos->y_1) * 2;
//
//	print_pos(pos);
//
//	while (pos->x_1 >= pos->x_2)
//	{
//	    pos->x_1--;
////	    ft_printf("%d \n", pos->err);
//		print_pxl(under);
//		pos->err -= pos->dy;
//		if (pos->err >= 0)
//		{
//			pos->y_1--;
//			pos->err += pos->dx;
//		}
//	}
//}
//
//void test_2(t_under under)
//{
//	t_pos pos;
//
//	pos = &under->pos;
//
//	while (pos->x_1 != pos->x_2)
//	{
//		print_pxl(under);
//		pos->x_1--;
//
//		ft_printf("%d %d %d\n", pos->x_1, pos->y_1, pos->err);
//		// ft_printf("dx : %d || dy:  %d || %d\n", pos->dx, pos->dy, pos->err);
//
//		pos->err -= pos->dy;
//		if (pos->err < 0)
//		{
//			pos->y_1++;
//			pos->err += -pos->dx;
//		}
//	}
//}