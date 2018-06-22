#ifndef FDF_STRUCT_H
#define FDF_STRUCT_H

# include "../libft/ft_library_header.h"
#include "../../../lib_grafik/project/include/graf_struct.h"

typedef struct		s_data_00
{
	t_pixel pixel_tab;
	int nb_col;
	int nb_line;
	long pxl_where;
} 					t_data_00;
typedef t_data_00 *t_data;

typedef struct s_fdf_00
{
	t_mlx mlx;
	t_data_00 data;
	t_line_00 line;
} t_fdf_00;

typedef t_fdf_00 *t_fdf;

typedef struct s_fdf_get_00
{
	t_str_split split;
	int nb_col;
	int nb_line;
	char *line;
	t_pixel pixel_tab;
	long pos_tab;
	int fd;
	int x;
	int y;
} t_fdf_get_00;

typedef t_fdf_get_00 *t_fdf_get;


#endif //FDF_STRUCT_H
