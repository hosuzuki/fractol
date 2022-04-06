/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 07:58:16 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/04/07 08:01:22 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_draw_julia(t_data *data)
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
			data->z_i = data->min_i + y * data->delta_i;
			data->z_r = data->min_r + x * data->delta_r;
			ft_my_mlx_pixel_put(data, x, y, ft_pick_color(data));
			x++;
		}
		y++;
	}
	return (0);
}
