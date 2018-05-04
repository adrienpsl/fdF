#ifndef FDF_FDF_HEADER_H
#define FDF_FDF_HEADER_H

#include "../src/sources/ft_library_header.h"

# include "../mlx/mlx.h"

# include "struct_fdf.h"


//
///*
//**    temp_dev
//*/
//void print_pxl(t_under under);
//
//void    recangle(t_under under);
//
///*
//**    bre_function
//*/
//void horizon_left_right(t_under under);
//void horizon_right_left(t_under under);
//void verticaly_up_end(t_under under);
//void verticaly_end_up(t_under under);
//
//
//void test_(t_under under);
//void test_2(t_under under);
//
///*
//**    s_data function
//*/
//
//
//
//
///*
//**    debug
//*/
//void d_set_pos(int x1, int y1, int x2, int y2, t_pos pos);
//void print_pos(t_pos pos);

void    recangle(t_fig_2 fig2, t_visu visu);

void trace_legend_rec(t_fig_2 fig2, t_visu visu, t_push_rec rec);

long is_color(t_dll color_list, int quick);
t_dll_l new_color_link(int quick, long color);
int is_same_quick(t_dll_l color_link,int quick);
void set_color(t_dll_l color_link, long color);

#endif //FDF_FDF_HEADER_H
