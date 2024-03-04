/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:12:51 by msacaliu          #+#    #+#             */
/*   Updated: 2024/03/04 11:49:29 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

#define MAX_LINE_LENGTH 1000
#define MAX_LINES 1000
#define WIDTH 100
#define HEIGHT 100

#include "./minilibx-linux/mlx.h"
#include "../libftprintf/ft_printf.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>



typedef struct	s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void 	*player;
	void	*wall;
	void	*floor;
	void	*coin;
	int     x;
    int     y;
	char 	**map2;
	char	*map;
	int		moves;
	int		coins;
	int		coins_colected;

}				t_data;

void 	draw_floor(t_data *data);
void 	draw_wall(t_data *data);
void	put_player(t_data *data);
void	find_player_coordinates(t_data *data);
int	  	redraw_image(t_data *data);
int 	handle_input(int keysym, t_data *data);
void    end_game(t_data *data, int new_x, int new_y);
int 	move_character(int keysym ,t_data *data);
char	**read_map(const char *filename);
int 	find_width(char **map);
int 	find_height(char **map);
void 	draw_coin(t_data *data);
void	put_door(t_data *data);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char 	*ft_strcpy(char *dest, char *src);
void	count_coins(t_data *data);
int		close_window(t_data *data);
int		check_if_rectangular_map(t_data *data);
int		check_map_characters(t_data *data);
int		check_walls(t_data *data);
int 	check_path_to_exit(t_data *data);
void 	validate_map(t_data *data);
// char	*ft_itoa(int n);
#endif