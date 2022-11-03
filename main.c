#include "so_long.h"

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

void	set_window_size(t_mlxdata *mlx_data, t_mapdata *map_data)
{
	mlx_data->wind_height = map_data->height * mlx_data->img_height;
	mlx_data->wind_weight = map_data->weight * mlx_data->img_weight;
}

void	init(t_mapdata *map_data, t_mlxdata *mlx_data)
{
	map_data->current_score = 0;
	mlx_data->mlx = mlx_init();
	mlx_data->space = mlx_xpm_file_to_image(mlx_data->mlx, "./img/floor.xpm", &mlx_data->img_weight, &mlx_data->img_height);
	set_window_size(mlx_data, map_data);
	mlx_data->wall = mlx_xpm_file_to_image(mlx_data->mlx, "./img/wall.xpm", &mlx_data->img_weight, &mlx_data->img_height);
	mlx_data->exit = mlx_xpm_file_to_image(mlx_data->mlx, "./img/exit.xpm", &mlx_data->img_weight, &mlx_data->img_height);
	mlx_data->player = mlx_xpm_file_to_image(mlx_data->mlx, "./img/player.xpm", &mlx_data->img_weight, &mlx_data->img_height);
	mlx_data->collectable = mlx_xpm_file_to_image(mlx_data->mlx, "./img/coin.xpm", &mlx_data->img_weight, &mlx_data->img_height);
	mlx_data->win = mlx_new_window(mlx_data->mlx, mlx_data->wind_weight, mlx_data->wind_height, "So Long");
}

/*int	closee(int keycode, t_mapdata *map_data)
{
	mlx_destroy_window(vars->mlxx, vars->wind);
	return (0);
}*/

void	render(char **map, t_mapdata *map_data, t_mlxdata	*mlx_data)
{
	int			i;
	int			j;

	i = 0;
	while (i != map_data->height)
	{
		j = 0;
		while (j != map_data->weight)
		{
			if (map[i][j] == '1')
			{
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->wall, j * mlx_data->img_weight, i * mlx_data->img_height);
			}
			else if (map[i][j] == '0')
			{
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->space, j * mlx_data->img_weight, i * mlx_data->img_height);
			}
			else if (map[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->space, j * mlx_data->img_weight, i * mlx_data->img_height);
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->player, j * mlx_data->img_weight, i * mlx_data->img_height);
			}
			else if (map[i][j] == 'E')
			{
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->space, j * mlx_data->img_weight, i * mlx_data->img_height);
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->exit, j * mlx_data->img_weight, i * mlx_data->img_height);
			}
			else if (map[i][j] == 'C')
			{
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->space, j * mlx_data->img_weight, i * mlx_data->img_height);
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->collectable, j * mlx_data->img_weight, i * mlx_data->img_height);
			}
			j++;
		}
		i++;
	}
	//mlx_hook(mlx_win, 2, 0, closee, &map_data);
	mlx_loop(mlx_data->mlx);
}

int	main(int argc, char **argv)
{
	char		**map;
	t_mapdata	map_data;
	t_mlxdata	mlx_data;

	if (argc > 1)
	{
		map = get_map(argv[1], &map_data);
		if (map == NULL)
			return (1);
		init(&map_data, &mlx_data);
		render(map, &map_data, &mlx_data);
	}
}

/*typedef struct	s_vars {
	void	*mlxx;
	void	*wind;
}				t_vars;


int	main(void)
{
	t_vars	vars;

	vars.mlxx= mlx_init();
	vars.wind = mlx_new_window(vars.mlxx, 1920, 1080, "Hello world!");
	mlx_hook(vars.wind, 2, 0, closee, &vars);
	mlx_loop(vars.mlxx);
}*/
