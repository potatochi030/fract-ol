/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chi <chi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:36:53 by aoqdeh            #+#    #+#             */
/*   Updated: 2026/01/29 08:02:36 by chi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "fractol.h"

int     main(int argc, char **argv)
{
    t_mlx   mlx1;

    read_input(argc, argv, mlx1);
    mlx1.obj = mlx_init();
    if (!mlx1.obj)
        return (-1);
    mlx1.win = mlx_new_window(mlx1.obj, WIDTH, HEIGHT, "fractol");
    if (!mlx1.win)
        close_mlx(mlx1);
    mlx1.image.img = mlx_new_image(mlx1.obj, WIDTH, HEIGHT);
    if (!mlx1.image.img)
        close_mlx(mlx1);
    mlx1.image.addr = mlx_get_data_addr(mlx1.image.img, &mlx1.image.bpp, &mlx1.image.ll, &mlx1.image.endian);
    
        
    mlx_loop(mlx1.obj);
}
