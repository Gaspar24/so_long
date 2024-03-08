/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:42:22 by msacaliu          #+#    #+#             */
/*   Updated: 2024/03/08 11:25:35 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = c % 256;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *) s + i);
		i++;
	}
	if (c == '\0')
		return ((char *) s + i);
	return (NULL);
}

void	free_map(char **map, t_data *data)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	free(data->map);
	free(data->mlx_ptr);
	free(data->win_ptr);
}

void	startup(t_data *data, t_dfs_data *characters, char *str)
{
	data->map = ft_strjoin("./maps/", str);
	data->map = ft_strjoin(data->map, ".ber");
	data->map2 = read_map(data->map);
	validate_map(data, characters);
	count_coins(data);
	data->moves = 0;
	data->coins = 0;
}
