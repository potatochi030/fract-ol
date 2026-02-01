#include "fractol.h"

int     handle_esc(int keycode, t_mlx *mlx)
{
    if (keycode == 65307)
        close_mlx(mlx);
    return (0);
}

// int     handle_zoom(int code, int x, int y, t_mlx mlx)
// {
//     int     nx;
//     int     ny;

    

// }