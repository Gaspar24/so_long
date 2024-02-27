/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:34:36 by msacaliu          #+#    #+#             */
/*   Updated: 2024/02/27 15:41:22 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void   redraw_image(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_floor(data);
	draw_wall(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,data->player, data->x, data->y);
	draw_coin(data);
	put_door(data);
}

void	put_door(t_data *data)
{
	int img_width = 50;
    int img_height = 50;
    void *door;
    int x = 0;
    int y = 0;

    door = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/door.xpm",&img_width, &img_height);
    char **map = read_map(data->map);
    int i = 0;
    int j;
    while(map[i] != NULL)
    {
        j = 0;
        while(map[i][j] != '\0')
        {
            if(map[i][j] == 'E')
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
    // void *floor;
    int x = 0;
    int y = 0;

    data->floor = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/floor.xpm",&img_width, &img_height);
	char **map = read_map(data->map);
    int i = 0;
    int j;
    while(map[i] != NULL)
    {
        j = 0;
        while(map[i][j] != '\0')
        {
            if(map[i][j] == '0' ||  map[i][j] == 'P')
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

    data->player = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/ninja1.xpm",&img_width, &img_height);
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
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,data->player,x,y);
            }
            x += img_width;
            j++;
        }
        y += img_height;
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
    char **map = read_map(data->map);
	int i = 0;
	int j;
	while(map[i] != NULL)
	{
		j = 0;
		while(map[i][j] != '\0')
		{
			if(map[i][j] == '1')
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
	void *coin;
	int img_width = 50;
	int img_height = 50;
	int x = 0;
	int y = 0;

	coin = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/coin.xpm",&img_width, &img_height);
    char **map = read_map(data->map);
	int i = 0;
	int j;
	while(map[i] != NULL)
	{
		j = 0;
		while(map[i][j] != '\0')
		{
			if(map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, coin, x, y);
			x += img_width;
			j++;
		}
		y += img_height;
		x = 0;
		i++;
	}
}
