#include "fractol.h"

void	ft_move_arrow_key(int keysym, t_data *data)
{
	if (keysym == KEY_UP_ARROW)
	{
		data->min_im -= (data->max_im - data->min_im) * MOVE_RATIO;
		data->max_im -= (data->max_im - data->min_im) * MOVE_RATIO;
	}
	if (keysym == KEY_DW_ARROW)
	{
		data->min_im += (data->max_im - data->min_im) * MOVE_RATIO;
		data->max_im += (data->max_im - data->min_im) * MOVE_RATIO;
	}
	if (keysym == KEY_R_ARROW)
	{
		data->min_re += (data->max_re - data->min_re) * MOVE_RATIO;
		data->max_re += (data->max_re - data->min_re) * MOVE_RATIO;
	}
	if (keysym == KEY_L_ARROW)
	{
		data->min_re -= (data->max_re - data->min_re) * MOVE_RATIO;
		data->max_re -= (data->max_re - data->min_re) * MOVE_RATIO;
	}
}

int	ft_destroy_win_and_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	ft_key_up_hook(int keysym, t_data *data)
{
	ft_printf("keysym: %d\n", keysym);
	if (keysym == KEY_SHIFT)
		data->shift_on = false;
	return (0);
}

int	ft_key_down_hook(int keysym, t_data *data)
{
	ft_printf("keysym: %d\n", keysym);
	if (keysym == KEY_ESC)
		ft_destroy_win_and_exit(data);
	if (keysym == KEY_SHIFT)
		data->shift_on = true;
	if (keysym == KEY_UP_ARROW || keysym == KEY_DW_ARROW
		|| keysym == KEY_L_ARROW || keysym == KEY_R_ARROW)
		ft_move_arrow_key(keysym, data);
	return (0);
}

