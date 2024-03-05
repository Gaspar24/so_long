/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:04:37 by msacaliu          #+#    #+#             */
/*   Updated: 2024/03/05 13:28:23 by msacaliu         ###   ########.fr       */
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

int   redraw_image(t_data *data)
{
	draw_floor(data);
	draw_wall(data);
    draw_coin(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,data->player, data->x, data->y);
	put_door(data);
    // mlx_string_put(data->mlx_ptr, data->win_ptr, (find_width(data->map2) *50)
    //  / 3, (50 + find_height(data->map2) * 50)- 20, 0x00FF00,ft_itoa(data->moves));
    return(0);
}


void    end_game(t_data *data, int new_x, int new_y)
{
        data->x = new_x;
		data->y = new_y;
        ft_printf("You foud the exit!!\n");
		mlx_destroy_window(data->mlx_ptr,data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		exit(0);
}

void validate_map(t_data *data)
{
    check_if_rectangular_map(data);
    check_map_characters(data);
    check_walls(data);
    // check_path_to_exit(data);
}

// void count_coins(t_data *data)
// {
//     int i;
// 	int j;
    
//     i = 0;
//     data->coins_colected = 0;
// 	while(data->map2[i] != NULL)
// 	{
// 		j = 0;
// 		while(data->map2[i][j] != '\0')
// 		{
// 			if(data->map2[i][j] == 'C')
// 				data->coins_colected += 1;
// 			j++;
// 		}
// 		i++;
// 	}
// }
