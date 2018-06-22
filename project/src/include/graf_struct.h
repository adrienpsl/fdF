
#ifndef MLX_STRUCT_H
#define MLX_STRUCT_H

typedef struct t_mlx_00 *t_mlx;

/*
**    stock les coord de tous les pxl, stocker sous forme de tab
*/
typedef struct s_vector_00
{
	double x;
	double y;
	double z;
	int color;
} t_vector_00;
typedef t_vector_00 *t_vector;

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
	t_mlx mlx;

} t_line_00;
typedef t_line_00 *t_line;

/*
**    img mlx
*/
typedef struct		s_img_00
{
	void *ptr;
	void *str;
	int size_ligne;
} 					t_img_00;
typedef t_img_00 *t_img;

/*
**    window
*/
typedef struct		s_window_00
{
	int nb_pixel_x;
	int nb_pixel_y;
	void *ptr;
} 					t_window_00;
typedef t_window_00 *t_window;

/*
**   stock les info de la fenetre
*/

typedef struct s_mlx_00
{
	t_window_00 window;
	t_img_00	img;
	void *ptr;
} t_mlx_00;

#endif
