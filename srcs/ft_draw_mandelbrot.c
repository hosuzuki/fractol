#include "fractol.h"

void	ft_my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = data->bpp - 8;
    pixel = data->addr + (y * data->line_len + x * (data->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (data->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (data->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len
			+ x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
*/

/*
//uint32_t	ft_get_color(t_data data, int x, int y)
unsigned int	ft_get_color(t_data data, int x, int y)
{
	return (*(uint32_t *)(data.addr
		+ (y * data.line_len + x * (data.bpp / 8))));
}
*/

//uint32_t	ft_pick_color(t_data *data)
unsigned int	ft_pick_color(t_data *data)
{
	int		i;
	int		color;
	double	tmp_r;

	i = 0;
	while (pow(data->z_r, 2.0) + pow(data->z_i, 2.0) <= 4 && i < MAX_ITER)
//	while (pow(data->z_r, 2.0) + pow(data->z_i, 2.0) <= 4 && i < data->max_iter)

	{
		tmp_r = pow(data->z_r, 2.0) - pow(data->z_i, 2.0) + data->c_r;
 //   (a + bj)^2 = a^2 + 2abj - b^2
		// a^2 - b^2 in this part. 
		data->z_i = 2 * data->z_r * data->z_i + data->c_i;
		// 2abj in this part.
		data->z_r = tmp_r;
		i++;
	}
//	if (i == data->max_iter)
	if (i == MAX_ITER)
		color = ft_rgb_to_hex(255, 26, 186);
	else
		color = ft_gradation((double)i / (double)MAX_ITER, pow(data->z_r, 2.0));
//		color = ft_gradation((double)i / data->max_iter, pow(data->z_r, 2.0));
		//		color = ft_hsv_to_hex(i % 360, (double)i / MAX_ITER, ((double)i / MAX_ITER));
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
int	ft_draw_mandelbrot(t_data *data)
{
	int	x;
	int	y;

	data->delta_r = (data->max_r - data->min_r) / (double)WIDTH;
	data->delta_i = (data->max_i - data->min_i) / (double)HEIGHT;
//	data->delta_r = (data->max_r - data->min_r) / (WIDTH - 1);
//	data->delta_i = (data->max_i - data->min_i) / (HEIGHT - 1);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->c_r = data->min_r + x * data->delta_r;
			//from left top on the width, but in min-max scale;
			data->c_i = data->min_i + y * data->delta_i;
			data->z_r = 0;
			data->z_i = 0;
			ft_my_mlx_pixel_put(data, x, y, ft_pick_color(data));
			x++;
		}
		y++;
	}
	return (0);
}
