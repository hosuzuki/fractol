#include "fractol.h"

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

static void	zoom_image(t_data *data, int button, int x, int y)
{
	double	mouse_re;
	double	mouse_im;
	double	interpolation;

	mouse_re = (double)x
		/ (WIDTH / (data->max_re - data->min_re)) + data->min_re;
	mouse_im = (double)y
		/ (HEIGHT / (data->max_im - data->min_im)) + data->min_im;
	if (button == SCROLL_UP)
	{
		if (data->max_iter > 4)
			data->max_iter -= 4;
		interpolation = 1.0 / 0.8;
	}
	else if (button == SCROLL_DOWN)
	{
		data->max_iter += 4;
		interpolation = 1.0 / 1.2;
	}
	data->min_re = interpolate(mouse_re, data->min_re, interpolation);
	data->min_im = interpolate(mouse_im, data->min_im, interpolation);
	data->max_re = interpolate(mouse_re, data->max_re, interpolation);
	data->max_im = interpolate(mouse_im, data->max_im, interpolation);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		zoom_image(data, button, x, y);
	return (0);
}
