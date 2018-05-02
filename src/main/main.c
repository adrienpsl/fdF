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

t_dll_l new_rec_link()
{
	t_dll_l visu_link;
	t_push_rec_ rec;
	t_push_rec rec_link;

	visu_link = new_dll_l(&rec, sizeof(t_push_rec_));
	ft_memset(visu_link->content, 0, sizeof(t_push_rec_));
	rec_link = visu_link->content;
	rec_link->max = INT_MIN;
	rec_link->min = INT_MAX;
	return (visu_link);
}

void set_rec(t_push_rec rec, t_dll_l link)
{
	rec->nb_quick++;
	if (get_nb(link) > rec->max)
		rec->max = get_nb(link);
	if (get_nb(link) < rec->min)
		rec->min = get_nb(link);
}

int get_quick_2(t_dll_l link)
{
	return ((t_wrong_link) link->content)->quick;
}

t_dll_l tt__1(t_dll_c pile, int *quick)
{
	t_dll_l rec_link;
	t_push_rec rec;

	rec_link = new_rec_link();
	rec = rec_link->content;
	*quick = get_quick_2(pile->top);
	if (pile->length != 0)
		while (pile->length && get_quick_2(pile->top) == *quick)
		{
			set_rec(rec, pile->top);
			pile->top = pile->top->next;
			pile->length--;
		}
	else
	{
		destroy_dll_l(&rec_link);
		return (NULL);
	}
	return (rec_link);
}

t_dll t__1(t_dll_c pile, t_dll color_pile)
{
	t_dll_l rec_link;
	t_dll_c pile_copy;
	t_dll rec_pile;
	int quick;

	pile_copy = new_dll_c();
	rec_pile = new_dll();
	pile_copy->top = pile->top;
	pile_copy->length = pile->length;

	while ((rec_link = tt__1(pile_copy, &quick)) != FALSE)
	{
		set_color(rec_link,
				  is_color(color_pile, quick));
		dll_push(rec_link, rec_pile);
	}
	free(pile_copy);
	return (rec_pile);
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

//int deal_key(int key, void *param)
//{
//	printf("%d \n", key);
//	return (1);
//}

void set_(int a, int b, t_dll_c pile)
{
	t_dll_l link_create;
	t_wrong_link_00 op;

	op.nb = a;
	op.quick = b;
	link_create = new_dll_l(&op, sizeof(t_wrong_link_00));
	dll_c_add_after(link_create, pile);
}

void print_rec(t_push_rec rec)
{
	ft_printf("======================== \n");

	ft_printf("min :   %3d    || max:    %3d \n", rec->min, rec->max);
	ft_printf("quick : %3d  || nb_quick: %3ld  || %3d \n", rec->quick,
			  rec->nb_quick,
			  rec->color);

	ft_printf("======================== \n");
}


// il me faut figure fixe ici c'est la que ca bug, comme je la rappelle a chaque fois
// dans ma liste chainer ca fait le bordel/

void print_list(t_pile_visu visu, t_test test, t_dll_c pile)
{
	t_dll_l visu_link;
	t_fig_2 fig2;
	t_push_rec rec;
	float temp;

	visu_link = visu->list_rec->top;

	rec = visu_link->content;
	fig2 = &rec->fig2;

	fig2->color = rec->color;

	ft_printf("------------ %d \n", fig2->color);
	fig2->x_1 = visu->x1;
	fig2->x_2 = visu->x2;

	fig2->y_1 = 30;
	temp = ((float)rec->nb_quick / (float)pile->length);
	fig2->y_2 = (temp * 600) + 30;
	fig2->y_1 = fig2->y_2;

	recangle(fig2, test->visu);

	visu_link = visu->list_rec->top->next;

	rec = visu_link->content;
	fig2 = &rec->fig2;

	fig2->color = rec->color;
	ft_printf("------------  %d \n", fig2->color);

	fig2->x_1 = visu->x1;
	fig2->x_2 = visu->x2;

	temp = ((float)rec->nb_quick / (float)pile->length);
	fig2->y_2 = (temp * 600) + 30;
	fig2->y_1 += fig2->y_2;

	recangle(fig2, test->visu);
}

int main()
{
	//	t_fig_2 fig2;

	t_visu visu;
	visu = new_visu(300, 3300, "push_push");

	t_test_ test;
	test.visu = visu;

	t_dll color_lst;
	t_dll_l color_link;

	t_dll_c pile;
	pile = new_dll_c();

	t_dll color_pile;
	color_pile = new_dll();

	set_(0, 1, pile);
	set_(5, 1, pile);
	set_(15, 1, pile);
	set_(455, 1, pile);
	set_(4, 1, pile);
	set_(4, 1, pile);

	set_(684, 3, pile);
	set_(88, 3, pile);
	set_(88, 3, pile);
	//	set_(354, 3, pile);

	dll_c_print_lst(pile);


	//


	t_dll pile_rec = t__1(pile, color_pile);
	t__1(pile, color_pile);
	print_rec(pile_rec->top->content);
	print_rec(pile_rec->top->next->content);

	//

	t_pile_visu p_visu;
	p_visu = new_pile_visu(30);


	//

	p_visu->list_color = color_pile;
	p_visu->list_rec = pile_rec;
	p_visu->y = 300;

	dll_c_print_lst(pile);
	print_list(p_visu, &test, pile);






	//

	color_lst = new_dll();
	color_link = new_color_link(0, 55);
	dll_add(color_link, color_lst);

	printf("%lX \n", is_color(color_lst, 1));
	printf("%lX \n", is_color(color_lst, 2));
	printf("%lX \n", is_color(color_lst, 31
	));
	printf("%lX \n", is_color(color_lst, 1));

	mlx_loop(visu->mlx);

	////	dll_add()
	//	fig2 = new_fig(30, 30, 130, 430);

	//
	//	fig2->color = 0xf44260;
	//	test.fig2 = fig2;
	//	test.visu = visu;
	////
	//	recangle(fig2,visu);
	//
	//	fig2 = new_fig(130, 130, 230, 230);
	//	fig2->color = 0xf44290;
	//	recangle(fig2,visu);


	//	mlx_key_hook(visu->window.ptr, deal_key, &test);





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