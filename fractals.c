#include "fractol.h"

void    put_colored_pix(t_mlx fract, int x, int y, int color)
{
    char    *dst;

    dst = fract.image.addr + (y * fract.image.ll + x * (fract.image.bpp / 8));
    *(unsigned int*)dst = color;
}
int     map_x(int x, t_mlx fract)
{
    return (fract.min_re + (x / (double)WIDTH) * (fract.max_re - fract.min_re));
}
int     map_y(int y, t_mlx fract)
{
    return (fract.min_im + (y / (double)HEIGHT) * (fract.max_im - fract.min_im));
}

void    put_pix(t_mlx fract, int x, int y)
{
    double  cx;
    double  cy;
    int     col;

    if (fract.type == mandelbrot)
    {
        cx = 0;
        cy = 0;
        fract.julia_i = map_y(y, fract);
        fract.julia_r = map_x(x, fract);
    }
    else
    {
        cx = map_y(y, fract);
        cy = map_x(x, fract);
    }
}

void    render_fractol(t_mlx mlx)
{
    int x;
    int y;

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
    mlx_put_image_to_window(mlx.obj, mlx.win, mlx.image.img, 0, 0);
}
