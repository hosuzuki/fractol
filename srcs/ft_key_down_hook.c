/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_down_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 07:58:17 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/04/07 08:33:29 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_move_win(int keysym, t_data *data)
{
	if (keysym == KEY_UP_ARROW)
	{
		data->min_i -= (data->max_i - data->min_i) * MOVE_RATIO;
		data->max_i -= (data->max_i - data->min_i) * MOVE_RATIO;
	}
	if (keysym == KEY_DW_ARROW)
	{
		data->min_i += (data->max_i - data->min_i) * MOVE_RATIO;
		data->max_i += (data->max_i - data->min_i) * MOVE_RATIO;
	}
	if (keysym == KEY_R_ARROW)
	{
		data->min_r += (data->max_r - data->min_r) * MOVE_RATIO;
		data->max_r += (data->max_r - data->min_r) * MOVE_RATIO;
	}
	if (keysym == KEY_L_ARROW)
	{
		data->min_r -= (data->max_r - data->min_r) * MOVE_RATIO;
		data->max_r -= (data->max_r - data->min_r) * MOVE_RATIO;
	}
}

static int	ft_key_up_hook(int keysym, t_data *data)
{
	if (keysym == KEY_SHIFT)
		data->shift_on = false;
	return (0);
}

static void	ft_change_color(t_data *data)
{
	if (data->color_theme == YELLOW)
		data->color_theme = RED;
	else if (data->color_theme == RED)
		data->color_theme = GREEN;
	else if (data->color_theme == GREEN)
		data->color_theme = YELLOW;
}

int	ft_key_down_hook(int keysym, t_data *data)
{
	if (keysym == KEY_SHIFT)
		data->shift_on = true;
	else if (keysym == KEY_UP_ARROW || keysym == KEY_DW_ARROW
		|| keysym == KEY_L_ARROW || keysym == KEY_R_ARROW)
		ft_move_win(keysym, data);
	else if (keysym == KEY_ALT)
		ft_change_color(data);
	else if (keysym == KEY_ESC)
	{
		ft_destroy_all(data);
		exit (0);
	}
	return (0);
}
