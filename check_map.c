/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:37:55 by msacaliu          #+#    #+#             */
/*   Updated: 2024/03/04 11:56:09 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_if_rectangular_map(t_data *data)
{
	int	width;
	int height;

	width = find_width(data->map2);
	height = find_height(data->map2);
	if (width == height)
		{
			ft_printf("map not rectangular!\n");
			exit(1);
		}
	return(0);
}

int	check_map_characters(t_data *data)
{
    int i;
    int j;
    int	hasP, hasE, has1, has0, hasC;
    
    hasP = hasE = has1 = has0 = hasC = 0;
    i = 0;
    while (data->map2[i] != NULL)
    {
        j = 0;
        while (data->map2[i][j] != '\0')
        {
            if (data->map2[i][j] == 'P')
                hasP = 1;
            if (data->map2[i][j] == 'E')
                hasE = 1;
            if (data->map2[i][j] == '1')
                has1 = 1;
            if (data->map2[i][j] == '0')
                has0 = 1;
            if (data->map2[i][j] == 'C')
                hasC = 1;
            j++;
        }
        i++;
    }
    if (!(hasP && hasE && has1 && has0 && hasC))
    {
		ft_printf("Missing mandatory characters!\n");
		exit(1);
	}
    return(0);
}

int	check_walls(t_data *data)
{
	int i;
	int j;
	int width;
	int height;

	width = find_width(data->map2);
	height = find_height(data->map2);
	i = 0;
	while (data->map2[i] != NULL)
	{
		j = 0;
		while (data->map2[i][j] != '\0')
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
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
	return(0);
}

// void dfs(int x, int y, char **map, int *found_exit) {
//     // If out of bounds or not a path, return
//     if(x < 0 || y < 0 || map[y][x] == '\0' || map[y][x] == 'V') {
//         return;
//     }

//     // If this is the exit, set found_exit to 1 and return
//     if(map[y][x] == 'E') {
//         *found_exit = 1;
//         return;
//     }

//     // Mark this position as visited
//     map[y][x] = 'V';

//     // Recursively search in all four directions
//     dfs(x+1, y, map, found_exit); // Right
//     dfs(x-1, y, map, found_exit); // Left
//     dfs(x, y+1, map, found_exit); // Down
//     dfs(x, y-1, map, found_exit); // Up
// }

// int check_path_to_exit(t_data *data) {
//     int found_exit = 0;
//     int start_x = data->x / 50;
//     int start_y = data->y / 50;

//     // Start DFS from the starting position
//     dfs(start_x, start_y, data->map2, &found_exit);

//     if(found_exit == 0)
// 	{
// 		ft_printf("No exit found, invalid map\n");
// 		exit(1);
// 	}
		
// 	return (0);
// }