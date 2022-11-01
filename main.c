#include "so_long.h"

void	my_mlx_pixel_put(t_mlxdata *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_map(char **map, t_mapdata *mapdata)
{
	int	i;

	i = 0;
	printf("%d x %d\n", mapdata->height, mapdata->weight);
	while (i != mapdata->height)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

char	**get_map(char	*ber_file, t_mapdata *map_data)
{
	char		**map;
	char		*line;
	int			fd;
	char		*buffer;

	fd = open(ber_file, O_RDONLY);
	line = get_next_line(fd);
	buffer = line;
	map_data->height = 0;
	while (buffer != NULL)
	{	
		map_data->height++;
		buffer = get_next_line(fd);
		line = ft_strjoin(line, buffer);
	}
	close(fd);
	map = ft_split(line, '\n');
	map_data->weight = ft_strlen(map[0]);
	if (validate_map(map, map_data))
		return (map);
	return (NULL);
}

void	init(t_mapdata *map_data)
{
	map_data->space = "./img/floor.xpm";
	map_data->wall = "./img/wall.xpm";
	map_data->current_score = 0;
}

void	set_window_size(int img_height, int img_width, int *w_height, int *w_width, t_mapdata *map_data)
{
	*w_height = map_data->height * img_height;
	*w_width = map_data->weight * img_width;
}
/*
void	render(char **map, t_mapdata *map_data)
{
	t_mlxdata	img;
	void		*mlx;
	void		*mlx_win;
	int			img_height;
	int			img_width;
	int 		w_height;
	int 		w_width;
	//void	*mlx;
	//void	*img;

	mlx = mlx_init();
	//img.img = mlx_new_image(mlx, 1920, 1080);
	img.img = mlx_xpm_file_to_image(mlx, map_data->space, &img_width, &img_height);
	set_window_size(img_height, img_width, &w_height, &w_width, map_data);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//my_mlx_pixel_put(&img, 255, 255, 0x00FF0000);
	img.img = mlx_xpm_file_to_image(mlx, map_data->wall, &img_width, &img_height);
	mlx_win = mlx_new_window(mlx, w_width, w_height, "So Long");
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 500, 500);
	mlx_loop(mlx);
}
*/
void	render(char **map, t_mapdata *map_data)
{
	t_mlxdata	*mlx_data;
	void		*mlx;
	void		*mlx_win;
	int			img_height;
	int			img_width;

	mlx_data = malloc(sizeof(t_mlxdata));
	mlx = mlx_init();
	mlx_data->img = mlx_xpm_file_to_image(mlx, map_data->space, &img_width, &img_height);
	set_window_size(img_height, img_width, &mlx_data->wind_height, &mlx_data->wind_weight, map_data);
	mlx_win = mlx_new_window(mlx, mlx_data->wind_weight, mlx_data->wind_height, "So Long");
	mlx_put_image_to_window(mlx, mlx_win, mlx_data->img, 0, 0);
	mlx_data->img = mlx_xpm_file_to_image(mlx, map_data->wall, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, mlx_data->img, 100, 100);
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	char		**map;
	t_mapdata	*map_data;

	map_data = malloc(sizeof(t_mapdata));
	if (argc > 1)
	{
		map = get_map(argv[1], map_data);
		init(map_data);
		render(map, map_data);
	}
}
