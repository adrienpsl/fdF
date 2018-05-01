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

t_dll_l new_color_link(int quick, long color)
{
	t_dll_l visu_link;
	t_color color_link;

	visu_link = new_dll_l(&color_link, sizeof(t_color_));
	color_link->quick = quick;
	color_link->color = color;
	return (visu_link);
}

t_dll_l new_visu_link()
{
	t_dll_l visu_link;
	t_push_rec rec;

	visu_link = new_dll_l(&rec, sizeof(t_push_rec_));
	ft_memset(visu_link->content, 0, sizeof(t_push_rec_));
	rec->max = INT_MIN;
	rec->min = INT_MAX;
	return (visu_link);
}

int color_find(t_dll_l color_link, void *quick)
{
	return (((t_color) color_link->content)->quick == *(int *) quick);
}

void get_all_visu(t_dll_c pile, t_pile_visu p_visu)
{
	int curr_quick;
	t_dll_l link;
	t_dll_l visu_link;
	t_push_rec rec;
	t_dll_l color_link;

	visu_link = new_visu_link();
	rec = visu_link->content;

	link = pile->top->next;
	curr_quick = get_quick(pile->top);

	while (curr_quick == get_quick(link))
	{
		rec->nb_quick++;
		if (get_nb(link) > rec->max)
			rec->max = get_nb(link);
		if (get_nb(link) < rec->min)
			rec->min = get_nb(link);
	}
	color_link = dll_find(p_visu->list_color, color_find, &curr_quick);
	// get color
}

t_pile_visu new_pile_visu(int x)
{
	// elle doit savoir ou sont ses quick;
	t_pile_visu pile_visu;

	pile_visu = ft_malloc_protect(sizeof(t_pile_visu_));
	ft_memset(pile_visu, 0, sizeof(*pile_visu));
	pile_visu->x1 = x;
	pile_visu->x2 = x + 100;

	return (pile_visu);
}

t_fig_2 new_fig(int x1, int y1, int x2, int y2)
{
	t_fig_2 fig2;

	fig2 = ft_malloc_protect(sizeof(t_fig_2_));
	fig2->x_1 = x1;
	fig2->y_1 = y1;
	fig2->x_2 = x2;
	fig2->y_2 = y2;

	return (fig2);
}

int loop_hook(void *param)
{
	t_test test;

	test = param;
	recangle(test->fig2, test->visu);
	return (TRUE);
}

t_visu new_visu(int x, int y, char *name)
{
	t_visu visu;
	t_window window;

	visu = ft_malloc_protect(sizeof(t_visu_));
	window = &visu->window;

	visu->mlx = visu->mlx = mlx_init();
	window->x = x - 50;
	window->y = y - 50;
	visu->window.ptr = mlx_new_window(visu->mlx, x, y, name);

	return (visu);
}

int deal_key(int key, void *param)
{
	printf("%d \n", key);
	return (1);
}

int main()
{
	t_visu visu;
	t_fig_2 fig2;
	t_test_ test;

	visu = new_visu(300, 3300, "push_push");
	fig2 = new_fig(30, 30, 130, 130);
	fig2->color = 0xFFFFFF;
	test.fig2 = fig2;
	test.visu = visu;

	mlx_key_hook(visu->window.ptr, deal_key, &test);
	mlx_loop(visu->mlx);

	//	mlx_pixel_put(visu->mlx, visu->window.ptr, 30, 30,
	//				  0xFFFFFF);


	//		mlx_loop_hook(visu->mlx, loop_hook, &test);

	//	void *mlx = mlx_init();
	//	void *window = mlx_new_window(mlx, 300, 300, "test");
	//	mlx_key_hook(window, deal_key, &test);
	//	mlx_loop(mlx);

	//
	//	under = &visu->under;
	//	pos = &under->pos;
	//
	//
	//
	//	under->widow = mlx_new_window(under->mlx, 1300, 1300, "test");
	//
	//	d_set_pos(30, 30, 130, 130, pos);
	//	under->color = 0xFFFFFF;
	////	recangle(under);
	//
	//
	//	//	mlx_mouse_hook(window, deal_mouse, &l);
	//	//
	////	mlx_string_put(under->mlx, under->widow, 50,50,0xFFFFFF,"bobo");
	//
	//	mlx_loop(under->mlx);
	//	return 0;
}