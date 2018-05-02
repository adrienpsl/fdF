#ifndef FDF_STRUCT_H
#define FDF_STRUCT_H



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

typedef struct s_fig_2_
{
	int x_1;
	int y_1;
	int x_2;
	int y_2;
	long color;
} t_fig_2_;

typedef t_fig_2_ *t_fig_2;

typedef struct s_window_
{
	void *ptr;
	int x;
	int y;
} t_window_;

typedef t_window_ *t_window;

typedef struct s_visu_
{
	void *mlx;
	t_window_ window;
	t_fig_2 *fig;
} t_visu_;

typedef t_visu_ *t_visu;

typedef struct s_test_
{
	t_visu visu;
	t_fig_2 fig2;
} t_test_;

typedef t_test_ *t_test;

typedef struct s_push_rec_
{
	t_fig_2_ fig2;
	int min;
	int max;
	int quick;
	long nb_quick;
	long color;
} t_push_rec_;

typedef t_push_rec_ *t_push_rec;

typedef struct		s_pile_y_
{
	int cu;
	int lim;
} 					t_pile_y_;

typedef t_pile_y_ *t_pile_y;


typedef struct		s_pile_visu_
{
//	t_pile_y_ y;
	int y;
	int x1;
	int x2;
	t_dll list_rec;
	t_dll list_color;

} 					t_pile_visu_;

typedef t_pile_visu_ *t_pile_visu;


typedef struct		s_wrong_link_00
{
	int nb;
	int quick;
} 					t_wrong_link_00;

typedef t_wrong_link_00 *t_wrong_link;


#endif //FDF_STRUCT_H
