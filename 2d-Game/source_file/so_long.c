/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamimsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:22:56 by ahamimsa          #+#    #+#             */
/*   Updated: 2024/05/05 09:23:03 by ahamimsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_playermovement(int keycode, t_map *dt)
{
	int	old_x;
	int	old_y;

	old_x = dt->player_x;
	old_y = dt->player_y;
	all_moves(keycode, dt);
	if (dt->player_x < 0 || dt->player_x >= dt->width || dt->player_y < 0
		|| dt->player_y >= dt->height
		|| dt->maptiles[dt->player_y][dt->player_x] == '1')
	{
		dt->player_x = old_x;
		dt->player_y = old_y;
	}
	if (dt->maptiles[dt->player_y][dt->player_x] == 'X')
		exit_game(dt, "You Lose");
	if (dt->maptiles[dt->player_y][dt->player_x] == 'C')
	{
		dt->c--;
		dt->maptiles[dt->player_y][dt->player_x] = '0';
		draw_ground(dt);
	}
	if (dt->maptiles[dt->player_y][dt->player_x] == 'E' && dt->c == 0)
		exit_game(dt, "You Won");
	draw_ground(dt);
	draw_game(dt);
}

int	ft_key_hook(int keycode, t_map *dt)
{
	if (dt->reached == 1)
	{
		if (keycode == W && dt->maptiles[dt->player_y - 1][dt->player_x] != '1')
			ft_playermovement(W, dt);
		else if (keycode == S
			&& dt->maptiles[dt->player_y + 1][dt->player_x] != '1')
			ft_playermovement(S, dt);
		else if (keycode == A && dt->maptiles[dt->player_y][dt->player_x
			- 1] != '1')
			ft_playermovement(A, dt);
		else if (keycode == D && dt->maptiles[dt->player_y][dt->player_x
			+ 1] != '1')
			ft_playermovement(D, dt);
		printf("Moves : %d\n", dt->moves);
	}
	if (keycode == ESC)
		exit_game(dt, "You Exited Game");
	return (0);
}

int	animation(t_map *dt)
{
	char	*n;

	n = ft_itoa(dt->moves);
	dt->frame_counter++;
	draw_game(dt);
	mlx_string_put(dt->mlx_ptr, dt->wind, 50, 50, 0xFFFF00, "Moves Number : ");
	mlx_string_put(dt->mlx_ptr, dt->wind, 210, 50, 0xFFFF00,
		ft_itoa(dt->moves));
	free(n);
	return (0);
}

int	error_mssg(char *s)
{
	perror(s);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	dt;
	int		fd;
	char	*line;

	dt.maptiles = NULL;
	if ((argc != 2) || !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		return (err_msg("arg error or missin file"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (err_msg("failed to open"));
	line = get_next_line(fd);
	while (line)
	{
		dt.maptiles = addilmap(dt.maptiles, line);
		line = get_next_line(fd);
	}
	if (!dt.maptiles)
		return (err_msg("no map"));
	if (!mvalidialmap(&dt) || !check_row(&dt))
		return (err_msg("invalid map or row"));
	if (!window_init(&dt))
		return (err_msg("failed to init window"));
	ft_free(&dt);
	close(fd);
	return (0);
}
