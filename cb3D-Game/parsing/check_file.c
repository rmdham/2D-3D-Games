/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloudifa <mloudifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:03:04 by slouham           #+#    #+#             */
/*   Updated: 2025/04/29 16:51:00 by mloudifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	empty_line(char	*str)
{
	while (*str)
	{
		if (*str != 32 && *str != 9 && *str != '\n')
			return (0);
		str++;
	}
	return (1);
}

void	is_it_full_walls(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '1' && str[i] != 32)
			func_error("First or last line not valid");
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!str1 || !str2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (str1[i] != str2[i])
			break ;
		i++;
	}
	if (str1[i] > str2[i])
		return (1);
	else if (str1[i] < str2[i])
		return (-1);
	return (0);
}

int	check_file_name(char *str)
{
	int	i;
	int	num_point;
	int	fd;

	i = -1;
	num_point = 0;
	if (str[0] == '\0')
		func_error("File format is not .cub");
	while (str[++i])
	{
		if (str[i] == '.' && str[i + 1] && str[i + 1] != '/')
			num_point++;
	}
	if (num_point != 1)
		func_error("File format is not .cub");
	if (ft_strcmp(str + ft_strlen(str) - 4, ".cub") != 0)
		func_error("File format is not .cub");
	fd = open(str, O_RDONLY);
	if (fd == -1)
		func_error("Open failed");
	return (fd);
}
