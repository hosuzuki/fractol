/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 07:58:17 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/04/07 09:01:45 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = data->bpp - 8;
	pixel = data->addr + (y * data->line_len + x * (data->bpp / 8));
	while (i >= 0)
	{
		if (data->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (data->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

unsigned int	ft_pick_color(t_data *data)
{
	int		i;
	int		color;
	double	tmp_r;

	i = 0;
	while (pow(data->z_r, 2.0) + pow(data->z_i, 2.0) <= 4 && i < data->max_it)
	{
		tmp_r = pow(data->z_r, 2.0) - pow(data->z_i, 2.0) + data->c_r;
		data->z_i = 2 * data->z_r * data->z_i + data->c_i;
		data->z_r = tmp_r;
		i++;
	}
	if (i == data->max_it)
		color = ft_rgb_to_hex(255, 255, 255);
	else
		color = ft_gradation(data, (double)i
				/ (double)data->max_it, pow(data->z_r, 2.0));
	return (color);
}

int	ft_draw_mandelbrot(t_data *data)
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
			data->c_r = data->min_r + x * data->delta_r;
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
