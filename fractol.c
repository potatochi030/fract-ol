/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <aoqdeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:36:53 by aoqdeh            #+#    #+#             */
/*   Updated: 2026/01/28 17:19:41 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "fractol.h"

int main()
{
    t_mlx mlx1;
    char    *dst;

    mlx1.mlx = mlx_init();
    mlx1.win = mlx_new_window(mlx1.mlx, WIDTH, HIGHT, "fractol");
    mlx1.img = mlx_new_image(mlx1.mlx, WIDTH, HIGHT);
    mlx1.addr = mlx_get_data_addr(mlx1.img, &mlx1.bpp, &mlx1.ll, &mlx1.endian);
    dst = mlx1.addr + (5 * mlx1.ll + 5 * (mlx1.bpp / 8));
    *(unsigned int*)dst = 0x00FF0000;
    mlx_put_image_to_window(mlx1.mlx, mlx1.win, mlx1.img, 0, 0);
    mlx_loop(mlx1.mlx);
}