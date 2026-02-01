#include "fractol.h"

int     get_color(int i, int max_i)
{
    double  t;
    int     r;
    int     g;
    int     b;

    if (i == max_i)
        return (0x000000);
    t = (double) i / max_i;
    r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return ((r << 16) | (g << 8) | b);
}
int     get_iteration(double zx, double zy, t_mlx fract)
{
    double  tmp;
    int     i;

    i = 0;
    while ((zx * zx) + (zy * zy) < 4 && i < fract.max_iter)
    {
        tmp  = zx * zx - zy * zy + fract.julia.re;
        zy = 2 * zx * zy + fract.julia.im;
        zx = tmp;
        i++;
    }
    return (i);
}
void    put_pix(t_mlx fract, int x, int y)
{
    double  cx;
    double  cy;
    int     i;
    
    if (fract.type == mandelbrot)
    {
        cx = 0;
        cy = 0;
        fract.julia.re = map_x(x, fract);
        fract.julia.im = map_y(y, fract);
    }
    else
    {
        cx = map_x(x, fract);
        cy = map_y(y, fract);
    }
    i = get_iteration(cx, cy, fract);
    put_colored_pix(fract, x, y, get_color(i, fract.max_iter));
}

void    print_fractol(t_mlx mlx)
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
    mlx_put_image_to_window(mlx.obj, mlx.win, mlx.img.image, 0, 0);
}
