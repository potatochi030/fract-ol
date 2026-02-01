#include "fractol.h"

int     handle_esc(int keycode, t_mlx *mlx)
{
    if (keycode == 65307)
        close_mlx(mlx);
    return (0);
}

int     handle_zoom(int code, int x, int y, t_mlx *mlx)
{
    int     pre_x;
    int     pre_y;
    int     aft_x;
    int     aft_y;

    pre_x = map_x(x, *mlx);
    pre_y = map_y(y, *mlx);
    if (code == 3 && mlx->type == julia)
    {
        mlx->julia.re = pre_x;
        mlx->julia.im = pre_y;
    }
    if (code == 4)
        mlx->zoom *= 1.1;
    else if (code == 5)
        mlx->zoom *=0.9;
    aft_x = map_x(x, *mlx);
    aft_y = map_y(y, *mlx);
    mlx->central_x += pre_x - aft_x;
    mlx->central_y += pre_y - aft_y;
    mlx_clear_window(mlx->obj, mlx->win);
    print_fractol(*mlx);
    mlx_put_image_to_window(mlx->obj, mlx->win, mlx->img.image, 0, 0);
    return (0);
}
