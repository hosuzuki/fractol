/*
#include "fractol.h"
 * Draw the Julia set.
 * The Julia set is the set that does not diverge when z_n = z_(n-1) + C.
 * C is a complex constant (the same number is used for all pixels).
 * Z_0 is the position of the pixel to be drawn.
 *
 * If divergence occurs, it is filled with black.

int	ft_draw_julia(t_data *data)
{
	int	x;
	int	y;

	data->delta_r = (data->max_r - data->min_r) / (WIDTH - 1);
	data->delta_i = (data->max_i - data->min_i) / (HEIGHT - 1);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->z_i = data->min_i + y * data->delta_i;
			data->z_r = data->min_r + x * data->delta_r;
			ft_my_mlx_pixel_put(&data->img, x, y, ft_pick_color(data));
			x++;
		}
		y++;
	}
	return (0);
}
*/
