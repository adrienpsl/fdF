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

#include "../includes/fdf_header.h"

void	add_pixel_link(t_fdf_get get)
{
	static t_pixel_00 pixel;
	static char *z_str;
	t_dll_l pixel_link;

	z_str = get->split[get->x];
	if (ft_is_all_number(z_str) == FALSE)
		ft_error("z is not number");
	pixel.x = get->x;
	pixel.y = get->y;
	pixel.z = ft_atoi(z_str);
	pixel.color = 0xFFFFFF;
	pixel_link = new_dll_l(&pixel, sizeof(t_pixel_00));
	dll_add(pixel_link, get->pixel_pile);

}

void split_and_get_pxl(t_fdf_get get)
{
	if (ft_strlen(get->line) != get->size_line)
		ft_error("lines are changing length");
	get->split = ft_strsplit(get->line, ' ');
	while (get->split[get->x])
	{
		add_pixel_link(get);
		++get->x;
	}
	get->x = 0;
	++get->y;
}

void init_populatie_pixel(char *name, t_fdf_get get, t_fdf fdf)
{
	ft_memset(&get, 0, sizeof(get));
	get->fd = open_file(name);
	get_next_line(get->fd, &get->line);
	get->size_line = ft_strlen(get->line);
	if(get->line)
		free(get->line);
	get->pixel_pile = fdf->pixel_pile;
}


void populate_pixel(char *name, t_fdf fdf)
{
	t_fdf_get_00 get;

	init_populatie_pixel(name, &get, fdf);
	while (get_next_line(get.fd, &get.line) > 0)
	{
	    ;
	}
}