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

t_fdf destroy_fdf(t_fdf fdf)
{
	if (fdf->data.pixel_tab)
	    free(fdf->data.pixel_tab);
	free(fdf);
	return (fdf);
}


t_fdf new_fdf()
{
	t_fdf fdf;

	fdf = ft_malloc_protect(sizeof(t_fdf_00));
	ft_memset(fdf, 0, sizeof(t_fdf_00));
	return (fdf);
}
