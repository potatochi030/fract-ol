/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <aoqdeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:39:24 by aoqdeh            #+#    #+#             */
/*   Updated: 2026/02/01 20:42:35 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_colored_pix(t_mlx *fract, int x, int y, int color)
{
	char	*dst;

	dst = fract->img.addr + (y * fract->img.ll + x * (fract->img.bpp / 8));
	*(unsigned int *)dst = color;
}

double	get_actual_x(int x, t_mlx *fract)
{
	double	aft_x;

	aft_x = ((x - WIDTH / 2.0) / fract->zoom) + fract->central_x;
	return (aft_x);
}

double	get_actual_y(int y, t_mlx *fract)
{
	double	aft_y;

	aft_y = -((y - HEIGHT / 2.0) / fract->zoom) + fract->central_y;
	return (aft_y);
}

void	init_vals(t_mlx *mlx)
{
	mlx->max_iter = 250;
	mlx->zoom = 200.0;
	mlx->central_x = 0.0;
	mlx->central_y = 0.0;
	mlx->julia.im = 0.27015;
	mlx->julia.re = -0.7;
}

int	close_mlx(t_mlx *mlx)
{
	if (mlx->img.image)
		mlx_destroy_image(mlx->obj, mlx->img.image);
	if (mlx->win)
		mlx_destroy_window(mlx->obj, mlx->win);
	if (mlx->obj)
	{
		mlx_destroy_display(mlx->obj);
		free(mlx->obj);
	}
	exit(0);
}
