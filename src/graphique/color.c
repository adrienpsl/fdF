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

long	get_color_2(t_dll_l color_link)
{
	return (((t_color)color_link->content)->color);
}

void	set_color(t_dll_l color_link, long color)
{
	((t_rec_link)color_link->content)->color = color;
}

int		is_same_quick(t_dll_l color_link, int quick)
{
	return (((t_color)color_link->content)->quick == quick);
}

int		new_color(void)
{
	int a;

	a = rand() % 255;
	a = a << 8;
	a += rand() % 255;
	a = a << 8;
	a += rand() % 255;
	return (a);
}

long	is_color(t_dll color_list, int quick)
{
	t_dll_l link;

	link = color_list->top;
	while (link)
	{
		if (is_same_quick(link, quick) == TRUE)
			return (get_color_2(link));
		link = link->next;
	}
	link = new_color_link(quick, new_color());
	dll_add(link, color_list);
	return (get_color_2(link));
}
