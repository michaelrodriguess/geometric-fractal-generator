#include "fract-ol.h"

int	print_iteration_mandelbrot(const double c)
{
	double z;
	size_t i;
	size_t max_iteration;

	z = 0;
	i = 0;
	max_iteration = 100;
	while (z <= 2)
	{
		if (i == max_iteration)
			break;
		z = pow(z,2) + c;
		i++;
	}
	return (i);
}

int main(void)
{
	double c;
	double distancia;
	void	*mlx_ptr;
	void	*mlx_wd;
	int i = 0;
	
	mlx_ptr = mlx_init();
	mlx_wd = mlx_new_window(mlx_ptr, 600, 600, "Fractol");
	distancia = (double) 4 / 600;
	c = -2;
	while (c <= 2)
	{
		if (print_iteration_mandelbrot(c) == 100)
			mlx_pixel_put(mlx_ptr, mlx_wd, i, 300, 0xFFFFFF);
		//write(1, "1", 1);
		else 
			mlx_pixel_put(mlx_ptr, mlx_wd, i, 300, 0x80FF00);
			//write(1, "0", 1);

		i++;
		c += distancia;
	}
	mlx_loop(mlx_ptr);
}
