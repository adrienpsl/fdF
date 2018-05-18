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

#include "../../includes/all_includes.h"

t_dll_l		new_color_link(int quick, long color_hexa)
{
	t_dll_l		color_link;
	t_color_	color;

	color.quick = quick;
	color.color = color_hexa;
	color_link = new_dll_l(&color, sizeof(t_color_));
	return (color_link);
}

void		set_set(t_dll_l visu_link, t_fig_2 fig2)
{
	t_rec_link rec;

	rec = visu_link->content;
	fig2->color = rec->color;
	fig2->x_2 += (rec->percent * X_WINDOW);
}

void		print_list(t_v visu, int y, int mode)
{
	t_dll_l		rec_link;
	t_fig_2_00	fig2;
	t_rec_link	rec;

	rec_link = visu->rec_pile->top;
	fig2.x_1 = 0;
	fig2.x_2 = 0;
	fig2.y_1 = y;
	fig2.y_2 = y + 150;
	while (rec_link)
	{
		rec = rec_link->content;
		set_set(rec_link, &fig2);
		mode == 0 ?
		recangle(&fig2, &visu->mlx_data) :
		the_legende(&visu->mlx_data, rec, &fig2);
		fig2.x_1 = fig2.x_2;
		rec_link = rec_link->next;
	}
}
