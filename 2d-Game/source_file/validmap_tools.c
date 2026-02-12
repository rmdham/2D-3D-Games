/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamimsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:00:04 by ahamimsa          #+#    #+#             */
/*   Updated: 2024/05/05 09:49:18 by ahamimsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	mvalidiyinlwalls(char **map, t_map *dt)
{
	int	i;
	int	size;

	size = 0;
	while (map[size])
		size++;
	i = 0;
	while (map[0][i] && map[size - 1][i])
	{
		if (map[0][i] != '1' || map[size - 1][i] != '1')
			return (0);
		i++;
	}
	dt->width = i;
	i = 0;
	while (i < size)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 1] != '1')
			return (0);
		i++;
	}
	dt->height = i;
	return (1);
}

int	dfs(t_map *data, int x, int y, int **visited)
{
	if (x < 0 || x >= data->height || y < 0 || y >= data->width
		|| data->maptiles[x][y] == '1' || visited[x][y])
		return (0);
	if (data->maptiles[x][y] == 'E')
		return (1);
	visited[x][y] = 1;
	if (dfs(data, x + 1, y, visited) || dfs(data, x - 1, y, visited)
		|| dfs(data, x, y + 1, visited) || dfs(data, x, y - 1, visited))
		return (1);
	return (0);
}

int	dfss(t_map *data, int x, int y, int **visited)
{
	if (x < 0 || x >= data->height || y < 0 || y >= data->width
		|| data->maptiles[x][y] == '1' || visited[x][y])
		return (0);
	if (data->maptiles[x][y] == 'C')
		data->count--;
	if (data->count == 0)
		return (1);
	visited[x][y] = 1;
	if (dfss(data, x + 1, y, visited) || dfss(data, x - 1, y, visited)
		|| dfss(data, x, y + 1, visited) || dfss(data, x, y - 1, visited))
		return (1);
	return (0);
}

int	mvalidyatri9(t_map *dt)
{
	dt->visited = malloc(sizeof(int *) * dt->height);
	if (!dt->visited)
		return (0);
	dt->i = 0;
	while (dt->i < dt->height)
	{
		dt->visited[dt->i] = malloc(sizeof(int) * dt->width);
		if (!dt->visited[dt->i])
			return (0);
		dt->j = 0;
		while (dt->j < dt->width)
		{
			dt->visited[dt->i][dt->j++] = 0;
		}
		dt->i++;
	}
	dt->result = dfs(dt, dt->player_x, dt->player_y, dt->visited);
	dt->i = 0;
	while (dt->i < dt->height)
	{
		free(dt->visited[dt->i++]);
	}
	free(dt->visited);
	return (dt->result);
}

int	mvalidyincoll(t_map *dt)

{
	dt->count = dt->c;
	dt->visited = malloc(sizeof(int *) * dt->height);
	if (!dt->visited)
		return (0);
	dt->i = 0;
	while (dt->i < dt->height)
	{
		dt->visited[dt->i] = malloc(sizeof(int) * dt->width);
		if (!dt->visited[dt->i])
			return (0);
		dt->j = 0;
		while (dt->j < dt->width)
		{
			dt->visited[dt->i][dt->j++] = 0;
		}
		dt->i++;
	}
	dt->result = dfss(dt, dt->player_x, dt->player_y, dt->visited);
	dt->i = 0;
	while (dt->i < dt->height)
	{
		free(dt->visited[dt->i++]);
	}
	free(dt->visited);
	return (dt->result);
}
