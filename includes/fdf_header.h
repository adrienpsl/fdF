#ifndef FDF_FDF_HEADER_H
#define FDF_FDF_HEADER_H

#include "../sources/ft_library_header.h"

# include "../mlx/mlx.h"

# include "mlx_object.h"


t_mlx	new_mlx(int x, int y, char *name);
void	fill_pixel(t_mlx mlx, long x, long y, int color);

#endif //FDF_FDF_HEADER_H
