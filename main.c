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
#include "includes/fdf_header.h"

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
	t_dot_00 dot[4];
} t_rect_00;

typedef t_rect_00 *t_rect;

void set_dot(int x, int y, void *right, void *bottom, t_dot dot)
{
	dot->x = x;
	dot->y = y;
	dot->tab.bottom = bottom;
	dot->tab.right = right;
}

void trace_rec_utils(t_dot dot, t_fdf fdf)
{
	t_line line;
	t_dot c_dot;
	t_mlx mlx;
	line = &fdf->line;
	mlx = fdf->mlx;

	set_line_1(dot->x, dot->y, line);
	if (dot->tab.right)
	{
		c_dot = dot->tab.right;
		set_line_2(c_dot->x, c_dot->y, line);
		trace_line(fdf);
		set_line_1(dot->x, dot->y, line);
	}
	if (dot->tab.bottom)
	{
		c_dot = dot->tab.bottom;
		set_line_2(c_dot->x, c_dot->y, line);
		trace_line(fdf);
	}
	if (dot->tab.bottom || dot->tab.right)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
}

void tracer_rec(t_rect rect, t_fdf fdf)
{
	for (int i = 0; i < 4; ++i)
	{
		trace_rec_utils(&rect->dot[i], fdf);
	}
}

double degd(int d)
{
	return (d / 180.0 * M_PI);
}

void test(t_rect rect)
{
	t_dot dot;

	//	double d_rad = 40;
		double deg = degd(50);
//	double deg = 0.0174533 * 45;

	int tmp_x;
	// (le plus proche de o h gauche  + CELUI LE PLU lion) / 2
	for (int i = 0; i < 4; ++i)
	{
		dot = &rect->dot[i];
		dot->x -= 230;
		dot->y -= 230;
		printf("%f %f \n", dot->x, dot->y);
		tmp_x  = dot->x * cos(deg) - dot->y * sin(deg);
		dot->y = dot->x * sin(deg) + dot->y * cos(deg);
		printf("%f %f \n", dot->x, dot->y);
		dot->x = tmp_x + 230;
		dot->y += 230;
		printf("%f %f \n\n", dot->x, dot->y);
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


int main()
{
	t_mlx mlx;
	t_fdf fdf;
	t_rect_00 rec;

	fdf = new_fdf();
	mlx = fdf->mlx;
	t_dot d_1 = &rec.dot[0];
	t_dot d_2 = &rec.dot[1];
	t_dot d_3 = &rec.dot[2];
	t_dot d_4 = &rec.dot[3];

	set_dot(0, 0, d_2, d_3, d_1);
	set_dot(60, 0, NULL, d_4, d_2);
	set_dot(0, 60, d_4, NULL, d_3);
	set_dot(60, 60, NULL, NULL, d_4);

	tracer_rec(&rec, fdf);
	for (int i = 0; i < 45; ++i)
	{
	}
	test(&rec);
	tracer_rec(&rec, fdf);



	//	mlx_mouse_hook(mlx->window, get_souris_click, &fdf);

	mlx_loop(mlx->mlx);
	return 0;
}