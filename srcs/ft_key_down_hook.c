#include "fractol.h"

static void	ft_move_win(int keysym, t_data *data)
{
	//if (data->max_r <= 0 || data->max_i <= 0)
//		return ;
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
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	exit (0);
}

int	ft_key_up_hook(int keysym, t_data *data)
{
	if (keysym == KEY_SHIFT)
		data->shift_on = false;
	return (0);
}

static void ft_change_color(t_data *data)
{
	if 	(data->color_theme == YELLOW)
		data->color_theme = RED;
	else if 	(data->color_theme == RED)
		data->color_theme = GREEN;
	else if 	(data->color_theme == GREEN)
		data->color_theme = YELLOW;
//	else if 	(data->color_theme == BLUE)
//		data->color_theme = YELLOW;
}

int	ft_key_down_hook(int keysym, t_data *data)
{
	if (keysym == KEY_SHIFT)
		data->shift_on = true;
	if (keysym == KEY_UP_ARROW || keysym == KEY_DW_ARROW
		|| keysym == KEY_L_ARROW || keysym == KEY_R_ARROW)
		ft_move_win(keysym, data);
//	printf("%d\n", keysym);
	if (keysym == KEY_ALT)
		ft_change_color(data);
	if (keysym == KEY_ESC)
		ft_destroy_win_and_exit(data);
	return (0);
}

