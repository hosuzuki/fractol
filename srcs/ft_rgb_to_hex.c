#include "fractol.h"

//uint32_t	ft_rgb_to_hex(int r, int g, int b)
unsigned int	ft_rgb_to_hex(int r, int g, int b)
{
//	uint32_t	color;
	unsigned int	color;

	color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}

unsigned int ft_gradation(t_data *data, double i)
{
	if	(data->color_theme == YELLOW)
	{
		if (0.5 < i)
			return (ft_rgb_to_hex(i * 255.0, i * 255.0, 0));
		else 
			return (ft_rgb_to_hex(i * 255.0, 0, 0));
	}
	else if 	(data->color_theme == RED)
	{
		if (0.5 < i)
			return (ft_rgb_to_hex(i * 255.0, 0, 0));
		else 
		return (ft_rgb_to_hex(0, i * 255.0, 0));
	}
	else
	{
		if (0.5 < i)
			return (ft_rgb_to_hex(0, i * 255.0, 0));
		else
			return (ft_rgb_to_hex(i * 255.0, i * 255.0, 0));
	}
		//	else 
//		return (ft_rgb_to_hex(0, 0, i * 255.0));
}


/*
 	(void)pow;
	if (pow < 5)
	{
		return (ft_rgb_to_hex(i * 255.0, i * 255.0, 0));
	else if (pow < 7)
		return (ft_rgb_to_hex(0, i * 255.0, 0));
	else
		return (ft_rgb_to_hex(i * 255.0, 0, 0));
}

*/
/*double	ft_abs(double val)
{
	if (val < 0)
		return (-val);
	return (val);
}
*/
/*
 * h: Hue.  [0-360]
 * s: Saturation(Chroma) [0-1]
 * v: Value(Brightness) [0-1]
//uint32_t	ft_hsv_to_hex(double h, double s, double v)
*/

unsigned int	ft_hsv_to_hex(double h, double s, double v)
{
	double	c;
	double	x;
	double	m;

	c = v * s;
	x = c * (1 - abs(((int)h / 60 % 2) - 1));
	m = v - c;
	if (s == 0)
		return (ft_rgb_to_hex((v + m) * 255, (v + m) * 255, (v + m) * 255));
	if (h >= 300)
		return (ft_rgb_to_hex((c + m) * 255, (0 + m) * 255, (x + m) * 255));
	else if (h >= 240)
		return (ft_rgb_to_hex((x + m) * 255, (0 + m) * 255, (c + m) * 255));
	else if (h >= 180)
		return (ft_rgb_to_hex((0 + m) * 255, (x + m) * 255, (c + m) * 255));
	else if (h >= 120)
		return (ft_rgb_to_hex((0 + m) * 255, (c + m) * 255, (x + m) * 255));
	else if (h >= 60)
		return (ft_rgb_to_hex((x + m) * 255, (c + m) * 255, (0 + m) * 255));
	else if (h >= 0)
		return (ft_rgb_to_hex((c + m) * 255, (x + m) * 255, (0 + m) * 255));
	else
		return (ft_rgb_to_hex((0 + m) * 255, (0 + m) * 255, (0 + m) * 255));
}


/*
 int rgb_to_int(double r, double g, double b)
{
	int color;

	color = 0;
	color |= (int)(b * 255); // 255 = 1111 1111
	color |= (int)(g * 255) << 8; // |= means results of | will be affected to the one in the left. in this case color.
	color |= (int)(r * 255) << 16;
	return (color);
}

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int get_b(int trgb)
{
	return (trgb & 0xFF);
}

int create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]{b, g, r t});
}

*/
