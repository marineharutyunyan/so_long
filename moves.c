#include "so_long.h"

void	move(int next_x, int next_y, t_data *data)
{
	if (data->map[next_y][next_x] != '1' && data->map[next_y][next_x] != 'E')
	{
		data->moves_count += 1;
		printf("You did %d steps\n", data->moves_count);
		if (data->map[next_y][next_x] == 'C')
		{
			data->map[next_y][next_x] = '0';
			data->current_score += 1;
		}
		mlx_put_image_to_window(data->mlx, data->win, data->space, next_x * data->img_weight, next_y * data->img_height);
		mlx_put_image_to_window(data->mlx, data->win, data->space, data->player_position_x * data->img_weight, data->player_position_y * data->img_height);
		data->player_position_x = next_x;
		data->player_position_y = next_y;
		data->map[next_y][next_x] = 'P';
		mlx_put_image_to_window(data->mlx, data->win, data->player, next_x * data->img_weight, next_y * data->img_height);
	}
	if (data->map[next_y][next_x] == 'E' && data->current_score == data->score)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->space, data->player_position_x * data->img_weight, data->player_position_y * data->img_height);
		mlx_put_image_to_window(data->mlx, data->win, data->player, next_x * data->img_weight, next_y * data->img_height);
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
