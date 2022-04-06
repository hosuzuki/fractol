#include "fractol_bonus.h"



static unsigned int	ft_pick_color_bs(t_data *data)
//static uint32_t	get_color_in_burningship(t_data *data)
{
	int		i;
	int		color;
	double	tmp_r;

	i = 0;
//	while (pow(data->z_r, 2.0) + pow(data->z_i, 2.0)  <= 4 && i < data->max_iter)
	while (pow(data->z_r, 2.0) + pow(data->z_i, 2.0)  <= 4 && i < data->max_it)
	{
		tmp_r = pow(data->z_r, 2.0) - pow(data->z_i, 2.0)  + data->c_r;
		data->z_i = fabs(2 * (double)data->z_r * (double)data->z_i) + data->c_i;
		data->z_r = tmp_r;
		i++;
	}
//	if (i == data->max_iter)
	if (i == data->max_it)
		color = ft_rgb_to_hex(0, 0, 0);
	else
		color = ft_gradation(data, (double)i / (double)data->max_it);
//		color = ft_gradation((double)i / data->max_iter, pow(data->z_r, 2.0));
//		color = ft_hsv_to_hex(i % 360, (double)i / MAX_ITER, ((double)i / MAX_ITER));
//		color = ft_hsv_to_hex(i % 360, (double)i / data->max_iter, ((double)i / data->max_iter));
	return (color);
}

/*
 * Draw the burningship set.
 * A burning ship set is a set that does not diverge when z_n = z_(n-1) + C.
 * C is the position of the pixel to be drawn.
 * Z_0 should be set to 0
 *
 * If divergent, fill with black.
 *
 * Z_(n+1) = (abs(z_re) + abs(z_im)j) ^ 2 + C
 *   (Z is an expression for a complex number)
 *
 * The difference from the Mandelbrot set is that
 *   in barningship we take absolute values in sequences of iterations.
 */
int	ft_draw_burningship(t_data *data)
{
	int	x;
	int	y;

	data->delta_r = (data->max_r - data->min_r) / (double)WIDTH;
	data->delta_i = (data->max_i - data->min_i) / (double)HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->c_i = data->min_i + y * data->delta_i;
			data->c_r = data->min_r + x * data->delta_r;
			data->z_r = 0;
			data->z_i = 0;
			ft_my_mlx_pixel_put(data, x, y, ft_pick_color_bs(data));
			x++;
		}
		y++;
	}
	return (0);
}
