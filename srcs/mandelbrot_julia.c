#include "fractol.h"

static uint32_t	get_color_in_fractal(t_data *data)
{
	int		iteration;
	int		color;
	double	tmp_x;

	iteration = 0;
	while (data->z_re * data->z_re + data->z_im * data->z_im <= 4
		&& iteration < data->max_iter)
	{
		tmp_x = data->z_re * data->z_re
			- data->z_im * data->z_im + data->c_re;
		data->z_im = 2 * data->z_re * data->z_im + data->c_im;
		data->z_re = tmp_x;
		iteration++;
	}
	if (iteration == data->max_iter)
		color = rgb2hex(0, 0, 0);
	else
		color = hsv2hex(iteration % 360, (double)iteration / data->max_iter,
				((double)iteration / data->max_iter));
	return (color);
}

/*
 * Draw the Mandelbrot set.
 * A Mandelbrot set is a set that does not diverge when z_n = z_(n-1) + C.
 * C is the position of the pixel to be drawn.
 * Z_0 should be set to 0.
 *
 * If divergence occurs, fill with black
 *
 * Memo:
 *   Z_(n+1) = Z_n ^ 2 + C (Z is an expression for a complex number)
 *   (a + bj)^2 = a^2 + 2abj - b^2
*/
int	draw_mandelbrot(t_data *data)
{
	int	x;
	int	y;

	data->delta_re = (data->max_re - data->min_re) / (WIDTH - 1);
	data->delta_im = (data->max_im - data->min_im) / (HEIGHT - 1);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->c_im = data->min_im + y * data->delta_im;
			data->c_re = data->min_re + x * data->delta_re;
			data->z_re = 0;
			data->z_im = 0;
			my_mlx_pixel_put(&data->img, x, y,
				get_color_in_fractal(data));
			x++;
		}
		y++;
	}
	return (0);
}

/*
 * Draw the Julia set.
 * The Julia set is the set that does not diverge when z_n = z_(n-1) + C.
 * C is a complex constant (the same number is used for all pixels).
 * Z_0 is the position of the pixel to be drawn.
 *
 * If divergence occurs, it is filled with black.
 */
int	draw_julia(t_data *data)
{
	int	x;
	int	y;

	data->delta_re = (data->max_re - data->min_re) / (WIDTH - 1);
	data->delta_im = (data->max_im - data->min_im) / (HEIGHT - 1);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->z_im = data->min_im + y * data->delta_im;
			data->z_re = data->min_re + x * data->delta_re;
			my_mlx_pixel_put(&data->img, x, y,
				get_color_in_fractal(data));
			x++;
		}
		y++;
	}
	return (0);
}
