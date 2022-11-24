/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:59:58 by maharuty          #+#    #+#             */
/*   Updated: 2022/11/24 10:07:32 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_allowed_symbols(t_data *data, int i, int j)
{
	if (data->map[i][j] == '0' || data->map[i][j] == '1'
		|| data->map[i][j] == 'P' || data->map[i][j] == 'E'
			|| data->map[i][j] == 'C')
		return (1);
	else
		return (0);
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
			if (i == 0 && data->map[i][j] != '1')
				return (0);
			else if (i == data->height - 1 && data->map[i][j] != '1')
				return (0);
			else if (j == 0 && data->map[i][j] != '1')
				return (0);
			else if (j == data->weight - 1 && data->map[i][j] != '1')
				return (0);
			flag = check_allowed_symbols(data, i, j);
			j++;
		}
	}
	return (flag);
}

int	check_file_extention(char *ber_file)
{
	int	len;

	len = ft_strlen(ber_file);
	if (ber_file[len - 1] == 'r' && ber_file[len - 2] == 'e'
		&& ber_file[len - 3] == 'b' && ber_file[len - 4] == '.' )
		return (1);
	else
	{
		ft_printf("map is invalid\n");
		return (0);
	}
}
