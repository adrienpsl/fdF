#ifndef FDF_FDF_HEADER_H
# define FDF_FDF_HEADER_H

# include "../libft/ft_library_header.h"
# include "mlx.h"
# include "mlx_object.h"

t_mlx new_mlx(int x, int y, char *name);
t_fdf new_fdf();
t_fdf destroy_fdf(t_fdf fdf);

void fill_pixel(t_mlx mlx, long x, long y, int color);

/*
**    line
*/
void set_line_1(int x, int y, t_line l);
void set_line_2(int x, int y, t_line l);

/*
**    getter data
*/
void populate_pixel(char *name, t_fdf fdf);

/*
**    draw line
*/
void trace_line(t_fdf fdf);
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