/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:46:25 by maharuty          #+#    #+#             */
/*   Updated: 2022/11/24 10:59:23 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangule(t_data *data)
{
	int	i;

	i = 0;
	if (data->weight < 6 || data->height < 3)
		return (0);
	while (i != data->height)
	{
		if (ft_strlen(data->map[i]) != (size_t)data->weight)
			return (0);
		i++;
	}
	return (1);
}

int	check_exit(t_data *data)
{
	int	i;
	int	j;
	int	exit_count;

	i = 0;
	exit_count = 0;
	while (i != data->height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (exit_count >= 1)
		return (1);
	return (0);
}

int	check_and_set_collectables(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->score = 0;
	while (i != data->height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->score++;
			j++;
		}
		i++;
	}
	if (data->score >= 1)
		return (1);
	return (0);
}

int	check_and_set_player(t_data *data)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (i != data->height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_position_x = j;
				data->player_position_y = i;
				player_count++;
			}
			j++;
		}
		i++;
	}
	if (player_count == 1)
		return (1);
	return (0);
}

int	validate_map(t_data *data)
{
	if (!is_rectangule(data))
		return (0);
	if (!check_walls(data))
		return (0);
	if (!check_and_set_player(data))
		return (0);
	if (!check_exit(data))
		return (0);
	if (!check_and_set_collectables(data))
		return (0);
	return (1);
}
