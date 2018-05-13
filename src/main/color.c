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

long get_color_2(t_dll_l color_link)
{
	return (((t_color) color_link->content)->color);
}


void set_color(t_dll_l color_link, long color)
{
	((t_rec_link)color_link->content)->color = color;
}


int is_same_quick(t_dll_l color_link,int quick)
{
	return (((t_color) color_link->content)->quick == quick);
}

t_dll_l new_color_link(int quick, long color_hexa)
{
	t_dll_l color_link;
	t_color_ color;

	color.quick = quick;
	color.color = color_hexa;
	color_link = new_dll_l(&color, sizeof(t_color_));
	return (color_link);
}


long is_color(t_dll color_list, int quick)
{
	t_dll_l link;
	static long color = 0x00004b;

	link = color_list->top;
	while (link)
	{
	   if (is_same_quick(link, quick) == TRUE)
	       return (get_color_2(link));
	   link = link->next;
	}
	color += 20;
	link = new_color_link(quick, color);
	dll_add(link, color_list);
	ft_printf("%0x \n", color);
	return (color);
}
