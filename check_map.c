/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:37:55 by msacaliu          #+#    #+#             */
/*   Updated: 2024/03/05 13:28:14 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdbool.h>

int	check_if_rectangular_map(t_data *data)
{
	int	width;
	int height;

	width = find_width(data->map2);
	height = find_height(data->map2);
	if (width == height)
		{
			ft_printf("Map not rectangular!\n");
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
                hasP += 1;
            if (data->map2[i][j] == 'E')
                hasE += 1;
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
	if(hasE > 1 || hasP > 1)
	{
		ft_printf("Too many mandatory characters!\n");
		exit(1);
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


void dfs(int x, int y, char **map, int *found_exit) {
    ft_printf("x : %d", x);
    ft_printf(" y : %d\n", y);

    if(x < 0 || y < 0 || x >= find_width(map) || y >= find_height(map) )
        return;
	// ft_printf("x : %d", x);
    // ft_printf(" y : %d\n", y);
    if(map[x][y] == 'E') {
        *found_exit = 1;
        return;
    }

    // map[x][y] = 'V';

    dfs(x + 1, y, map, found_exit);
    dfs(x - 1, y, map, found_exit);
    dfs(x, y + 1, map, found_exit);
    dfs(x, y - 1, map, found_exit);
}

int check_path_to_exit(t_data *data) {
    int found_exit = 0;
	find_player_coordinates(data);
    int start_x = data->x / 50;
    int start_y = data->y / 50;
    dfs(start_x, start_y, data->map2, &found_exit);
	// ft_printf("x : %d",start_x);
	// ft_printf(" y :%d\n",start_y);
    if(!found_exit)
	{
		ft_printf("No exit found, invalid map\n");
		exit(1);
	}

	return (0);
}