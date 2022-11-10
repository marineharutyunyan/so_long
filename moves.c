/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:45:58 by maharuty          #+#    #+#             */
/*   Updated: 2022/11/09 18:46:00 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(int next_x, int next_y, t_data *data)
{
	if (data->map[next_y][next_x] != '1' && data->map[next_y][next_x] != 'E')
	{
		data->moves_count += 1;
		ft_printf("You did %d steps\n", data->moves_count);
		if (data->map[next_y][next_x] == 'C')
		{
			data->map[next_y][next_x] = '0';
			data->current_score += 1;
		}
		drow_one_texture(data->space, next_x, next_y, data);
		drow_one_texture(data->space, data->player_position_x,
			data->player_position_y, data);
		data->player_position_x = next_x;
		data->player_position_y = next_y;
		data->map[next_y][next_x] = 'P';
		drow_one_texture(data->player, next_x, next_y, data);
	}
	if (data->map[next_y][next_x] == 'E' && data->current_score == data->score)
	{
		drow_one_texture(data->space, data->player_position_x,
			data->player_position_y, data);
		drow_one_texture(data->player, next_x, next_y, data);
		ft_exit(data);
	}
}

void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = data->player_position_x - 1;
	y = data->player_position_y;
	move(x, y, data);
}

void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->player_position_x + 1;
	y = data->player_position_y;
	move(x, y, data);
}

void	move_down(t_data *data)
{
	int	x;
	int	y;

	x = data->player_position_x;
	y = data->player_position_y + 1;
	move(x, y, data);
}

void	move_up(t_data *data)
{
	int	x;
	int	y;

	x = data->player_position_x;
	y = data->player_position_y - 1;
	move(x, y, data);
}
