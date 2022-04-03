#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

# include <math.h>
# include <stdio.h>

# define WIDTH 300
# define HEIGHT 300
//# define DEFAULT_MAX_ITER 100
# define MAX_ITER 100
# define DEFAULT_JULIA_C_R -1
# define DEFAULT_JULIA_C_I -0.325

# define MOVE_RATIO 0.02
# define ZOOM_IN_RATIO 0.8
# define ZOOM_OUT_RATIO 1.2

# define RED_PIXEL 0x00FF0000
# define GREEN_PIXEL 0x0000FF00
# define BLUE_PIXEL 0x000000FF
# define WHITE_PIXEL 0x00FFFFFF

//# define KEY_Q 113
# define KEY_ESC 65307
# define KEY_SHIFT 65505
# define KEY_L_ARROW 65361
# define KEY_UP_ARROW 65362
# define KEY_R_ARROW 65363
# define KEY_DW_ARROW 65364
# define SCROLL_UP 5
# define SCROLL_DOWN 4

/*#define MOUSE_RIGHT 1
# define MOUSE_CENTER 2
# define MOUSE_LEFT 3
*/

typedef struct s_data
{
	int	fract_type;
	void	*mlx;
	void	*win;
	void	*img;
//	int		cur_img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
//	int			width;
//	int			height;
	bool				shift_on;
	double				max_r;
	double				min_r;
	double				max_i;
	double				min_i;
//	int					max_iter; //do I need this?
	double				c_r;
	double				c_i;
	double				z_r; 
	double				z_i;
	double				delta_r;
	double				delta_i;
}	t_data;

enum e_fractal_type {
	MANDELBROT,
	JULIA,
	BURNINGSHIP,
};

enum e_input_type {
	KEYDOWN = 2,
	KEYUP = 3,
//	ON_MOUSEDOWN = 4,
//	ON_MOUSEUP = 5,
//	ON_MOUSEMOVE = 6,
//	ON_EXPOSE = 12,
//	ON_DESTROY = 17,
	ClientMessage = 33,
};

// ft_init_data.c
void	ft_init_data(t_data *data);

// ft_draw_mandelbrot.c
void	ft_my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	ft_draw_mandelbrot(t_data *data);
unsigned int	ft_pick_color(t_data *data);
//uint32_t	ft_pick_color(t_data *data);

// ft_draw_julia.c
int	ft_draw_julia(t_data *data);

// ft_rgb_to_hex.c
double	ft_abs_double(double val);
unsigned int	ft_hsv_to_hex(double h, double s, double v);
unsigned int	ft_rgb_to_hex(int r, int g, int b);
//uint32_t	rgb2hex(int r, int g, int b);
//uint32_t	hsv2hex(double h, double s, double v);

// ft_key_down_hook.c
int	ft_destroy_win_and_exit(t_data *data);
int	ft_key_down_hook(int keysym, t_data *data);
int	ft_key_up_hook(int keysym, t_data *data);

// ft_mouse_hook.c
int	ft_mouse_hook(int button, int x, int y, t_data *data);

// ft_draw_burnigship_bonus.c
int	ft_draw_burningship(t_data *data);


#endif
