/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <aoqdeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:17:50 by aoqdeh            #+#    #+#             */
/*   Updated: 2026/02/01 19:43:56 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int i, int max_i)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (i == max_i)
		return (0x000000);
	t = (double) i / max_i;
	r = (int)(sin(30 * t) * 127 + 128);
	g = (int)(sin(20 * t + 1) * 127 + 128);
	b = (int)(sin(40 * t + 3) * 127 + 128);
	return ((r << 16) | (g << 8) | b);
}

int	get_iteration(double zx, double zy, t_mlx *fract)
{
	double	tmp;
	int		i;

	i = 0;
	while ((zx * zx) + (zy * zy) < 4 && i < fract->max_iter)
	{
		tmp = zx * zx - zy * zy + fract->julia.re;
		zy = 2 * zx * zy + fract->julia.im;
		zx = tmp;
		i++;
	}
	return (i);
}

void	put_pix(t_mlx *fract, int x, int y)
{
	double	zx;
	double	zy;
	int		i;

	if (fract->type == mandelbrot)
	{
		zx = 0;
		zy = 0;
		fract->julia.re = get_actual_x(x, fract);
		fract->julia.im = get_actual_y(y, fract);
	}
	else
	{
		zx = get_actual_x(x, fract);
		zy = get_actual_y(y, fract);
	}
	i = get_iteration(zx, zy, fract);
	put_colored_pix(fract, x, y, get_color(i, fract->max_iter));
}

void	print_fractol(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pix(mlx, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->obj, mlx->win, mlx->img.image, 0, 0);
}
