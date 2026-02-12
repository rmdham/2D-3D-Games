/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamimsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:59:55 by ahamimsa          #+#    #+#             */
/*   Updated: 2024/05/05 10:41:38 by ahamimsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	set_game(t_map *dt)
{
	initializer2(dt);
	dt->ply_up = XPM(dt->mlx_ptr, "../assets/player_up.xpm", &dt->x, &dt->y);
	dt->ply_up1 = XPM(dt->mlx_ptr, "../assets/player_up1.xpm", &dt->x, &dt->y);
	dt->ply_rt = XPM(dt->mlx_ptr, "../assets/player_rt.xpm", &dt->x, &dt->y);
	dt->ply_rt1 = XPM(dt->mlx_ptr, "../assets/player_rt1.xpm", &dt->x, &dt->y);
	dt->ply_lf = XPM(dt->mlx_ptr, "../assets/player_lf.xpm", &dt->x, &dt->y);
	dt->ply_lf1 = XPM(dt->mlx_ptr, "../assets/player_lf1.xpm", &dt->x, &dt->y);
	dt->ply_dn = XPM(dt->mlx_ptr, "../assets/player_dn.xpm", &dt->x, &dt->y);
	dt->ply_dn1 = XPM(dt->mlx_ptr, "../assets/player_dn1.xpm", &dt->x, &dt->y);
	dt->enemy = XPM(dt->mlx_ptr, "../assets/enemy.xpm", &dt->x, &dt->y);
	dt->enemy1 = XPM(dt->mlx_ptr, "../assets/enemy1.xpm", &dt->x, &dt->y);
	dt->collect = XPM(dt->mlx_ptr, "../assets/collect.xpm", &dt->x, &dt->y);
	dt->ground = XPM(dt->mlx_ptr, "../assets/ground.xpm", &dt->x, &dt->y);
	dt->wall = XPM(dt->mlx_ptr, "../assets/wall.xpm", &dt->x, &dt->y);
	dt->exit_pic = XPM(dt->mlx_ptr, "../assets/exit_pic.xpm", &dt->x, &dt->y);
	dt->exit1_pic = XPM(dt->mlx_ptr, "../assets/exit1_pic.xpm", &dt->x, &dt->y);
	if (!dt->ply_up || !dt->ply_up1 || !dt->ply_rt || !dt->ply_rt1
		|| !dt->ply_lf || !dt->ply_lf1 || !dt->ply_dn
		|| !dt->ply_dn1 || !dt->enemy || !dt->enemy1 || !dt->collect
		|| !dt->ground || !dt->wall || !dt->exit_pic || !dt->exit1_pic)
		exit_game(dt, "failed to load images");
	return (1);
}

int	draw_ground(t_map *dt)
{
	int	x;
	int	y;

	x = 0;
	while (x < dt->height)
	{
		y = 0;
		while (y < dt->width)
		{
			if (dt->maptiles[x][y] == '1')
				IMAGE(dt->mlx_ptr, dt->wind, dt->wall, y * 50, x * 50);
			else
				IMAGE(dt->mlx_ptr, dt->wind, dt->ground, y * 50, x * 50);
			y++;
		}
		x++;
	}
	return (1);
}

int	draw_game(t_map *d)
{
	d->x = 0;
	while (d->x < d->height)
	{
		d->y = 0;
		while (d->y < d->width)
		{
			if (d->moves == 0)
				IMAGE(d->mlx_ptr, d->wind, d->ply_dn, d->player_x * TW,
					d->player_y * TH);
			if (d->maptiles[d->x][d->y] == '0')
				IMAGE(d->mlx_ptr, d->wind, d->ground, d->y * TW, d->x * TH);
			else if (d->maptiles[d->x][d->y] == '1')
				IMAGE(d->mlx_ptr, d->wind, d->wall, d->y * TW, d->x * TH);
			else if (d->maptiles[d->x][d->y] == 'E')
				exit_anime(d);
			else if (d->maptiles[d->x][d->y] == 'C')
				IMAGE(d->mlx_ptr, d->wind, d->collect, d->y * TW, d->x * TH);
			else if (d->maptiles[d->x][d->y] == 'X')
				IMAGE(d->mlx_ptr, d->wind, d->enemy, d->y * TW, d->x * TH);
			d->y++;
		}
		d->x++;
	}
	player_anime(d);
	return (1);
}

int	set_player(t_map *dt)
{
	int	x;
	int	y;

	x = 0;
	while (x < dt->height)
	{
		y = 0;
		while (y < dt->width)
		{
			if (dt->maptiles[x][y] == 'P')
			{
				dt->player_x = y;
				dt->player_y = x;
				dt->maptiles[x][y] = '0';
				return (1);
			}
			y++;
		}
		x++;
	}
	dt->start_x = dt->player_x;
	dt->start_y = dt->player_y;
	return (0);
}

int	window_init(t_map *dt)
{
	int	wx;
	int	wy;

	wx = dt->width * 50;
	wy = dt->height * 50;
	dt->mlx_ptr = mlx_init();
	dt->wind = WINDOW(dt->mlx_ptr, wx, wy, "So Long");
	if (!dt->mlx_ptr || !dt->wind)
		return (0);
	mlx_hook(dt->wind, ON_DESTROY, 0, exit_game, dt);
	if (!set_game(dt))
		err_msg("game not set\n");
	if (!draw_ground(dt))
		err_msg("failed to draw ground\n");
	set_player(dt);
	mlx_hook(dt->wind, 2, 0, ft_key_hook, dt);
	mlx_loop_hook(dt->mlx_ptr, animation, dt);
	mlx_loop(dt->mlx_ptr);
	return (1);
}
