#include "so_long.h"

int	check_rectangule(int len, int rec_len)
{
	if (len == rec_len)
		return (1);
	return (0);
}

int	check_symbols(char **map, t_mapdata *mapdata)
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
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == '\n'
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