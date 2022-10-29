#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
#include <mlx.h>
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

typedef struct s_mapdata
{
	int	weight;
	int	height;
	int	player_position;
}		t_mapdata;

int	check_rectangule(int len, int rec_len);
int	check_symbols(char **map, t_mapdata *mapdata);

#endif
