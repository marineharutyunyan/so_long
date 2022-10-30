#include "so_long.h"

int	is_rectangule(char **map, t_mapdata *map_data)
{
	int	i;

	i = 0;
	while (i != map_data->height)
	{
		if (ft_strlen(map[i]) != (size_t)map_data->weight)
			return (0);
		i++;
	}
	return (1);
}

int	check_exit(char **map, t_mapdata *map_data)
{
	int	i;
	int	j;
	int	exit_count;

	i = 0;
	exit_count = 0;
	while (i != map_data->height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (exit_count >= 1)
		return (1);
	return (0);
}

int	check_and_set_collectables(char **map, t_mapdata *map_data)
{
	int	i;
	int	j;

	i = 0;
	map_data->score = 0;
	while (i != map_data->height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				map_data->score++;
			j++;
		}
		i++;
	}
	if (map_data->score >= 1)
		return (1);
	return (0);
}

int	check_player(char **map, t_mapdata *map_data)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (i != map_data->height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count == 1)
		return (1);
	return (0);
}

int	check_walls(char **map, t_mapdata *mapdata)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i != mapdata->height)
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || i == mapdata->height) && map[i][j] != '1')
				return (0);
			if ((j == 0 || j == mapdata->weight) && map[i][j] != '1')
				return (0);
			if (map[i][j] == '0' || map[i][j] == '1'
				|| map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C')
				flag = 1;
			else
				return (0);
			j++;
		}
		i++;
	}
	return (flag);
}

int	validate_map(char **map, t_mapdata *map_data)
{
	//printf("is map rectangule ?  %d\n", is_rectangule(map, map_data));
	if (!is_rectangule(map, map_data))
		return (0);
	//printf("simbols and walls are valid ?  %d\n", check_walls(map, map_data));
	if (!check_walls(map, map_data))
		return (0);
	//printf("one player exist?  %d\n", check_player(map, map_data));
	if (!check_player(map, map_data))
		return (0);
	//printf("at least one exit exist? %d\n", check_exit(map, map_data));
	if (!check_exit(map, map_data))
		return (0);
	//printf("colectable exist? %d\n", check_and_set_collectables(map, map_data));
	if (!check_and_set_collectables(map, map_data))
		return (0);
	return (1);
}
