/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 07:58:18 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/04/07 08:22:27 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	ft_rgb_to_hex(int r, int g, int b)
{
	unsigned int	color;

	color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}

unsigned int	ft_gradation(t_data *data, double i, double z_r)
{
	if (data->color_theme == YELLOW)
	{
		if (z_r < 5)
			return (ft_rgb_to_hex(i * 255.0, i * 255.0, 0));
		else
			return (ft_rgb_to_hex(i * 127.5, 0, i * 255.0));
	}
	else if (data->color_theme == RED)
	{
		if (z_r < 5)
			return (ft_rgb_to_hex(i * 255.0, 0, 0));
		else
			return (ft_rgb_to_hex(0, i * 255.0, 0));
	}
	else
	{
		if (z_r < 5)
			return (ft_rgb_to_hex(0, i * 255.0, 0));
		else
			return (ft_rgb_to_hex(0, i * 255.0, i * 255.0));
	}
}
