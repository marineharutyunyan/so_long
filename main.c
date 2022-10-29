#include "so_long.h"

typedef struct s_data
{
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
	*(unsigned int *)dst = color;
}

void	print_map(char **map, t_mapdata *mapdata)
{
	int	i;

	i = 0;
	printf("%d x %d\n", mapdata->height, mapdata->weight);
	while (i != mapdata->height)
	{
		ft_printf("%s", map[i]);
		i++;
	}
}

int	main(int argc, char ** argv)
{
/*
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	//void	*mlx;
	//void	*img;
	char	*relative_path = "./img/wall.xpm";
	char	*relative_path2 = "./img/floor.xpm";
	int		img_width;
	int		img_height;

	ft_printf("gdsdg%s\n", ft_strdup("barev\n"));
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
	*/
	char		*line;
	int			fd;
	int			i;
	t_mapdata	*mapdata;
	char		**map;

	mapdata = malloc(sizeof(t_mapdata));
	ft_printf("arguments count is %d\n", argc);
	line = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	mapdata->height = 0;
	mapdata->weight = ft_strlen(line);
	while (line != NULL)
	{
		if (!check_rectangule(ft_strlen(line), mapdata->weight))
		{
			ft_printf("WRONG\n");
			break ;
		}
		mapdata->height++;
		line = get_next_line(fd);
	}
	map = malloc(sizeof(char *) * mapdata->height);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		map[i] = malloc(sizeof(char) * mapdata->weight);
		map[i] = line;
		if (!line)
			break ;
		line = get_next_line(fd);
		i++;
	}
	if (!check_symbols(map, mapdata))
	{
		printf("Error\n");
	}
	print_map(map, mapdata);
}
