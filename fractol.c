/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <aoqdeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:36:53 by aoqdeh            #+#    #+#             */
/*   Updated: 2026/02/01 17:37:05 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	end(void)
{
	ft_putstr_fd("Usage: ./fractol mandelbrot\n", 2);
	ft_putstr_fd("       ./fractol julia <real cx> <imaginary cy>\n", 2);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	init_vals(&mlx);
	decide_fract(argc, argv, &mlx);
	mlx.obj = mlx_init();
	if (!mlx.obj)
		return (-1);
	mlx.win = mlx_new_window(mlx.obj, WIDTH, HEIGHT, "fractol");
	if (!mlx.win)
		close_mlx(&mlx);
	mlx.img.image = mlx_new_image(mlx.obj, WIDTH, HEIGHT);
	if (!mlx.img.image)
		close_mlx(&mlx);
	mlx.img.addr = mlx_get_data_addr(mlx.img.image, &mlx.img.bpp,
			&mlx.img.ll, &mlx.img.endian);
	print_fractol(&mlx);
	mlx_key_hook(mlx.win, handle_esc, &mlx);
	mlx_mouse_hook(mlx.win, handle_zoom, &mlx);
	mlx_hook(mlx.win, 17, 0, close_mlx, &mlx);
	mlx_loop(mlx.obj);
}
