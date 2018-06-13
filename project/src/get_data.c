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

void add_pixel_link(t_fdf_get get)
{
	static char *z_str = NULL;
	static t_pixel pixel = NULL;

	z_str = get->split->current;
	if (ft_is_all_number(z_str) == FALSE)
		ft_error("z is not number\n");
	pixel = &get->pixel_tab[get->pos_tab];
	pixel->x = (get->x)  ;
	pixel->y = (get->y) ;
	pixel->z = ft_atoi(z_str);
	pixel->color = 0xFFFFFF;
	get->pos_tab++;
}

/*
**    fill the tab with all nb, and check the size of all line is the same
*/

void split_and_get_pxl(t_fdf_get get)
{
	get->split = new_str_split(get->line, ' ');
	if (get->nb_col != get->split->all)
		ft_error("lines are changing length\n");
	while (str_split_get(get->split))
	{
		add_pixel_link(get);
		++get->x;
	}
	get->x = 0;
	++get->y;
}

void init_and_nb_malloc(char *name_file, t_fdf_get get)
{
	char **split_count_col;

	ft_memset(get, 0, sizeof(t_fdf_get_00));
	get->fd = open_file(name_file);
	ask_gnl(get->fd, &get->line);

	split_count_col = ft_strsplit(get->line, ' ');
	get->nb_col = count_split(split_count_col);
	ft_free_split(&split_count_col);

	get->nb_line++;
	while (ask_gnl(get->fd, &get->line))
	{
		get->nb_line++;
	}
	free_str(&get->line);

	get->pixel_tab = ft_malloc_protect(
	 sizeof(t_pixel_00) * get->nb_col * get->nb_col);
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

	init_and_nb_malloc(name, &get);
	while (ask_gnl(get.fd, &get.line))
	{
		split_and_get_pxl(&get);
	}
	free_str(&get.line);

	fdf->data.nb_col = get.nb_col;
	fdf->data.nb_line = get.nb_line;
	fdf->data.pixel_tab = get.pixel_tab;
	close(get.fd);
}
