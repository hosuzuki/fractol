#include "fractol.h"

/*
static double	ft_intrpl(double start, double end, double itp)
{
	return (start + ((end - start) * itp));
}
*/


static void ft_translation(t_data *data)
{
	

static void ft_scale(t_data *data)
{
	


static void	ft_zoom_image(t_data *data, int button, double x, double y)
{
	double	x_cp;
	double	y_cp;

	x_cp = ((data->max_r - data->min_r) * x) / WIDTH + data->min_r;
	y_cp = ((data->max_i - data->min_i) * y) / HEIGHT + data->min_i; 
	if (button == SCROLL_DOWN)
	{
		data->min_i = (data->min_i - x_cp) / ZOOM_IN_RATIO;
		data->max_i = (data->max_i - x_cp) / ZOOM_IN_RATIO;
		data->min_r = (data->min_i - x_cp) / ZOOM_IN_RATIO;
		data->max_r = (data->max_i - x_cp) / ZOOM_IN_RATIO;
	}
	else
	{
		data->min_i = (data->min_i - x_cp) / ZOOM_OUT_RATIO;
		data->max_i = (data->max_i - x_cp) / ZOOM_OUT_RATIO;
		data->min_r = (data->min_i - x_cp) / ZOOM_OUT_RATIO;
		data->max_r = (data->max_i - x_cp) / ZOOM_OUT_RATIO;
	}
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
//	ft_printf("button: %d\n", button);
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		ft_zoom_image(data, button, (double)x, (double)y);
	return (0);
}
