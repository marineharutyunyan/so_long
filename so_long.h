/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:46:43 by maharuty          #+#    #+#             */
/*   Updated: 2022/11/24 11:38:56 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include "libft.h"
# include "ft_printf.h"

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
	int		moves_count;
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

void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_down(t_data *data);
void	move_up(t_data *data);
void	init(t_data *data);
int		check_walls(t_data *data);
int		event_handler(int keycode, t_data *data);
void	drow_one_texture(void *texture, int x, int y, t_data *data);
int		validate_map(t_data *data);
int		check_file_extention(char *ber_file);
int		ft_exit(t_data *data);

#endif
