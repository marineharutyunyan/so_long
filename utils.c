/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:46:12 by maharuty          #+#    #+#             */
/*   Updated: 2022/11/24 11:39:54 by maharuty         ###   ########.fr       */
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
	if (!data->space || !data->wall || !data->exit
		|| !data->player || !data->collectable)
	{
		ft_printf("images not found\n");
		ft_exit(data);
	}
}

void	drow_one_texture(void *texture, int x, int y, t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, texture, x * data->img_weight,
		y * data->img_height);
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
	if (keycode == 53)
		ft_exit(data);
	return (0);
}
