#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
#include <mlx.h>
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

typedef struct s_data
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
	int 	moves_count;
	int		wind_height;
	int		wind_weight;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		weight;
	int		height;
	int		player_position_x;
	int		player_position_y;
	int		current_score;
	int		score;
	char	**map;
}				t_data;

int		validate_map(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_down(t_data *data);
void	move_up(t_data *data);
int		ft_exit(t_data *data);

#endif
