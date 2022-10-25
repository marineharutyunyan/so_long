#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	//void	*mlx;
	//void	*img;
	char	*relative_path = "./wall.xpm";
	char	*relative_path2 = "./floor.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	//img.img = mlx_new_image(mlx, 1920, 1080);
	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//my_mlx_pixel_put(&img, 255, 255, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	img.img = mlx_xpm_file_to_image(mlx, relative_path2, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 500, 500);
	mlx_loop(mlx);
}