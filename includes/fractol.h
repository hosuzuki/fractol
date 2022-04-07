/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 07:56:46 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/04/07 14:23:34 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

# include <math.h>
# include <stdio.h>

# define WIDTH 300
# define HEIGHT 300
# define DEFAULT_MAX_ITER 100
# define DEFAULT_JULIA_C_R -0.74667
# define DEFAULT_JULIA_C_I 0.186667

# define MOVE_RATIO 0.02
# define ZOOM_IN_RATIO 0.8
# define ZOOM_OUT_RATIO 1.2

# define YELLOW 0
# define RED 1
# define GREEN 2

# define KEY_ESC 65307
# define KEY_SHIFT 65505
# define KEY_L_ARROW 65361
# define KEY_UP_ARROW 65362
# define KEY_R_ARROW 65363
# define KEY_DW_ARROW 65364
# define KEY_ALT 65406
# define KEY_ALT_X 65513
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_data
{
	int		fract_type;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	bool	shift_on;
	double	max_r;
	double	min_r;
	double	max_i;
	double	min_i;
	int		max_it;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	delta_r;
	double	delta_i;
	int		color_theme;
}	t_data;

enum e_fractal_type {
	MANDELBROT,
	JULIA,
	BURNINGSHIP,
};

enum e_input_type {
	KEYDOWN = 2,
	KEYUP = 3,
	ClientMessage = 33,
};

// ft_init_data.c
void			ft_init_data(t_data *data);

// ft_draw_mandelbrot.c
void			ft_my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				ft_draw_mandelbrot(t_data *data);
unsigned int	ft_pick_color(t_data *data);

// ft_draw_julia.c
int				ft_draw_julia(t_data *data);

// ft_rgb_to_hex.c
unsigned int	ft_rgb_to_hex(int r, int g, int b);
unsigned int	ft_gradation(t_data *data, double i, double z_r);

// ft_key_down_hook.c
int				ft_key_up_hook(int keysym, t_data *data);
int				ft_key_down_hook(int keysym, t_data *data);

// ft_mouse_hook.c
int				ft_mouse_hook(int button, int x, int y, t_data *data);

// ft_destroy.c
void			ft_destroy_all(t_data *data);
int			ft_destroy_all_and_exit(t_data *data);

#endif
