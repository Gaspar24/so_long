/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:54:11 by msacaliu          #+#    #+#             */
/*   Updated: 2024/03/06 13:44:22 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int find_width(char **map)
{
	int i = 0;
	int j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
			j++;
		i++;
	}
	return (j);
}

int	find_height(char **map)
{
	int i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
	
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*new_string;
	int		suf;

	i = 0;
	new_string = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_string)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	suf = i;
	i = 0;
	while (s2[i] != '\0')
	{
		new_string[suf] = s2[i];
		i++;
		suf++;
	}
	new_string[suf] = '\0';
	return (new_string);
}

char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

int	count_digitss(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count += 1;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*number_str;
	int			d_count;
	int			i;
	long long	temp;

	d_count = count_digitss(n);
	temp = n;
	i = d_count;
	number_str = (char *)malloc((d_count +1) * sizeof(char));
	if (!number_str)
		return (NULL);
	if (temp == 0)
		number_str[0] = '0';
	while (temp != 0)
	{
		if (temp < 0)
		{
			number_str[0] = '-';
			temp = -temp;
		}
		number_str[(i--) - 1] = (temp % 10) + '0';
		temp = temp / 10;
	}
	number_str[d_count] = '\0';
	return (number_str);
}