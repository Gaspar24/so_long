/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:34:36 by msacaliu          #+#    #+#             */
/*   Updated: 2024/03/06 10:57:50 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	put_door(t_data *data)
{
	int img_width = 50;
    int img_height = 50;
    void *door;
    int x = 0;
    int y = 0;

    door = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/door.xpm",&img_width, &img_height);
    int i = 0;
    int j;
    while(data->map2[i] != NULL)
    {
        j = 0;
        while(data->map2[i][j] != '\0')
        {
            if(data->map2[i][j] == 'E')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, door, x, y);
            x += img_width;
            j++;
        }
        y += img_height;
        x = 0;
        i++;
    }
}

void draw_floor(t_data *data)
{
    int img_width = 50;
    int img_height = 50;
    int x = 0;
    int y = 0;

    data->floor = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/floor.xpm",&img_width, &img_height);
    int i = 0;
    int j;
    while(data->map2[i] != NULL)
    {
        j = 0;
        while(data->map2[i][j] != '\0')
        {
            if(data->map2[i][j] == '0' ||  data->map2[i][j] == 'P')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, x, y);
            x += img_width;
            j++;
        }
        y += img_height;
        x = 0;
        i++;
    }
}

void put_player(t_data *data)
{
    int img_width = 50;
    int img_height = 50;

    int x = 0;
    int y = 0;
    data->player_right = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/right_ninja.xpm",&img_width, &img_height);
    data->player = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/ninja5.xpm",&img_width, &img_height);
    data->player_up = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/up_ninja.xpm",&img_width, &img_height);
    data->player_down = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/down_ninja.xpm",&img_width, &img_height);
    int i = 0;
    int j;
	
    while(data->map2[i] != NULL)
    {
        j = 0;
        while(data->map2[i][j] != '\0')
        {
            if(data->map2[i][j++] == 'P')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,data->player,x,y);
            x += 50;
        }
        y += 50;
        x = 0;
        i++;
    }
	find_player_coordinates(data);
}

void draw_wall(t_data *data)
{
	void *wall;
	int img_width = 50;
	int img_height = 50;
	int x = 0;
	int y = 0;

	wall = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/wall1.xpm",&img_width, &img_height);
	int i = 0;
	int j;
	while(data->map2[i] != NULL)
	{
		j = 0;
		while(data->map2[i][j] != '\0')
		{
			if(data->map2[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall, x, y);
			x += img_width;
			j++;
		}
		y += img_height;
		x = 0;
		i++;
	}
}

void draw_coin(t_data *data)
{
	int img_width = 50;
	int img_height = 50;
	int x = 0;
	int y = 0;
    int i = 0;
	data->coin = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/coin2.xpm",&img_width, &img_height);
	i = 0;
	int j;
	while (data->map2[i] != NULL)
	{
		j = 0;
		while (data->map2[i][j] != '\0')
		{
			if (data->map2[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->coin, x, y);
			x += img_width;
			j++;
		}
		y += img_height;
		x = 0;
		i++;
	}
}
