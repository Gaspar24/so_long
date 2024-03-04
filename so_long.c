/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:16:56 by msacaliu          #+#    #+#             */
/*   Updated: 2024/03/04 11:49:45 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"


char **read_map(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Failed to open file\n");
        exit(1);
    }
    char **map = malloc(MAX_LINES * sizeof(char *));
    for (int i = 0; i < MAX_LINES; i++)
        map[i] = malloc((MAX_LINE_LENGTH + 1) * sizeof(char)); 
    char buffer[MAX_LINE_LENGTH + 1];
    int i = 0;
	int j = 0;
    ssize_t n;
    while ((n = read(fd, &buffer[j], 1)) > 0)
    {
        if (buffer[j] == '\n' || j == MAX_LINE_LENGTH - 1)
        {
            buffer[j] = '\0';
            ft_strcpy(map[i++], buffer);
            j = 0;
        }
        else
            j++;
    }
    if (j > 0) 
    {
        buffer[j] = '\0';
        ft_strcpy(map[i++], buffer);
    }
    map[i] = NULL; 
    close(fd);
    return map;
}


int	main(int argc, char *argv[])
{
	t_data  data;
	data.map = ft_strjoin("./maps/", argv[1]);
	data.map = ft_strjoin(data.map, ".ber");
	data.map2 = read_map(data.map);
    validate_map(&data);
    data.moves = 0;
    data.coins = 0;
    data.mlx_ptr = mlx_init();
    if(!data.mlx_ptr)
        return(1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, find_width(data.map2) * 50, 50 + find_height(data.map2) * 50, "Game");
    if(!data.win_ptr)
    {
        free(data.win_ptr);
        return(1);
    }
    put_player(&data);
    redraw_image(&data);
    mlx_hook(data.win_ptr, 17, 0, close_window, &data);
    mlx_string_put(data.mlx_ptr, data.win_ptr, (find_width(data.map2) *50) / 3, (50 + find_height(data.map2) * 50)- 20, 0x00FF00,"MOVES DONE:");
    mlx_string_put(data.mlx_ptr, data.win_ptr, (find_width(data.map2) *50) / 2, (50 + find_height(data.map2) * 50)- 20, 0x00FF00,"COINS COLECTED:");
    mlx_key_hook(data.win_ptr, handle_input, &data);
    // mlx_loop_hook(data.mlx_ptr, redraw_image, &data);
	mlx_loop(data.mlx_ptr);
}


// 	mlx_hook(cube->screen.win, 2, 1L << 0, key_press, cube);
	// mlx_hook(cube->screen.win, 3, 1L << 1, key_release, cube);
	// mlx_hook(cube->screen.win, 17, 0, close_window, cube);