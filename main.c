#include "so_long.h"

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	printf("Map size is %d x %d\n", data->height, data->weight);
	while (i != data->height)
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
}

char	**get_map(char	*ber_file, t_data *data)
{
	char		*line;
	int			fd;
	char		*buffer;

	fd = open(ber_file, O_RDONLY);
	line = get_next_line(fd);
	buffer = line;
	data->height = 0;
	while (buffer != NULL)
	{	
		data->height++;
		buffer = get_next_line(fd);
		line = ft_strjoin(line, buffer);
	}
	close(fd);
	data->map = ft_split(line, '\n');
	data->weight = ft_strlen(data->map[0]);
	if (validate_map(data))
		return (data->map);
	return (NULL);
}

void	set_window_size(t_data *data)
{
	data->wind_height = data->height * data->img_height;
	data->wind_weight = data->weight * data->img_weight;
}

void	init(t_data *data)
{
	data->current_score = 0;
	data->mlx = mlx_init();
	data->space = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm", &data->img_weight, &data->img_height);
	set_window_size(data);
	data->wall = mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm", &data->img_weight, &data->img_height);
	data->exit = mlx_xpm_file_to_image(data->mlx, "./img/exit.xpm", &data->img_weight, &data->img_height);
	data->player = mlx_xpm_file_to_image(data->mlx, "./img/player.xpm", &data->img_weight, &data->img_height);
	data->collectable = mlx_xpm_file_to_image(data->mlx, "./img/coin.xpm", &data->img_weight, &data->img_height);
	data->win = mlx_new_window(data->mlx, data->wind_weight, data->wind_height, "So Long");
}

int	event_handler(int keycode, t_data *data)
{
	if (keycode == 0)
		move_left(data);
	if (keycode == 2)
		move_right(data);
	if (keycode == 1)
		move_down(data);
	if (keycode == 13)
		move_up(data);
	return (0);
}

void	render(t_data *data)
{
	int			i;
	int			j;

	i = 0;
	while (i != data->height)
	{
		j = 0;
		while (j != data->weight)
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall, j * data->img_weight, i * data->img_height);
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->space, j * data->img_weight, i * data->img_height);
			else if (data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->space, j * data->img_weight, i * data->img_height);
				mlx_put_image_to_window(data->mlx, data->win, data->player, j * data->img_weight, i * data->img_height);
			}
			else if (data->map[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->space, j * data->img_weight, i * data->img_height);
				mlx_put_image_to_window(data->mlx, data->win, data->exit, j * data->img_weight, i * data->img_height);
			}
			else if (data->map[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->space, j * data->img_weight, i * data->img_height);
				mlx_put_image_to_window(data->mlx, data->win, data->collectable, j * data->img_weight, i * data->img_height);
			}
			j++;
		}
		i++;
	}
	mlx_hook(data->win, 2, 0, event_handler, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		data.map = get_map(argv[1], &data);
		if (data.map == NULL)
			return (1);
		init(&data);
		render(&data);
	}
}