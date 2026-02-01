/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chi <chi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:36:08 by aoqdeh            #+#    #+#             */
/*   Updated: 2026/02/01 11:03:39 by chi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

typedef enum e_type
{
    julia,
    mandelbrot
}   t_type;

typedef struct s_complex
{
    long double     re;
    long double     im;
}   t_complex;

typedef struct s_img
{
    void    *image;
    char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}   t_img;

typedef struct s_mlx
{
    void    *obj;
    void    *win;
    t_img   img;
    t_type      type;
    t_complex   julia;
    int		max_iter;
    int     zoom;
    int     central_x;
    int     central_y;
}   t_mlx;



void    print_fractol(t_mlx mlx);
void    put_pix(t_mlx fract, int x, int y);
int     get_iteration(double zx, double zy, t_mlx fract);
int     get_color(int i, int max_i);
void    end(void);
double      convert_double(char *str);
void    init_julia(char **argv,t_mlx fract);
void    decide_fract(int argc, char **argv, t_mlx fract);
void    put_colored_pix(t_mlx fract, int x, int y, int color);
void    init_vals(t_mlx mlx);
int     close_mlx(t_mlx *mlx);
int     handle_esc(int keycode, t_mlx *mlx);
int     map_x(int x, t_mlx fract);
int     map_y(int y, t_mlx fract);


#endif