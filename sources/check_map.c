/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:37:55 by msacaliu          #+#    #+#             */
/*   Updated: 2024/03/07 14:43:16 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdbool.h>

int	check_if_rectangular_map(t_data *data)
{
	int	width;
	int	height;

	width = find_width(data->map2);
	height = find_height(data->map2);
	if (width == height)
	{
		ft_printf("Map not rectangular!\n");
		exit(1);
	}
	return (0);
}

int	check_map_characters(t_data *data, t_dfs_data *characters)
{
	int	i[2];

	i[X] = 0;
	define_characters();
	while (data->map2[i[X]] != NULL)
	{
		i[Y] = 0;
		while (data->map2[i[X]][i[Y]] != '\0')
		{
			if (data->map2[i[X]][i[Y]] == 'P')
				characters->has_p += 1;
			if (data->map2[i[X]][i[Y]] == 'E')
				characters->has_e += 1;
			if (data->map2[i[X]][i[Y]] == '1')
				characters->has_1 = 1;
			if (data->map2[i[X]][i[Y]] == '0')
				characters->has_0 = 1;
			if (data->map2[i[X]][i[Y]] == 'C')
				characters->has_c = 1;
			i[Y]++;
		}
		i[X]++;
	}
	check_characters_nb(characters);
	return (0);
}

int	check_walls(t_data *data)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = 0;
	while (data->map2[i] != NULL)
	{
		j = 0;
		while (data->map2[i][j] != '\0')
		{
			if (i == 0 || i == find_height(data->map2) - 1
				|| j == 0 || j == find_width(data->map2) - 1)
			{
				if (data->map2[i][j] != '1')
				{
					ft_printf("Map is not surrounded by walls!\n");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	dfs(t_data *data, int x, int y, char **map)
{
	int	width;
	int	height;

	width = find_width(data->map2);
	height = find_height(data->map2);
	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
	{
		data->found_exit = 1;
		return ;
	}
	map[y][x] = 'V';
	dfs(data, x + 1, y, map);
	dfs(data, x - 1, y, map);
	dfs(data, x, y + 1, map);
	dfs(data, x, y - 1, map);
}

int	check_path_to_exit(t_data *data)
{
	int		start_x;
	int		start_y;
	char	**map_copy;
	int		i;

	i = 0;
	data->found_exit = 0;
	find_player_coordinates(data);
	start_x = data->x / 50;
	start_y = data->y / 50;
	map_copy = copy_map(data);
	dfs(data, start_x, start_y, map_copy);
	if (!data->found_exit)
	{
		ft_printf("No exit found, invalid map\n");
		exit(1);
	}
	while (i < find_height(data->map2))
		free(map_copy[i++]);
	free(map_copy);
	return (0);
}
