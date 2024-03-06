/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:16:56 by msacaliu          #+#    #+#             */
/*   Updated: 2024/03/06 14:17:00 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

char **copy_map(t_data *data)
{
    int height;
    int width;
    
    height = find_height(data->map2);
    width = find_width(data->map2);
    char **copy = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        copy[i] = malloc(width * sizeof(char));
        for (int j = 0; j < width; j++) {
            copy[i][j] = data->map2[i][j];
        }
    }
    return copy;
}

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
    count_coins(&data);
    ft_printf("total coins %d\n",data.coins_colected);
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
    // char *movess = ft_itoa(data.moves);
    put_player(&data);
    redraw_image(&data,'a');
    mlx_hook(data.win_ptr, 17, 0, close_window, &data);
    mlx_key_hook(data.win_ptr, handle_input, &data);
    // mlx_loop_hook(data.mlx_ptr, redraw_image, &data);
	mlx_loop(data.mlx_ptr);
}


