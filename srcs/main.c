#include "fractol.h"

void	ft_update_fractal(t_data *data)
{
	int		x;
	int		y;
	double	x_cp;
	double	y_cp;

	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
//	if (!x && !y)
	if (!x || !y)
		return ;
//	x_cp = (double)x / (WIDTH / (data->max_r - data->min_r)) + data->min_r;
//	y_cp = (double)y / (HEIGHT / (data->max_i - data->min_i)) * -1 + data->max_i;
	x_cp = ((data->max_r - data->min_r) * (double)x) / WIDTH + data->min_r;
	y_cp = ((data->max_i - data->min_i) * (double)y) / HEIGHT + data->min_i; // don't i need -1?
	data->c_r = x_cp;
	data->c_i = y_cp;
}

int	ft_render(t_data *data)
{
	if (data->shift_on && data->fract_type == JULIA)
		ft_update_fractal(data);
	if (data->fract_type == MANDELBROT)
		ft_draw_mandelbrot(data);
	else if (data->fract_type == JULIA)
		ft_draw_julia(data);
	else if (data->fract_type == BURNINGSHIP)
		ft_draw_burningship(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	select_fractal(t_data *data, char *str)
{
	if (!ft_strncmp(str, "mandelbrot", 11))
		data->fract_type = MANDELBROT;
	else if (!ft_strncmp(str, "julia", 6))
		data->fract_type = JULIA;
	else if (!ft_strncmp(str, "burningship", 12))
		data->fract_type = BURNINGSHIP;
	else
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || !select_fractal(&data, argv[1]))
	{
		ft_printf("Please input one of fractal types below after ./fractol\n");
		ft_printf("- mandelbrot\n");
		ft_printf("- julia\n");
		ft_printf("- burningship\n");
		return (1);
	}
	ft_init_data(&data);
	mlx_loop_hook(data.mlx, &ft_render, &data);
	mlx_hook(data.win, KEYDOWN, 1L<<0, ft_key_down_hook, &data);
	mlx_hook(data.win, KEYUP, 1L<<1, ft_key_up_hook, &data);
	mlx_hook(data.win, ClientMessage, 1L << 17, ft_destroy_win_and_exit, &data);
	mlx_mouse_hook(data.win, ft_mouse_hook, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img);
//	data.img = NULL;
	mlx_destroy_window(data.mlx, data.win);
//	data.win = NULL;
	mlx_destroy_display(data.mlx);
//	ft_free_all(&data);
	return (0);
}
