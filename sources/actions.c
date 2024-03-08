/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:38:44 by msacaliu          #+#    #+#             */
/*   Updated: 2024/03/08 11:19:06 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_position(int keysym, int *new_x, int *new_y)
{
	if (keysym == 'w')
		*new_y -= 50;
	if (keysym == 's')
		*new_y += 50;
	if (keysym == 'a')
		*new_x -= 50;
	if (keysym == 'd')
		*new_x += 50;
}

void	update_coordinates(t_data *data, int new_x, int new_y, int keysym)
{
	data->x = new_x;
	data->y = new_y;
	ft_printf("MOVES:%d       Coins: %d \n", data->moves += 1, data->coins);
	redraw_image(data, keysym);
}

int	move_character(int keysym, t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->x;
	new_y = data->y;
	update_position(keysym, &new_x, &new_y);
	if (data->map2[new_y / 50][new_x / 50] == 'E' )
	{
		if (data->coins == data->coins_colected)
			end_game(data, new_x, new_y);
		else
			ft_printf("Not all coins colected!\n");
	}
	if (data->map2[new_y / 50][new_x / 50] == 'C')
	{
		data->map2[new_y / 50][new_x / 50] = '0';
		data->coins += 1;
	}
	if (data->map2[new_y / 50][new_x / 50] != '1')
		update_coordinates(data, new_x, new_y, keysym);
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == 65307)
	{
		ft_printf("GAME OVER!\n");
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		exit(1);
	}
	if (keysym == 'w' || keysym == 's' || keysym == 'a' || keysym == 'd')
		move_character(keysym, data);
	return (0);
}

int	close_window(t_data *data)
{
	ft_printf("GAME OVER!\n");
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	exit(1);
	return (1);
}
