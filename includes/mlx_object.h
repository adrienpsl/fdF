#ifndef FDF_STRUCT_H
#define FDF_STRUCT_H

# include "../sources/ft_library_header.h"


typedef struct s_coord_
{
	int x_1;
	int y_1;
	int x_2;
	int y_2;
} t_coord_;

typedef t_coord_ *t_coord;


typedef struct		s_color_
{
	int quick;
	long color;
} 					t_color_;
typedef t_color_ *t_color;


typedef struct s_fig_2_
{
	int x_1;
	int y_1;
	int x_2;
	int y_2;
	long color;
} t_fig_2_00;
typedef t_fig_2_00 *t_fig_2;


typedef struct		s_dot_tab_00
{
	struct s_dot_00 *right;
	struct s_dot_00 *bottom;
} 					t_dot_tab_00;
typedef t_dot_tab_00 *t_dot_tab;


typedef struct		s_dot_00
{
	double	x;
	double	y;
	double	z;
	t_dot_tab_00 tab;
} 					t_dot_00;

typedef t_dot_00 *t_dot;



typedef struct s_rec_link_00
{
	long nb_quick;
	int color;
	int min;
	int max;
	int quick;
	float percent;
} t_rec_link_00;
typedef t_rec_link_00 *t_rec_link;

typedef struct		s_mlx_00
{
	void			*window;
	void			*mlx;
	int				x;
	int				y;
	void			*img;
	void			*str_img;
}					t_mlx_00;

typedef t_mlx_00 *t_mlx;

/*
**    lines
*/
typedef struct s_line_
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


typedef struct		s_fdf_00
{
	t_mlx			mlx;
	t_dll			p_pixel;
	t_line_00		line;
	int				line_size;
} 					t_fdf_00;
typedef t_fdf_00 *t_fdf;

typedef struct		s_fdf_get_00
{
	size_t	size_line;
	int fd;
	int ret;
	char **split;
	char *line;
} 					t_fdf_get_00;
typedef t_fdf_get_00 *t_fdf_get;






#endif //FDF_STRUCT_H
