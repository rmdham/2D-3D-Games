/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloudifa <mloudifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:05:31 by slouham           #+#    #+#             */
/*   Updated: 2025/04/29 16:49:55 by mloudifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_line(t_cube *s_pars, char *str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
	{
		if (str[i] == 9)
			func_error("Remove tab from your map");
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 32
			&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W'
			&& str[i] != '\n')
			func_error("Different character");
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
		{
			if (s_pars->player_exit == 1)
				func_error("player duplicate");
			else
				s_pars->player_exit = 1;
		}
	}
}

int	valid_char(char	**map_2d, int i, int j)
{
	if ((map_2d[i - 1][j] != '1' && map_2d[i - 1][j] != 'N' &&
		map_2d[i - 1][j] != 'S' && map_2d[i - 1][j] != 'E' &&
		map_2d[i - 1][j] != 'W' && map_2d[i - 1][j] != '0')
		|| (map_2d[i + 1][j] != '1' && map_2d[i + 1][j] != 'N' &&
		map_2d[i + 1][j] != 'S' && map_2d[i + 1][j] != 'E' &&
		map_2d[i + 1][j] != 'W' && map_2d[i + 1][j] != '0')
		|| ((map_2d[i][j - 1] != '1' && map_2d[i][j - 1] != 'N' &&
		map_2d[i][j - 1] != 'S' && map_2d[i][j - 1] != 'E' &&
		map_2d[i][j - 1] != 'W' && map_2d[i][j - 1] != '0'))
		|| ((map_2d[i][j + 1] != '1' && map_2d[i][j + 1] != 'N' &&
		map_2d[i][j + 1] != 'S' && map_2d[i][j + 1] != 'E' &&
		map_2d[i][j + 1] != 'W' && map_2d[i][j + 1] != '0')))
		return (1);
	return (0);
}

void	flood_fill(char **map_2d)
{
	int	i;
	int	j;

	i = 0;
	while (map_2d[++i])
	{
		j = 0;
		while (map_2d[i][j])
		{
			if (map_2d[i][j] == '0')
			{
				if (valid_char(map_2d, i, j))
					func_error("Map not valid");
			}
			j++;
		}
	}
}

void	check_walls_characters(char **map_2d)
{
	int		i;
	char	*temp1;

	i = 0;
	is_it_full_walls(map_2d[0]);
	while (map_2d[++i])
	{
		temp1 = ft_strtrim(map_2d[i], " ");
		if (temp1[0] != '1' || temp1[ft_strlen(temp1) - 1] != '1')
			func_error("Map not closed");
		free(temp1);
	}
	is_it_full_walls(map_2d[i - 1]);
	flood_fill(map_2d);
}

void	parse_map(t_cube *s_pars, char *temp1)
{
	char	*join_str;
	char	*temp2;

	join_str = malloc(1);
	join_str[0] = '\0';
	while (temp1)
	{
		temp2 = join_str;
		join_str = ft_strjoin(join_str, temp1);
		free(temp1);
		free(temp2);
		temp1 = get_next_line(s_pars->fd);
		check_line(s_pars, temp1);
	}
	if (s_pars->player_exit == 0)
		func_error("Check your Player");
	free(temp1);
	check_free_lines(join_str);
	s_pars->map_2d = ft_split(join_str, '\n');
	check_walls_characters(s_pars->map_2d);
	free(join_str);
}
