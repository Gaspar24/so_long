/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:04:37 by msacaliu          #+#    #+#             */
/*   Updated: 2024/03/08 11:19:58 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_coordinates(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = read_map(data->map);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				data->x = j * 50;
				data->y = i * 50;
			}
		}
	}
}

int	redraw_image(t_data *data, int keysim)
{
	put_door(data, SIZE, SIZE);
	draw_floor(data, SIZE, SIZE);
	draw_wall(data, SIZE, SIZE);
	draw_coin(data, SIZE, SIZE);
	if (keysim == 'a')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player, data->x, data->y);
	else if (keysim == 'd')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_right, data->x, data->y);
	else if (keysim == 'w')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_up, data->x, data->y);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_down, data->x, data->y);
	return (0);
}

void	end_game(t_data *data, int new_x, int new_y)
{
	data->x = new_x;
	data->y = new_y;
	ft_printf("You foud the exit!!\n");
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

void	validate_map(t_data *data, t_dfs_data *characters)
{
	check_if_all_rows_are_equal(data);
	check_if_rectangular_map(data);
	check_map_characters(data, characters);
	check_map_interior(data);
	check_walls(data);
	check_path_to_exit(data);
}

void	count_coins(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->coins_colected = 0;
	while (data->map2[i] != NULL)
	{
		j = 0;
		while (data->map2[i][j] != '\0')
		{
			if (data->map2[i][j] == 'C')
				data->coins_colected += 1;
			j++;
		}
		i++;
	}
}
