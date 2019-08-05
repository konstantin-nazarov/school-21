__kernel void	pixel_mandelbrot(__global t_fractal *fractal, __global char win, __global int *img)
{
	printf("t\n");
	int x = fractal->win_w % get_global_id(0);
	int y = fractal->win_w / get_global_id(0);
	float	cx;
	float	cy;
	float	temp;
	int		i;

	win = 0;
	i = -1;
	cx = (x / fractal->block_w - fractal->sx) * fractal->size - fractal->dx;
	cy = (fractal->sy - y / fractal->block_h) * fractal->size + fractal->dy;
	x = 0;
	y = 0;
	while ((temp = x * x + y * y) <= 4 && ++i < fractal->it)
	{
		temp = x * x - y * y + cx;
		y = 2 * x * y + cy;
		x = temp;
	}
	if (temp > 4)
		img[y * fractal->win_w + x] = i * 256;
		// img[y * fractal->win_w + x] = color(fractal, (i < 1) ? 1 : i);
	img[y * fractal->win_w + x] = 0x99FF99;

}

__kernel void	rot13( __global const char* in, __global char* out)
{
	const uint index = get_global_id(0);
	char c=in[index];

	if (c<'A' || c>'z' || (c>'Z' && c<'a'))
	{
		out[index] = in[index];
	}
	else
	{
		if (c>'m' || (c>'M' && c<'a'))
		{
			out[index] = in[index]-13;
		}
		else
		{
			out[index] = in[index]+13;
		}
	}
}
