/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chi <chi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:36:08 by aoqdeh            #+#    #+#             */
/*   Updated: 2026/01/29 08:00:16 by chi              ###   ########.fr       */
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
typedef struct s_mlx
{
    void    *obj;
    void    *win;
    t_img   image;
    t_type      type;
    int			max_iter;
    double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
    double		julia_i;
	double		julia_r;
    int		color_shift;
}   t_mlx;

typedef struct s_img
{
    void    *img;
    char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}   t_img;

#endif