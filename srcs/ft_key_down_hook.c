#include "fractol.h"

void	ft_move_arrow_key(int keysym, t_data *data)
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

int	ft_destroy_win_and_exit(t_data *data)
{
//	mlx_destroy_image(data.mlx, data.img);
	mlx_destroy_window(data->mlx, data->win);
//	mlx_destroy_display(data.mlx);
	exit(0);
}

int	ft_key_up_hook(int keysym, t_data *data)
{
	if (keysym == KEY_SHIFT)
		data->shift_on = false;
	return (0);
}

int	ft_key_down_hook(int keysym, t_data *data)
{
	if (keysym == KEY_ESC)
		ft_destroy_win_and_exit(data);
	if (keysym == KEY_SHIFT)
		data->shift_on = true;
	if (keysym == KEY_UP_ARROW || keysym == KEY_DW_ARROW
		|| keysym == KEY_L_ARROW || keysym == KEY_R_ARROW)
		ft_move_arrow_key(keysym, data);
	return (0);
}

