#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

# include <math.h>
# include <stdio.h>

# define WIDTH 1200
# define HEIGHT 1200
# define DEFAULT_MAX_ITER 100
# define DEFAULT_JULIA_C_RE 0.4
# define DEFAULT_JULIA_C_IM -0.325

# define MOVE_RATIO 0.02

# define RED_PIXEL 0x00FF0000
# define GREEN_PIXEL 0x0000FF00
# define BLUE_PIXEL 0x000000FF
# define WHITE_PIXEL 0x00FFFFFF

# define KEY_Q 113
# define KEY_ESC 65307
# define KEY_SHIFT 65505
# define KEY_L_ARROW 65361
# define KEY_UP_ARROW 65362
# define KEY_R_ARROW 65363
# define KEY_DW_ARROW 65364
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define MOUSE_RIGHT 1
# define MOUSE_CENTER 2
# define MOUSE_LEFT 3

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
//	int		cur_img;
	char	*addr;
	int	fract_type;
	int	bpp;
	int	line_len;
	int	endian;
	int			width;
	int			height;
	bool				is_pressed_shift;
	double				max_re;
	double				max_im;
	double				min_re;
	double				min_im;
	int					max_iter;
	double				c_re;
	double				c_im;
	double				z_re; //
	double				z_im;
	double				delta_re;
	double				delta_im;
}	t_data;

//typedef int				(*t_fractal_drawer)(t_canvas *canvas);

//typedef struct	s_math 
//	t_fractal_drawer	fractal_drawer;
//} t_math;

enum e_fractal_type {
	JULIA,
	MANDELBROT,
	BURNINGSHIP,
};

enum e_input_type {
	KEYDOWN = 2,
	KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ClientMessage = 33,
};

int	key_down_hook(int keysym, t_data *data);
int	key_up_hook(int keysym, t_data *data);
int	mouse_hook(int button, int x, int y, t_data *data);
int	main_loop(t_data *data);
int	draw_mandelbrot(t_data *data);
int	exit_and_destroy_win(t_data *data);
uint32_t	rgb2hex(int r, int g, int b);
uint32_t	hsv2hex(double h, double s, double v);

#endif
