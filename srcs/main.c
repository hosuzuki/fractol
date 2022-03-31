#include "fractol.h"

void ft_free_all(t_data *data)
{
	if (data->mlx)
		free(data->mlx);
	if (data->win)
		free(data->win);
	if (data->img)
		free(data->img);
	if (data->addr)
		free(data->addr);
}

void ft_free_all_and_exit_with_perror(t_data *data)
{
	ft_free_all(data);
	perror("1");
	exit(1);
}

void	assign_null(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
}

void	init_data(t_data *data)
{
	assign_null(data);
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_free_all_and_exit_with_perror(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!data->win)
		ft_free_all_and_exit_with_perror(data);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		ft_free_all_and_exit_with_perror(data);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);
	data->is_pressed_shift = false;
	data->max_re = 1.7;
	data->max_im = 2;
	data->min_re = -2.3;
	data->min_im = -2;
	data->max_iter = DEFAULT_MAX_ITER;
	data->c_re = DEFAULT_JULIA_C_RE;
	data->c_im = DEFAULT_JULIA_C_IM;
}

int	select_fractal(t_data *data, char *str)
{
	if (!ft_strncmp(str, "mandelbrot", 11))
		data->fract_type = MANDELBROT;
//	else if (!ft_strncmp(str, "julia", 6))
//		data->fract_type = JULIA;
//	else if (!ft_strncmp(str, "burningship", 12))
//		data->fract_type = BURNINGSHIP;
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
		return (1);
	}
	init_data(&data);
	mlx_loop_hook(data.mlx, &main_loop, &data);

	mlx_hook(data.win, KEYDOWN, 1L<<0, key_down_hook, &data);
//	mlx_hook(data.win, KEYUP, 1L<<1, key_up_hook, &data);
//	mlx_hook(data.win, ClientMessage, 1L << 17, exit_and_destroy_win, &data); // ??

	mlx_mouse_hook(data.win, mouse_hook, &data);

	//	mlx_loop_hook(data.mlx, &render, &data);
//	mlx_mouse_hook(data.win, mouse_button, 0);
//	mlx_hook(data.win, 2, 1L<<0, key_hook, &data);
	mlx_loop(data.mlx);

	mlx_destroy_image(data.mlx, data.img);
	mlx_destroy_display(data.mlx);
	ft_free_all(&data);
}
