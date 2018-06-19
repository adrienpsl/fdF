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

#include <math.h>
#include "project/includes/fdf_header.h"

//int get_souris_click(int button, int x, int y, void *param)
//{
//	static int i = 0;
//	t_fdf fdf = param;
//	t_mlx mlx = fdf->mlx;
//	t_line line = &fdf->line;
//
//	(void) button;
//	if (i == 0)
//	{
//		set_line_1(x, y, line);
//		++i;
//	}
//
//	else if (i == 1)
//	{
//		set_line_2(x, y, line);
//		++i;
//	}
//
//	if (i == 2)
//	{
//		trace_line(fdf);
//		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
//		i = 0;
//	}
//	//	ft_printf("%d \n", button);
//
//	return (TRUE);
//}

typedef struct s_rect_00
{
	t_pixel_00 pixel[4];
} t_rect_00;

typedef t_rect_00 *t_rect;

void set_pixel(int x, int y, int z, t_pixel pixel)
{
	pixel->x = x;
	pixel->y = y;
	pixel->z = z;
}

//void trace_rec_utils(t_pixel pixel, t_fdf fdf)
//{
//	t_line line;
//	t_pixel c_pixel;
//	t_mlx mlx;
//	line = &fdf->line;
//	mlx = fdf->mlx;
//
//	set_line_1(pixel->x, pixel->y, line);
//	if (pixel->tab.right)
//	{
//		c_pixel = pixel->tab.right;
//		set_line_2(c_pixel->x, c_pixel->y, line);
//		trace_line(fdf);
//		set_line_1(pixel->x, pixel->y, line);
//	}
//	if (pixel->tab.bottom)
//	{
//		c_pixel = pixel->tab.bottom;
//		set_line_2(c_pixel->x, c_pixel->y, line);
//		trace_line(fdf);
//	}
//	if (pixel->tab.bottom || pixel->tab.right)
//		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
//}
//
//void tracer_rec(t_rect rect, t_fdf fdf)
//{
//	for (int i = 0; i < 4; ++i)
//	{
//		trace_rec_utils(&rect->pixel[i], fdf);
//	}
//}

double degd(int d)
{
	return (d / 180.0 * M_PI);
}

// matrice de rotation du z ?
// il me faut plus de point pour que ca marche


//int test_souris(int button, int x, int y, void *param)
//{faire
//	static int i = 0;
//	t_fdf fdf = param;
//	t_mlx mlx = fdf->mlx;
//	t_line line = &fdf->line;
//
//	(void) button;
//	test()
//	//	ft_printf("%d \n", button);
//
//	return (TRUE);
//}

// fonction trace :
//	prend fdf, t /

//void fdf_trace(t_fdf fdf)
//{
//
//}


// print les pixel :
void print_pix(t_fdf fdf)
{
	t_pixel pixel;
	int i = 0;
	int all = fdf->data.nb_line * fdf->data.nb_line;
	static int x = 0;
	static int y = 0;

	while (i < all)
	{
		pixel = fdf->data.pixel_tab + i;
		printf("%.0f ", pixel->x);
		printf("%.0f ", pixel->y);
		printf("%.0f // ", pixel->z);
		++x;
		if (x == 4)
		{
			y++;
			x = 0;
			ft_printf("\n");
		}
		i++;
	}
}

void create_mlx(t_fdf fdf)
{
	t_data data;

	data = &fdf->data;
	fdf->mlx = new_mlx(data->nb_line, data->nb_col, "FDF");
}
// je dois calculer la distance de mon pxl
// j'envie ce truc dans les pixels

void test(t_fdf fdf)
{
	t_pixel tab_pxl = fdf->data.pixel_tab;
	t_pixel pixel;
	double deg = degd(45);

	double tmp_x;
//	int middle_x = 500;
	int middle_x = 50;
//	int middle_y = 500;
	int middle_y = 50;

	for (int i = 0; i < 4; ++i)
	{
		pixel = tab_pxl + i;
		pixel->x += middle_x;
		pixel->y += middle_y;
//		pixel->z -= middle_y;

		printf("%f %f \n", pixel->x, pixel->y);
		tmp_x = pixel->x * cos(deg) - pixel->y * sin(deg);
		printf("%f %f \n",  cos(deg), sin(deg));
		pixel->y = pixel->x * sin(deg) + pixel->y * cos(deg);

		printf("%f %f \n", pixel->x, pixel->y);
		pixel->x = tmp_x - middle_x;
		pixel->y -= middle_y;
		printf("%f %f \n\n", pixel->x, pixel->y);
	}
}


int main(int ac, char **av)
{
	(void) ac;
	t_fdf fdf;

	fdf = new_fdf();
	populate_pixel(av[1], fdf);
	fdf->mlx = new_mlx(1000, 1000, "FDF");

	//	mlx_mouse_hook(mlx->window, get_souris_click, &fdf);
	//	t_data data;
	//	data = &fdf->data;
//	trace_tab(fdf);
//	test(fdf);
	trace_tab(fdf);
	print_pix(fdf);
//	trace_tab(fdf);
	mlx_put_image_to_window(fdf->mlx->ptr, fdf->mlx->window.ptr,
							fdf->mlx->img.ptr, 0, 0);
	mlx_loop(fdf->mlx->ptr);


	//	fdf->mlx->y = fdf->nb_col;
	//	print_pix(fdf);

	//	dll_func(fdf->pixel_pile, &print_pix);


	destroy_fdf(fdf);
	return 0;
}