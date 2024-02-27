/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:04:37 by msacaliu          #+#    #+#             */
/*   Updated: 2024/02/27 15:15:51 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_coordinates(t_data *data)
{
    int x = 0;
    int y = 0;    
    char **map = read_map(data->map);
    
    int i = 0;
    int j;

    while(map[i] != NULL)
    {
        j = 0;
        while(map[i][j] != '\0')
        {
            if(map[i][j] == 'P')
            {
                data->x = x;
                data->y = y;
            }
            x += 50;
            j++;
        }
        x = 0;
        y += 50;
        i++;
    }
}