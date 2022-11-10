/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:46:12 by maharuty          #+#    #+#             */
/*   Updated: 2022/11/09 18:46:17 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

void	set_window_size(t_data *data)
{
	data->wind_height = data->height * data->img_height;
	data->wind_weight = data->weight * data->img_weight;
}

void	init(t_data *data)
{
	data->current_score = 0;
	data->moves_count = 0;
	data->mlx = mlx_init();
	data->space = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm",
			&data->img_weight, &data->img_height);
	set_window_size(data);
	data->wall = mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm",
			&data->img_weight, &data->img_height);
	data->exit = mlx_xpm_file_to_image(data->mlx, "./img/exit.xpm",
			&data->img_weight, &data->img_height);
	data->player = mlx_xpm_file_to_image(data->mlx, "./img/player.xpm",
			&data->img_weight, &data->img_height);
	data->collectable = mlx_xpm_file_to_image(data->mlx, "./img/coin.xpm",
			&data->img_weight, &data->img_height);
	data->win = mlx_new_window(data->mlx, data->wind_weight,
			data->wind_height, "So Long");
}

int	check_walls(t_data *data)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (++i != data->height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if ((i == 0 || i == data->height) && data->map[i][j] != '1')
				return (0);
			if ((j == 0 || j == data->weight) && data->map[i][j] != '1')
				return (0);
			if (data->map[i][j] == '0' || data->map[i][j] == '1'
				|| data->map[i][j] == 'P' || data->map[i][j] == 'E'
					|| data->map[i][j] == 'C')
				flag = 1;
			else
				return (0);
			j++;
		}
	}
	return (flag);
}

void	drow_one_texture(void *texture, int x, int y, t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, texture, x * data->img_weight,
		y * data->img_height);
}
