/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:38:44 by msacaliu          #+#    #+#             */
/*   Updated: 2024/03/06 14:18:29 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int move_character(int keysym, t_data *data)
{
	int new_x = data->x;
	int new_y = data->y;

	if(keysym == 'w')
		new_y -= 50;
	if(keysym == 's')
		new_y += 50;
	if(keysym == 'a')
		new_x -= 50;
	if(keysym == 'd')
		new_x += 50;
	if (data->map2[new_y / 50][new_x / 50] == 'E' )
	{
		if(data->coins == data->coins_colected)
			end_game(data, new_x,new_y);
		else
			ft_printf("Not all coins colected!\n");
	}

	if (data->map2[new_y / 50][new_x / 50] == 'C')
	{
		data->map2[new_y / 50][new_x / 50] = '0';
		data->coins += 1;
	}
		
	if (data->map2[new_y / 50][new_x / 50] != '1') 
	{
		data->x = new_x;
		data->y = new_y;
		ft_printf("MOVES:%d          Coins: %d \n",data->moves += 1, data->coins);
		redraw_image(data,keysym);
	}
	return (0);
}

int handle_input(int keysym, t_data *data)
{
	if(keysym == 65307)
	{
		ft_printf("GAME OVER!\n");
		mlx_destroy_window(data->mlx_ptr,data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		exit(1);
	}
	if(keysym == 'w' || keysym == 's' || keysym == 'a' || keysym == 'd')
		move_character(keysym, data);
	return (0);
	
}

int	close_window(t_data *data)
{
    ft_printf("GAME OVER!\n");
    mlx_destroy_window(data->mlx_ptr,data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    exit(1);
    return (1);
}