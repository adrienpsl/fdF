#ifndef FDF_STRUCT_H
#define FDF_STRUCT_H

# include "../libft/ft_library_header.h"
#include "mlx_struct.h"

#define POSITION_FIGURE 0
#define HEIGHT    (POSITION_FIGURE + 50)
#define WIDTH    (POSITION_FIGURE + 50)

typedef struct s_fig_2_
{
	int x_1;
	int y_1;
	int x_2;
	int y_2;
	long color;
} t_fig_2_00;
typedef t_fig_2_00 *t_fig_2;

/*
**    stock les coord de tous les pxl, stocker sous forme de tab
*/
typedef struct s_pixel_00
{
	double x;
	double y;
	double z;
	int color;
} t_pixel_00;
typedef t_pixel_00 *t_pixel;


typedef struct		s_data_00
{
	t_pixel pixel_tab;
	int nb_col;
	int nb_line;
	long pxl_where;
} 					t_data_00;
typedef t_data_00 *t_data;


/*
**    lines
*/
typedef struct s_line_00
{
	int x_1;
	int y_1;
	int x_2;
	int y_2;
	int dx;
	int dy;
	int e;

} t_line_00;
typedef t_line_00 *t_line;

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
