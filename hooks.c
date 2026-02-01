/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <aoqdeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:34:53 by aoqdeh            #+#    #+#             */
/*   Updated: 2026/02/01 19:43:56 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_esc(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		close_mlx(mlx);
	return (0);
}

int	handle_zoom(int code, int x, int y, t_mlx *mlx)
{
	double	pre_x;
	double	pre_y;
	double	aft_x;
	double	aft_y;

	pre_x = get_actual_x(x, mlx);
	pre_y = get_actual_y(y, mlx);
	if (code == 4)
		mlx->zoom *= 1.05;
	else if (code == 5)
		mlx->zoom /= 1.05;
	aft_x = get_actual_x(x, mlx);
	aft_y = get_actual_y(y, mlx);
	mlx->central_x += pre_x - aft_x;
	mlx->central_y += pre_y - aft_y;
	mlx_clear_window(mlx->obj, mlx->win);
	print_fractol(mlx);
	mlx_put_image_to_window(mlx->obj, mlx->win, mlx->img.image, 0, 0);
	return (0);
}
