#ifndef FDF_STRUCT_H
#define FDF_STRUCT_H

# include "../src/sources/ft_library_header.h"

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
	int err;
} t_line_;

typedef t_line_ *t_line;

typedef struct s_coord_
{
	int x_1;
	int y_1;
	int x_2;
	int y_2;
} t_coord_;

typedef t_coord_ *t_coord;

typedef struct		s_wrong_link_00
{
	int nb;
	int quick;
} 					t_wrong_link_00;
typedef t_wrong_link_00 *t_wrong_link;

typedef struct		s_color_
{
	int quick;
	long color;
} 					t_color_;

typedef t_color_ *t_color;

typedef struct		s_linkTmp_
{
	int nb;
	int quick;
} 					t_linkTmp_;

typedef t_linkTmp_ *t_linkTmp;

typedef struct s_fig_2_
{
	int x_1;
	int y_1;
	int x_2;
	int y_2;
	long color;
} t_fig_2_00;

typedef t_fig_2_00 *t_fig_2;


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

typedef struct		s_mlx_data_00
{
	void *window;
	void *mlx;
	int x;
	int y;
} 					t_mlx_data_00;

typedef t_mlx_data_00 *t_mlx_data;

typedef struct		s_visualisateur_00
{
	t_mlx_data_00 mlx_data;
	t_fig_2_00 fig2;
//	t_rec_link	rec_link;
	t_dll rec_pile;
	t_dll list_color;
	t_dll_c pile_a;
	t_dll_c pile_b;


} 					t_visualisateur_00;

typedef t_visualisateur_00 *t_visualisateur;



#endif //FDF_STRUCT_H
