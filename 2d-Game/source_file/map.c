/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamimsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:57:08 by ahamimsa          #+#    #+#             */
/*   Updated: 2024/05/04 15:57:26 by ahamimsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_element(t_map *dt)
{
	int	i;
	int	j;

	i = 0;
	while (dt->maptiles[i])
	{
		j = 0;
		while (dt->maptiles[i][j])
		{
			if (dt->maptiles[i][j] != '1' && dt->maptiles[i][j] != '0'
				&& dt->maptiles[i][j] != 'P' && dt->maptiles[i][j] != 'C'
				&& dt->maptiles[i][j] != 'E' && dt->maptiles[i][j] != 'X')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_row(t_map *dt)
{
	int		i;
	size_t	len;

	len = strlen(dt->maptiles[0]);
	i = 0;
	while (dt->maptiles[i])
	{
		if (strlen(dt->maptiles[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

char	**addilmap(char **map, char *newline)
{
	int		i;
	int		size;
	char	**updatedmap;

	i = 0;
	size = 0;
	while (map && map[size])
		size++;
	updatedmap = malloc(sizeof(char *) * (size + 2));
	if (!updatedmap)
		return (NULL);
	while (i < size)
	{
		updatedmap[i] = map[i];
		i++;
	}
	updatedmap[i] = newline;
	updatedmap[i + 1] = NULL;
	free(map);
	return (updatedmap);
}

int	mvalidialmap(t_map *dt)
{
	initializer(dt);
	while (dt->maptiles[dt->x])
	{
		dt->y = 0;
		while (dt->maptiles[dt->x][dt->y])
		{
			if (dt->maptiles[dt->x][dt->y] == 'P')
			{
				dt->c_player++;
				dt->player_x = dt->x;
				dt->player_y = dt->y;
			}
			else if (dt->maptiles[dt->x][dt->y] == 'E')
				dt->exit++;
			else if (dt->maptiles[dt->x][dt->y] == 'C')
				dt->c++;
			dt->y++;
		}
		dt->x++;
	}
	if (!check_element(dt) || dt->c_player != 1 || dt->exit != 1 || dt->c < 1
		|| !mvalidiyinlwalls(dt->maptiles, dt) || !mvalidyatri9(dt)
		|| !mvalidyincoll(dt))
		return (0);
	return (1);
}
