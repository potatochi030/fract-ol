#include "fractol.h"

void    put_colored_pix(t_mlx fract, int x, int y, int color)
{
    char    *dst;

    dst = fract.img.addr + (y * fract.img.ll + x * (fract.img.bpp / 8));
    *(unsigned int*)dst = color;
}

int     map_x(int x, t_mlx fract)
{
    return(((x - WIDTH / 2) / fract.zoom) + fract.central_x);
}
int     map_y(int y, t_mlx fract)
{
    return(((y - HEIGHT / 2) /fract.zoom) + fract.central_y);
}
void    init_vals(t_mlx mlx)
{
    (void)mlx;
    mlx.max_iter = 250;
    mlx.zoom = 200;
    mlx.central_x = 0;
    mlx.central_y = 0;
    mlx.julia.im = 0.27015;
    mlx.julia.re = -0.7;
}
int     close_mlx(t_mlx *mlx)
{
    if (mlx->img.image)
        mlx_destroy_image(mlx->obj, mlx->img.image);
    if (mlx->win)
        mlx_destroy_window(mlx->obj, mlx->win);
    if (mlx->obj)
    {
        mlx_destroy_display(mlx->obj);
        free(mlx->obj);
    }
    exit(0);
}
