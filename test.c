
// #include "so_long.h"

// #define MAX_LINE_LENGTH 100
// #define MAX_LINES 100



// char **read_map(const char *filename)
// {
//     int fd = open(filename, O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Failed to open file");
//         exit(1);
//     }
//     char **map = malloc(MAX_LINES * sizeof(char *));
//     for (int i = 0; i < MAX_LINES; i++)
//         map[i] = malloc((MAX_LINE_LENGTH + 1) * sizeof(char)); 
//     char buffer[MAX_LINE_LENGTH + 1];
//     int i = 0, j = 0;
//     ssize_t n;
//     while ((n = read(fd, &buffer[j], 1)) > 0)
//     {
//         if (buffer[j] == '\n' || j == MAX_LINE_LENGTH - 1)
//         {
//             buffer[j] = '\0';
//             strcpy(map[i++], buffer);
//             j = 0;
//         }
//         else
//             j++;
//     }
//     if (j > 0) 
//     {
//         buffer[j] = '\0';
//         strcpy(map[i++], buffer);
//     }
//     map[i] = NULL; // mark the end of the map
//     close(fd);
//     return map;
// }

// // int main(void)
// // {
// //     int i = 0;
// //     char **map = read_map("./maps/map.ber");
// //     while (map[i] != NULL)
// //     {
// //         printf("%s\n", map[i]);
// //         i++;
// //     }
// //     return 0;
// // }

// #include "so_long.h"
// #include <stdio.h>

// int find_width(char **map)
// {
// 	int i = 0;
// 	int j = 0;
// 	while (map[i] != NULL)
// 	{
// 		while (map[i][j] != '\0')
// 			j++;
// 		i++;
// 	}
// 	return (j);
// }

// int fin_height(char **map)
// {
// 	int i = 0;
// 	while (map[i] != NULL)
// 		i++;
// 	return (i);
// }

// int main(void)
// {
// 	char **map = read_map("./maps/map.ber");
// 	int width = find_width(map);
// 	int height = fin_height(map);
// 	printf("width: %d\n", width);
// 	printf("height: %d\n", height);
// 	return 0;
// }