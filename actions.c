/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:38:44 by msacaliu          #+#    #+#             */
/*   Updated: 2024/02/27 15:45:52 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int move_character(int keysym, t_data *data)
{
	int new_x = data->x;
	int new_y = data->y;
	char **map = read_map(data->map);
	
	if(keysym == 'w')
		new_y -= 50;
	if(keysym == 's')
		new_y += 50;
	if(keysym == 'a')
		new_x -= 50;
	if(keysym == 'd')
		new_x += 50;
	if (map[new_y / 50][new_x / 50] != '1') 
	{
		data->x = new_x;
		data->y = new_y;
		redraw_image(data);
	}
	if (map[new_y / 50][new_x / 50] == 'E') 
	{
		data->x = new_x;
		data->y = new_y;
		sleep(1);
		ft_printf("You foud the exit!!\n");
		mlx_destroy_window(data->mlx_ptr,data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		exit(0);
	}
	return (0);
}

int handle_input(int keysym, t_data *data)
{
	if(keysym == 65307)
	{
		ft_printf("End game!\n");
		mlx_destroy_window(data->mlx_ptr,data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		exit(1);
	}
	if(keysym == 'w' || keysym == 's' || keysym == 'a' || keysym == 'd')
		move_character(keysym, data);
	return (0);
}
