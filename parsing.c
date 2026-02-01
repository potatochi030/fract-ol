/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <aoqdeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:39:16 by aoqdeh            #+#    #+#             */
/*   Updated: 2026/02/01 19:54:44 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	end(void)
{
	ft_putstr_fd("Usage: ./fractol mandelbrot\n", 2);
	ft_putstr_fd("       ./fractol julia <real cx> <imaginary cy>\n", 2);
	exit(-1);
}

int	is_double(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == 't')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (i < ft_strlen(str))
		return (0);
	return (1);
}

double	convert_double(char *str)
{
	double	perc;
	double	dev;
	size_t	i;

	i = 0;
	dev = 1;
	perc = 0.0;
	while (str[i] == ' ' || str[i] == 't')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] == '.')
		i++;
	perc = ft_atoi(&str[i]);
	while (ft_isdigit(str[i++]) == 1)
		dev = dev * 10;
	return (((double)ft_atoi(str) + perc / (double)dev));
}

void	init_julia(char **argv, t_mlx *fract)
{
	if (is_double(argv[2]) && is_double(argv[3]))
	{
		fract->julia.re = convert_double(argv[2]);
		fract->julia.im = convert_double(argv[3]);
	}
	else
	{
		ft_putendl_fd("Number Format Error: julia requires decimal points", 2);
		exit(-1);
	}
}

void	decide_fract(int argc, char **argv, t_mlx *fract)
{
	if (argc < 2 || argc > 4)
		end();
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		fract->type = mandelbrot;
	}
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (argc != 4)
		{
			ft_putendl_fd("Wrong Number of Variables", 2);
			ft_putendl_fd("Example Points: (.28,.008) (-.79,.15)", 1);
			exit(-1);
		}
		fract->type = julia;
		init_julia(argv, fract);
	}
	else
		end();
}
