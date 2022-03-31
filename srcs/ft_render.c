#include "fractol.h"

/*
void	ft_update_fractal(t_data *data)
{
	int		x;
	int		y;
//	double	mouse_re;
//	double	mouse_im;

	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	if (!x && !y)
		return ;
//	mouse_re = (double)x
	data->c_re = (double)x
	/ (WIDTH / (data->max_re - data->min_re)) + data->min_re;
//	mouse_im = (double)y
	data->c_im = (double)y
	/ (HEIGHT / (data->max_im - data->min_im)) * -1 + data->max_im;
//	data->c_re = mouse_re;
//	data->c_im = mouse_im;
}

*/

int	ft_render(t_data *data)
{
//	if (data->shift_on)
//	{
//		printf("update_fractal\n");
//		ft_update_fractal(data);
	if (data->fract_type == MANDELBROT)
		draw_mandelbrot(data);
//	else if (data->fract_type == JULIA)
//		draw_julia(data);
//	else if (data->fract_type == BURNINGSHIP)
//		draw_burningship(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
