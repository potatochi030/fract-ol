#include "fractol.h"
int     is_double(char *str)
{
    int     i;
    int     dot;

    i = 0;
    if (!str || !str[i])
        return (0);
    while (str[i] == ' ' || str[i] == '\t')
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
double      convert_double(char *str)
{
    double  perc;
    double  dev;
    int     i;
    int     sign;

    i = 0;
    dev = 1;
    perc = 0.0;
    sign = 1;
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
int     close_mlx(t_mlx *mlx)
{
    if (mlx->image.img)
        mlx_distroy_image(mlx->obj, mlx->image.img);
    if (mlx->win)
        mlx_destroy_window(mlx->obj, mlx->win);
    if (mlx->obj)
    {
        mlx_destroy_display(mlx->obj);
        free(mlx->obj);
    }
    exit(0);
}
