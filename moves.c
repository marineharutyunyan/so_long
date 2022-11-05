#include "so_long.h"

void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = data->player_position_x - 1;
	y = data->player_position_y;
	if (data->map[y][x] != '1' && data->map[y][x] != 'E')
	{
		printf("\nNextpixel is %c\n", data->map[y][x]);
		printf("Current_score %d\n", data->current_score);
		printf("score %d\n\n", data->score);
		if (data->map[y][x] == 'C')
		{
			data->map[y][x] = '0';
			data->current_score += 1;
		}
		mlx_put_image_to_window(data->mlx, data->win, data->space, x * data->img_weight, y * data->img_height);
		mlx_put_image_to_window(data->mlx, data->win, data->space, data->player_position_x * data->img_weight, data->player_position_y * data->img_height);
		data->player_position_x -= 1;
		data->map[y][x] = 'P';
		mlx_put_image_to_window(data->mlx, data->win, data->player, x * data->img_weight, y * data->img_height);
	}
	if (data->map[y][x] == 'E' && data->current_score == data->score)
	{
		printf("\nNext pixel is %c\n", data->map[y][x]);
		mlx_put_image_to_window(data->mlx, data->win, data->space, data->player_position_x * data->img_weight, data->player_position_y * data->img_height);
		mlx_put_image_to_window(data->mlx, data->win, data->player, x * data->img_weight, y * data->img_height);
		printf("game Finished\n");
		mlx_destroy_window(data->mlx, data->win);
	}
}

void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->player_position_x + 1;
	y = data->player_position_y;
	if (data->map[y][x] != '1' && (data->map[y][x] != 'E' && data->current_score != data->score))
	{
		if (data->map[y][x] == 'C')
		{
			mlx_put_image_to_window(data->mlx, data->win, data->space, x * data->img_weight, y * data->img_height);
			data->current_score += 1;
		}
		mlx_put_image_to_window(data->mlx, data->win, data->space, data->player_position_x * data->img_weight, data->player_position_y * data->img_height);
		data->player_position_x += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->player_position_x * data->img_weight, data->player_position_y * data->img_height);
	}		
}

void	move_down(t_data *data)
{
	int	x;
	int	y;

	x = data->player_position_x;
	y = data->player_position_y + 1;
	if (data->map[y][x] != '1' && (data->map[y][x] != 'E' && data->current_score != data->score))
	{
		if (data->map[y][x] == 'C')
		{
			mlx_put_image_to_window(data->mlx, data->win, data->space, x * data->img_weight, y * data->img_height);
			data->current_score += 1;
		}
		mlx_put_image_to_window(data->mlx, data->win, data->space, data->player_position_x * data->img_weight, data->player_position_y * data->img_height);
		data->player_position_y += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->player_position_x * data->img_weight, data->player_position_y * data->img_height);
	}	
}

void	move_up(t_data *data)
{
	int	x;
	int	y;

	x = data->player_position_x;
	y = data->player_position_y - 1;
	if (data->map[y][x] != '1' && (data->map[y][x] != 'E' && data->current_score != data->score))
	{
		if (data->map[y][x] == 'C')
		{
			mlx_put_image_to_window(data->mlx, data->win, data->space, x * data->img_weight, y * data->img_height);
			data->current_score += 1;
		}
		mlx_put_image_to_window(data->mlx, data->win, data->space, data->player_position_x * data->img_weight, data->player_position_y * data->img_height);
		data->player_position_y -= 1;
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->player_position_x * data->img_weight, data->player_position_y * data->img_height);
	}
}
