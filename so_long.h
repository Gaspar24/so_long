
#ifndef SO_LONG_H
# define SO_LONG_H

#define MAX_LINE_LENGTH 100
#define MAX_LINES 100

#include "./minilibx-linux/mlx.h"
#include "../libftprintf/ft_printf.h"
#include <stdlib.h>
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
	int     x;
    int     y;
	char	*map;

}				t_data;

void 	draw_floor(t_data *data);
void 	draw_wall(t_data *data);
void	put_player(t_data *data);
void	find_player_coordinates(t_data *data);
void   	redraw_image(t_data *data);
int 	handle_input(int keysym, t_data *data);
int 	move_character(int keysym ,t_data *data);
char	**read_map(const char *filename);
int 	find_width(char **map);
int 	find_height(char **map);
void 	draw_coin(t_data *data);
void	put_door(t_data *data);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
#endif