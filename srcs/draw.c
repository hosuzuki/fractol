#include "fractol.h"

/*
void	update_fractal(t_data *data)
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

int	main_loop(t_data *data)
{
//	if (data->is_pressed_shift)
//		update_fractal(data);
	if (data->fract_type == MANDELBROT)
		draw_mandelbrot(data);
//	else if (data->fract_type == JULIA)
//		draw_julia(data);
//	else if (data->fract_type == BURNINGSHIP)
//		draw_burningship(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
