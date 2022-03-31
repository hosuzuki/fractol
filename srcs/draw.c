#include "fractol.h"

void	update_fractal_c(t_canvas *canvas)
{
	int		x;
	int		y;
	double	mouse_re;
	double	mouse_im;

	mlx_mouse_get_pos(canvas->mlx, canvas->win, &x, &y);
	if (!x && !y)
		return ;
	mouse_re = (double)x
		/ (WIDTH / (canvas->max_re - canvas->min_re)) + canvas->min_re;
	mouse_im = (double)y
		/ (HEIGHT / (canvas->max_im - canvas->min_im)) * -1 + canvas->max_im;
	canvas->c_re = mouse_re;
	canvas->c_im = mouse_im;
}

int	main_loop(t_data *data)
{
	if (data->is_pressed_shift)
		update_fractal(data);
	if (data->fract_type == MANDELBROT)
		draw_mandelbrot(data);
//	else if (data->fract_type == JULIA)
//		draw_julia(data);
//	else if (data->fract_type == BURNINGSHIP)
//		draw_burningship(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

