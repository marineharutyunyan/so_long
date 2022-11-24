/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:45:38 by maharuty          #+#    #+#             */
/*   Updated: 2022/11/24 11:38:29 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	generate_map(t_data *data, char *line, int fd, char *buffer)
{
	while (buffer != NULL)
	{	
		data->height++;
		buffer = get_next_line(fd);
		line = ft_strjoin(line, buffer);
	}
	data->map = ft_split(line, '\n');
	data->weight = ft_strlen(data->map[0]);
	free(line);
}

char	**get_map(char	*ber_file, t_data *data)
{
	char		*line;
	int			fd;
	char		*buffer;

	fd = open(ber_file, O_RDONLY);
	if (fd != -1)
	{
		line = get_next_line(fd);
		buffer = line;
		if (line)
		{
			data->height = 0;
			generate_map(data, line, fd, buffer);
			close(fd);
			if (validate_map(data))
				return (data->map);
		}
	}
	return (NULL);
}

void	drow_map(int i, int j, t_data *data)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall,
			j * data->img_weight, i * data->img_height);
	else
	{
		mlx_put_image_to_window(data->mlx, data->win, data->space,
			j * data->img_weight, i * data->img_height);
		if (data->map[i][j] == 'P')
			mlx_put_image_to_window(data->mlx, data->win, data->player,
				j * data->img_weight, i * data->img_height);
		else if (data->map[i][j] == 'E')
			mlx_put_image_to_window(data->mlx, data->win, data->exit,
				j * data->img_weight, i * data->img_height);
		else if (data->map[i][j] == 'C')
			mlx_put_image_to_window(data->mlx, data->win, data->collectable,
				j * data->img_weight, i * data->img_height);
	}
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
			drow_map(i, j, data);
			j++;
		}
		i++;
	}
	mlx_hook(data->win, 2, 0, event_handler, data);
	mlx_hook(data->win, 17, 0, ft_exit, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		if (check_file_extention(argv[1]))
		{
			data.map = get_map(argv[1], &data);
			if (data.map == NULL)
			{
				ft_printf("Something went wrong!\n");
				return (0);
			}
			init(&data);
			render(&data);
		}
	}
	return (0);
}
