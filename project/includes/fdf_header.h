#ifndef FDF_FDF_HEADER_H
# define FDF_FDF_HEADER_H

# include "../libft/ft_library_header.h"
# include "mlx.h"
# include "fdf_struct.h"

# define X 0
# define Y 1
# define Z 2


/*
**    fdf ------------------------------------------------------
*/
t_fdf new_fdf();
t_fdf destroy_fdf(t_fdf fdf);

/*
**    test function
*/
int trace_tab(t_fdf fdf);


/*
**    getter data
*/
void populate_pixel(char *name, t_fdf fdf);




#endif