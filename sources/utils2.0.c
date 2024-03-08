/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:13:06 by msacaliu          #+#    #+#             */
/*   Updated: 2024/03/08 11:25:24 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player_positions(t_data *data, int img_width, int img_height)
{
	data->player_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/right_ninja.xpm", &img_width, &img_height);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/ninja5.xpm", &img_width, &img_height);
	data->player_up = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/up_ninja.xpm", &img_width, &img_height);
	data->player_down = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/down_ninja.xpm", &img_width, &img_height);
}

void	define_characters(t_dfs_data *characters)
{
	characters->has_1 = 0;
	characters->has_e = 0;
	characters->has_c = 0;
	characters->has_p = 0;
}

void	check_characters_nb(t_dfs_data *characters)
{
	if (characters->has_e > 1 || characters->has_p > 1)
	{
		ft_printf("Too many mandatory characters!\n");
		exit(1);
	}
	if (!(characters->has_p && characters->has_e && characters->has_1
			&& characters->has_c))
	{
		ft_printf("Missing mandatory characters!\n");
		exit(1);
	}
}

void	check_if_all_rows_are_equal(t_data *data)
{
	int	i;
	int	row_length;

	row_length = find_width(data->map2);
	i = 0;
	while (data->map2[i] != NULL)
	{
		if (ft_strlen(data->map2[i]) != row_length)
		{
			ft_printf("The rows don't have equal length!\n");
			exit(1);
		}
		i++;
	}
}

void	check_map_interior(t_data *data)
{
	char	*characters;
	int		i;
	int		j;

	i = 0;
	characters = "P,C,1,0,E";
	while (data->map2[i] != NULL)
	{
		j = 0;
		while (data->map2[i][j] != '\0')
		{
			if (ft_strchr(characters, data->map2[i][j]) == NULL)
			{
				ft_printf("Invalid character in the map!\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}
