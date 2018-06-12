
#ifndef MLX_STRUCT_H
#define MLX_STRUCT_H

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
typedef t_mlx_00 *t_mlx;

#endif
