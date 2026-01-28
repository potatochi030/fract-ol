/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <aoqdeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:36:08 by aoqdeh            #+#    #+#             */
/*   Updated: 2026/01/28 16:31:48 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HIGHT 800

typedef struct s_mlx
{
    void    *mlx;
    void    *win;
    void    *img;
    char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}   t_mlx;

#endif