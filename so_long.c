
#include "so_long.h"


// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }



//
char **read_map(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Failed to open file");
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
            strcpy(map[i++], buffer);
            j = 0;
        }
        else
            j++;
    }
    if (j > 0) 
    {
        buffer[j] = '\0';
        strcpy(map[i++], buffer);
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
	char **map = read_map(data.map);

    data.mlx_ptr = mlx_init();
    if(!data.mlx_ptr)
        return(1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, find_width(map) * 50, find_height(map) * 50, "Game");
    if(!data.win_ptr)
    {
        free(data.win_ptr);
        return(1);
    }
    draw_floor(&data);
    draw_wall(&data);
	put_player(&data);
	draw_coin(&data);
	put_door(&data);
    mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
}


