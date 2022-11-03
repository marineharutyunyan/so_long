#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
#include <mlx.h>
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

typedef struct s_mapdata
{
	int		weight;
	int		height;
	int		player_position;
	int		current_score;
	int		score;
	char	**map;

}		t_mapdata;

typedef struct s_mlxdata
{
	int		img_weight;
	int		img_height;
	void	*wall;
	void	*exit;
	void	*player;
	void	*space;
	void	*collectable;
	char	*addr;
	void	*win;
	void	*mlx;
	int		wind_height;
	int		wind_weight;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlxdata;

int	validate_map(char **map, t_mapdata *map_data);

#endif
