#ifndef FDF_FDF_HEADER_H
#define FDF_FDF_HEADER_H

#include "../sources/ft_library_header.h"

# include "../mlx/mlx.h"

# include "mlx_object.h"


t_mlx	new_mlx(int x, int y, char *name);
void	fill_pixel(t_mlx mlx, long x, long y, int color);


/*
**    line
*/
void set_line_1(int x, int y, t_line l);
void set_line_2(int x, int y, t_line l);


#endif //FDF_FDF_HEADER_H
