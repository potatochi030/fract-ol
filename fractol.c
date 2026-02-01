/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chi <chi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:36:53 by aoqdeh            #+#    #+#             */
/*   Updated: 2026/02/01 11:45:05 by chi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

int     main(int argc, char **argv)
{
    t_mlx   mlx;
    
    init_vals(mlx);
    decide_fract(argc, argv, mlx);
    mlx.obj = mlx_init();
    if (!mlx.obj)
        return (-1);
    mlx.win = mlx_new_window(mlx.obj, WIDTH, HEIGHT, "fractol");
    if (!mlx.win)
        close_mlx(&mlx);
    mlx.img.image = mlx_new_image(mlx.obj, WIDTH, HEIGHT);
    if (!mlx.img.image)
        close_mlx(&mlx);
    mlx.img.addr = mlx_get_data_addr(mlx.img.image, &mlx.img.bpp, &mlx.img.ll, &mlx.img.endian);
    print_fractol(mlx);
    mlx_key_hook(mlx.win, handle_esc, &mlx);
    mlx_mouse_hook(mlx.win, handle_esc, &mlx);
    mlx_hook(mlx.win, 17, 0, close_mlx, &mlx);
    mlx_loop(mlx.obj);
}
