#include "fractol.h"

/*
static double	ft_intrpl(double start, double end, double itp)
{
	return (start + ((end - start) * itp));
}
*/

static void ft_translation_back(t_data *data, double x_cp, double y_cp)
{
	data->min_r = data->min_r + x_cp;
	data->max_r = data->max_r + x_cp;
	data->min_i = data->min_i + y_cp;
	data->max_i = data->max_i + y_cp;
}

static void ft_translation_to_zero(t_data *data, double x_cp, double y_cp)
{
	data->min_r = data->min_r - x_cp;
	data->max_r = data->max_r - x_cp;
	data->min_i = data->min_i - y_cp;
	data->max_i = data->max_i - y_cp;
}

static void ft_scale(t_data *data, double ratio)
{
	data->min_r = data->min_r * ratio;
	data->max_r = data->max_r * ratio;
	data->min_i = data->min_i * ratio;
	data->max_i = data->max_i * ratio;
}


/*
static void	ft_zoom_image(t_data *data, int button, double x, double y)
{
	double	x_cp;
	double	y_cp;
	double	itp;

//	itp = 0.0;
//	x_cp = x	/ (WIDTH / (data->max_r - data->min_r)) + data->min_r;
	// get x in 2 x 2 complex plane
//	y_cp = y	/ (HEIGHT / (data->max_i - data->min_i)) + data->min_i;
	x_cp = ((data->max_r - data->min_r) * x) / WIDTH + data->min_r;
	y_cp = ((data->max_i - data->min_i) * y) / HEIGHT + data->min_i; 
	if (button == SCROLL_UP)
	{
//		if (data->max_iter > 4)
//			data->max_iter -= 4;
		itp = 1.0 / 0.8;
	}
//	else if (button == SCROLL_DOWN)
	else
	{
//		data->max_iter += 4;
		itp = 1.0 / 1.2;
	}
	data->min_r = ft_intrpl(x_cp, data->min_r, itp);
	data->min_i = ft_intrpl(y_cp, data->min_i, itp);
	data->max_r = ft_intrpl(x_cp, data->max_r, itp);
	data->max_i = ft_intrpl(y_cp, data->max_i, itp);
}
*/

int	ft_mouse_hook(int button, int x, int y, t_data *data)
{
	double	x_cp;
	double	y_cp;
//	ft_printf("button: %d\n", button);
	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		x_cp = ((data->max_r - data->min_r) * (double)x) / (double)WIDTH + data->min_r;
		y_cp = ((data->max_i - data->min_i) * (double)y) / (double)HEIGHT + data->min_i; 
		ft_translation_to_zero(data, x_cp, y_cp);
		if (button == SCROLL_UP)
//		{
//			if (data->max_iter > 4)
//				data->max_iter -= 4;
			ft_scale(data, ZOOM_IN_RATIO);
//		}
		else
//		{
			ft_scale(data, ZOOM_OUT_RATIO);
//			data->max_iter += 4;
//		}
		ft_translation_back(data, x_cp, y_cp);
	}
	return (0);
}
