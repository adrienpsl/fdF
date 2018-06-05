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

void test(t_rect rect)
{
	t_pixel pixel;
	double deg = degd(50);

	int tmp_x;
	static int middle_x = (HEIGHT + POSITION_FIGURE) / 2;
	static int middle_y = (WIDTH + POSITION_FIGURE) / 2;

	for (int i = 0; i < 4; ++i)
	{
		pixel = &rect->pixel[i];
		pixel->x -= middle_x;
		pixel->y -= middle_y;
		pixel->z -= middle_y;


		printf("%f %f \n", pixel->x, pixel->y);
		tmp_x = pixel->x * cos(deg) - pixel->y * sin(deg);
		pixel->y = pixel->x * sin(deg) + pixel->y * cos(deg);


		printf("%f %f \n", pixel->x, pixel->y);
		pixel->x = tmp_x + middle_x;
		pixel->y += middle_y;
		printf("%f %f \n\n", pixel->x, pixel->y);
	}
}

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
void print_pix(t_dll_l link)
{
	t_pixel pixel;

	pixel = link->content;
	ft_printf("%d ", pixel->x);
	ft_printf("%d ", pixel->y);
	ft_printf("%d \n", pixel->z);
}

int main(int ac, char **av)
{
	(void)ac;
//	t_mlx mlx;
	t_fdf fdf;

//	t_rect_00 rec;

	fdf = new_fdf();
//	mlx = fdf->mlx;
//	t_pixel d_1 = &rec.pixel[0];
//	t_pixel d_2 = &rec.pixel[1];
//	t_pixel d_3 = &rec.pixel[2];
//	t_pixel d_4 = &rec.pixel[3];


//	set_pixel(POSITION_FIGURE, POSITION_FIGURE, z, d_1);
//	set_pixel(WIDTH, POSITION_FIGURE, z, NULL, d_4, d_2);
//	set_pixel(POSITION_FIGURE, HEIGHT, z, d_4, NULL, d_3);
//	set_pixel(HEIGHT, WIDTH, z, NULL, NULL, d_4);
//
//	tracer_rec(&rec, fdf);
//	for (int i = 0; i < 45; ++i)
//	{
//	}
//	test(&rec);
//	tracer_rec(&rec, fdf);



	//	mlx_mouse_hook(mlx->window, get_souris_click, &fdf);

//	mlx_loop(mlx->mlx);
	populate_pixel(av[1], fdf);
	dll_func(fdf, &print_pixel);


	destroy_fdf(fdf);
	return 0;
}