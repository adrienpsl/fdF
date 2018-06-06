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

/*
**    add on tab the struc pxl with all coord,
**    check if z is a nb
*/

//void add_pixel_link(t_fdf_get get)
//{
//	static t_pixel_00 pixel;
//	static char *z_str;
//	t_dll_l pixel_link;
//
//	ft_memset(&pixel, 0, sizeof(t_pixel_00));
//	z_str = get->split[get->x];
//	if (ft_is_all_number(z_str) == FALSE)
//		ft_error("z is not number\n");
//	pixel.x = get->x;
//	pixel.y = get->y;
//	pixel.z = ft_atoi(z_str);
//	pixel.color = 0xFFFFFF;
//	pixel_link = new_dll_l(&pixel, sizeof(t_pixel_00));
//	dll_add(pixel_link, get->pixel_pile);
//}

/*
**    fill the tab with all nb, and check the size of all line is the same
*/

//void split_and_get_pxl(t_fdf_get get)
//{
//	get->split = new_str_split(get->line, ' ');
//
//	if (get->nb_col != get->split->all)
//		ft_error("lines are changing length\n");
//	//	while (get->split[get->x])
//	//	{
//	//		add_pixel_link(get);
//	//		++get->x;
//	//	}
//	ft_free_split(&get->split);
//	get->x = 0;
//	++get->y;
//}

void init_and_nb_malloc(char *name_file, t_fdf_get get)
{

	get->fd = open_file(name_file);
	ask_gnl(get->fd, &get->line);

	get->split = ft_strsplit(get->line, ' ');
	get->nb_col = count_split(get->split);
	ft_free_split(&get->split);

	get->nb_line++;
	while (ask_gnl(get->fd, &get->line))
	{
		get->nb_line++;
	}
	free_str(&get->line);

	// faire le tab pour send les data
	// set le dernier a 0 et garder sa size
	get->pixel_tab = ft_malloc_protect(sizeof(t_pixel_00) * get->nb_col *
									   get->nb_col);
	ft_printf("%d \n", get->nb_col * get->nb_col);
	close(get->fd);
	get->fd = open_file(name_file);
}

/*
**   with gnl fill in fdf a dll with all pixel x,y,z
**   the fonction check the enty and the data
*/

void populate_pixel(char *name, t_fdf fdf)
{
	t_fdf_get_00 get;
	static int ret = 0;

	init_and_nb_malloc(name, &get);
	while (ask_gnl(get.fd, &get.line))
	{
//		split_and_get_pxl(&get);
	}
	free_str(&get.line);

	fdf->nb_col = get.nb_col;
	fdf->nb_line = get.nb_line;
	free_str(&get.line);
	close(get.fd);
}
