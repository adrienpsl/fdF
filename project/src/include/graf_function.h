//
// Created by Adrien PUSEL on 6/22/18.
//

#ifndef GRAF_FUNCTION_H
#define GRAF_FUNCTION_H

#include "graf_struct.h"

/*
**    mlx -------------------------------------------------
*/
t_mlx new_mlx(int x, int y, char *name);
void clear_img(t_mlx mlx);




/*
**    grafique lib --------------------------------------------
*/

void fill_pixel(t_mlx mlx, long x, long y, int color);

/*
**    draw line
*/
//void trace_line(t_fdf fdf);
void dx_p_dy_p(t_fdf fdf);
void dy_p_dx_p(t_fdf fdf);
void dx_p_dy_n(t_fdf fdf);
void dy_n_dx_p(t_fdf fdf);
void dx_p_dy_0(t_fdf fdf);
void dx_n_dy_p(t_fdf fdf);
void dy_p_dx_n(t_fdf fdf);
void dy_n_dx_n(t_fdf fdf);
void dy_0_dx_n(t_fdf fdf);
void dx_n_dy_n(t_fdf fdf);
void dy_p_dx_0(t_fdf fdf);
void dx_0_dy_n(t_fdf fdf);

#endif