#include "fractol.h"

int	ft_draw_julia(t_data *data)
{
	int	x;
	int	y;

	data->delta_r = (data->max_r - data->min_r) / (long double)WIDTH;
	data->delta_i = (data->max_i - data->min_i) /(long double)HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->z_i = data->min_i + y * data->delta_i;
			data->z_r = data->min_r + x * data->delta_r;
			ft_my_mlx_pixel_put(data, x, y, ft_pick_color(data));
			x++;
		}
		y++;
	}
	return (0);
}
