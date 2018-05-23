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

t_fdf destroy_fdf(t_fdf fdf)
{

	// destroy mlx


	destroy_dll(&fdf->p_pixel);
	return (fdf);
}

t_fdf new_fdf()
{
	t_fdf fdf;

	fdf = ft_malloc_protect(sizeof(t_fdf_00));
	ft_memset(fdf, 0, sizeof(fdf));

	// je ne protege pas mon init

	fdf->mlx = new_mlx(1000, 1000, "lala");
	fdf->p_pixel = new_dll();
	return (fdf);
}

