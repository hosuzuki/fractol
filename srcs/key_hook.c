#include "fractol.h"

void	move_arrow_key(int keysym, t_data *data)
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

int	exit_and_destroy_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	key_press_hook(int keysym, t_data *data)
{
	ft_printf("keysym: %d\n", keysym);
	if (keysym == KEY_ESC)
		exit_and_destroy_win(data);
	if (keysym == KEY_SHIFT)
		data->is_pressed_shift = true;
	if (keysym == KEY_UP_ARROW || keysym == KEY_DW_ARROW
		|| keysym == KEY_L_ARROW || keysym == KEY_R_ARROW)
		move_arrow_key(keysym, data);
	return (0);
}

int	key_release_hook(int keysym, t_data *data)
{
	ft_printf("keysym: %d\n", keysym);
	if (keysym == KEY_SHIFT)
		data->is_pressed_shift = false;
	return (0);
}
