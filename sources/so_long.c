/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:16:56 by msacaliu          #+#    #+#             */
/*   Updated: 2024/03/08 11:25:07 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_data *data)
{
	int		height;
	int		width;
	char	**copy;
	int		i;
	int		j;

	height = find_height(data->map2);
	width = find_width(data->map2);
	copy = malloc(height * sizeof(char *));
	i = 0;
	while (i < height)
	{
		copy[i] = malloc(width * sizeof(char));
		j = 0;
		while (j < width)
		{
			copy[i][j] = data->map2[i][j];
			j++;
		}
		i++;
	}
	return (copy);
}

char	**init_map(void)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc(MAX_LINES * sizeof(char *));
	while (i < MAX_LINES)
	{
		map[i] = malloc((MAX_LINE_LENGTH + 1) * sizeof(char));
		if (!map[i])
		{
			while (i >= 0)
				free(map[i--]);
			free(map);
			ft_printf("Failed to allocate memory\n");
			exit(1);
		}
		i++;
	}
	return (map);
}

void	fill_map(int fd, char **map)
{
	char	buffer[MAX_LINE_LENGTH + 1];
	int		i[2];
	ssize_t	n;

	i[X] = 0;
	i[Y] = 0;
	n = read(fd, &buffer[i[Y]], 1);
	while (n > 0)
	{
		if (buffer[i[Y]] == '\n' || i[Y] == MAX_LINE_LENGTH - 1)
		{
			buffer[i[Y]] = '\0';
			ft_strcpy(map[i[X]++], buffer);
			i[Y] = 0;
		}
		else
			i[Y]++;
		n = read(fd, &buffer[i[Y]], 1);
	}
	if (i[Y] > 0)
	{
		buffer[i[Y]] = '\0';
		ft_strcpy(map[i[X]++], buffer);
	}
	map[i[X]] = NULL;
}

char	**read_map(const char *filename)
{
	int		fd;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Failed to open file\n");
		exit(1);
	}
	map = init_map();
	fill_map(fd, map);
	close(fd);
	return (map);
}

int	main(int argc, char *argv[])
{
	t_data		data;
	t_dfs_data	characters;

	(void)argc;
	define_characters(&characters);
	startup(&data, &characters, argv[1]);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, find_width(data.map2) * SIZE,
			find_height(data.map2) * SIZE, "Game");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (1);
	}
	put_player(&data, SIZE, SIZE);
	redraw_image(&data, 'a');
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
	free_map(data.map2, &data);
}
