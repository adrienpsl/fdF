///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   ft_atoi.c                                          :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
///*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "../includes/fdf_header.h"
//
////void	new_link
//
//void split_and_get_pxl(t_fdf_get get, t_dll p_pixel)
//{
//	static int i = 0;
//	if (ft_strlen(get->line) != get->size_line)
//		ft_error("lines are changing length");
//	get->split = ft_strsplit(get->line, ' ');
//	while (get->split[i])
//	{
//	    //new link;
//	}
//}
//
//void init_pixel(char *name, t_fdf_get get)
//{
//	ft_memset(&get, 0, sizeof(get));
//	get->fd = open_file(name);
//	get_next_line(get->fd, &get->line);
//	get->size_line = ft_strlen(get->line);
//	if(get->line)
//		free(get->line);
//}
//
//
//void p_pixel(char *name, t_fdf fdf)
//{
//	t_fdf_get_00 get;
//
//	init_pixel(name, &get);
//	while (get_next_line(get.fd, &get.line) > 0)
//	{
//	    ;
//	}
//}