/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 07:58:17 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/04/07 11:35:25 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_free_all(t_data *data)
{
	if (data->mlx)
		free(data->mlx);
	if (data->win)
		free(data->win);
}

static void	ft_free_all_and_exit_with_perror(t_data *data)
{
	ft_free_all(data);
	perror("ERROR");
	exit(1);
}

static void	ft_assign_null(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
}

static void	ft_put_defaults(t_data *data)
{
	if (data->fract_type == MANDELBROT)
	{
		data->max_r = 1.5;
		data->min_r = -2.5;
	}
	else
	{
		data->max_r = 2;
		data->min_r = -2;
	}
	data->max_i = 2;
	data->min_i = -2;
	data->max_it = DEFAULT_MAX_ITER;
	data->c_r = DEFAULT_JULIA_C_R;
	data->c_i = DEFAULT_JULIA_C_I;
	data->color_theme = YELLOW;
}

void	ft_init_data(t_data *data)
{
	ft_assign_null(data);
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_free_all_and_exit_with_perror(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!data->win)
		ft_free_all_and_exit_with_perror(data);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		ft_free_all_and_exit_with_perror(data);
	data->addr = mlx_get_data_addr(data->img,
			&data->bpp, &data->line_len, &data->endian);
	data->shift_on = false;
	ft_put_defaults(data);
}
