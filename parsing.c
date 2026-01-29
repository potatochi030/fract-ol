#include "fractol.h"

void    end()
{
    ft_putstr_fd("Usage: ./fractol mandelbrot\n", 2);
    ft_putstr_fd("       ./fractol julia <real cx> <imaginary cy>\n", 2);
    exit(-1);
}

void    init_julia(char **argv, t_mlx fract)
{
    fract.type = julia;
}

void    read_input(int argc, char **argv, t_mlx fract)
{
    fract.min_re = -2;
    fract.max_re = 2;
    fract.min_im = -2;
    fract.max_im = 2;

    if (argc < 2)
        end();
    if (ft_strncmp(argv[1], "mandelbrot\0", 11) == 0)
    {
        fract.type = mandelbrot;
        return ;
    }
    else if (ft_strncmp(argv[1], "julia\0", 6) == 0)
    {
        if (argc < 4)
        {
            ft_putstr_fd("Insuffiecient Variables: julia <real cx> <imaginary cy>\n", 2);
            ft_putstr_fd("You can use the following points () () ()", 1);//check
            exit(-1);
        }
        fract.type = julia;
        return ;
    }
    else
        end();
}
