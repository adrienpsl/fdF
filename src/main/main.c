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
#include "../../mlx/mlx.h"


//#include "color.c"
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
//			++y1;
//			e += dx;
//		}
//		x2--;
//	}
//}

int get_quick(t_dll_l link)
{
	return ((t_linkTmp) link->content)->quick;
}

int get_nb(t_dll_l link)
{
	return ((t_linkTmp) link->content)->nb;
}


int get_quick_2(t_dll_l link)
{
	return ((t_wrong_link) link->content)->quick;
}



t_fig_2 new_fig(int x1, int y1, int x2, int y2)
{
	t_fig_2 fig2;

	fig2 = ft_malloc_protect(sizeof(t_fig_2_00));
	fig2->x_1 = x1;
	fig2->y_1 = y1;
	fig2->x_2 = x2;
	fig2->y_2 = y2;

	return (fig2);
}


//void print_rec(t_push_rec rec)
//{
//	ft_printf("======================== \n");
//
//	ft_printf("min :   %3d    || max:    %3d \n", rec->min, rec->max);
//	ft_printf("quick : %3d  || nb_quick: %3ld  || %3d \n", rec->quick,
//			  rec->nb_quick,
//			  rec->color);
//
//	ft_printf("======================== \n");
//}


// il me faut figure fixe ici c'est la que ca bug, comme je la rappelle a chaque fois




