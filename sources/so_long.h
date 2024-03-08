/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:12:51 by msacaliu          #+#    #+#             */
/*   Updated: 2024/03/08 11:29:46 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../lib/libftprintf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# define MAX_LINE_LENGTH 1000
# define MAX_LINES 1000
# define WIDTH 100
# define HEIGHT 100
# define X 0
# define Y 1
# define SIZE 50

typedef struct s_dfs_data
{
	int	has_p;
	int	has_e;
	int	has_1;
	int	has_c;
}	t_dfs_data;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player;
	void	*player_right;
	void	*player_up;
	void	*player_down;
	void	*wall;
	void	*floor;
	void	*coin;
	void	*door;
	int		x;
	int		y;
	char	**map2;
	char	*map;
	int		moves;
	int		coins;
	int		coins_colected;
	int		found_exit;
	int		coins_posible_to_reach;

}				t_data;

void	draw_floor(t_data *data, int img_width, int img_height);
void	draw_wall(t_data *data, int img_width, int img_height);
void	put_player(t_data *data, int img_width, int img_height);
void	draw_coin(t_data *data, int img_width, int img_height);
void	put_player_positions(t_data *data, int img_width, int img_height);
void	put_door(t_data *data, int img_width, int img_height);
int		redraw_image(t_data *data, int keysim);
void	find_player_coordinates(t_data *data);
int		handle_input(int keysym, t_data *data);
void	end_game(t_data *data, int new_x, int new_y);
int		move_character(int keysym, t_data *data);
char	**read_map(const char *filename);
int		find_width(char **map);
int		find_height(char **map);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
void	count_coins(t_data *data);
int		close_window(t_data *data);
int		check_if_rectangular_map(t_data *data);
int		check_map_characters(t_data *data, t_dfs_data *characters);
int		check_walls(t_data *data);
int		check_path_to_exit(t_data *data);
void	check_characters_nb(t_dfs_data *characters);
void	validate_map(t_data *data, t_dfs_data *characters);
char	**copy_map(t_data *data);
void	check_if_all_rows_are_equal(t_data *data);
void	check_map_interior(t_data *data);
void	startup(t_data *data, t_dfs_data *characters, char *str);
char	*ft_strchr(const char *s, int c);
void	free_map(char **map, t_data *data);
void	define_characters(t_dfs_data *characters);

#endif