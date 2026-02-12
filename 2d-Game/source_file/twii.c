/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twii.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamimsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:47:36 by ahamimsa          #+#    #+#             */
/*   Updated: 2024/05/05 09:47:43 by ahamimsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	anime_right(t_map *dt)
{
	static int	j;

	if (j <= 0)
		j = 50;
	j -= 5;
	if (dt->frame_counter % 2 == 0)
	{
		IMAGE(dt->mlx_ptr, dt->wind, dt->ply_rt, (dt->player_x * TW + 0) - j,
			dt->player_y * TH);
	}
	else
	{
		IMAGE(dt->mlx_ptr, dt->wind, dt->ply_rt1, (dt->player_x * TW + 0)
			- j, dt->player_y * TH);
	}
	if (j <= 0)
	{
		dt->press = 0;
		dt->reached = 1;
		j = 0;
	}
}

void	anime_left(t_map *dt)
{
	static int	j;

	if (j <= 0)
		j = 50;
	j -= 5;
	if (dt->frame_counter % 2 == 0)
	{
		IMAGE(dt->mlx_ptr, dt->wind, dt->ply_lf, (dt->player_x * TW) + j,
			dt->player_y * TH);
	}
	else
	{
		IMAGE(dt->mlx_ptr, dt->wind, dt->ply_lf1, (dt->player_x * TW) + j,
			dt->player_y * TH + 0);
	}
	if (j <= 0)
	{
		dt->press = 0;
		dt->reached = 1;
		j = 0;
	}
}

void	anime_up(t_map *dt)
{
	static int	j;

	if (j <= 0)
		j = 50;
	j -= 5;
	if (dt->frame_counter % 2 == 0)
	{
		IMAGE(dt->mlx_ptr, dt->wind, dt->ply_up, dt->player_x * TW + 0,
			(dt->player_y * TH + 0) + j);
	}
	else
	{
		IMAGE(dt->mlx_ptr, dt->wind, dt->ply_up1, dt->player_x * TW + 0,
			(dt->player_y * TH + 0) + j);
	}
	if (j <= 0)
	{
		dt->press = 0;
		dt->reached = 1;
		j = 0;
	}
}

void	anime_down(t_map *dt)
{
	static int	j;

	if (j <= 0)
		j = 50;
	j -= 5;
	if (dt->frame_counter % 2 == 0)
	{
		IMAGE(dt->mlx_ptr, dt->wind, dt->ply_dn, dt->player_x * TW + 0,
			(dt->player_y * TH + 0) - j);
	}
	else
	{
		IMAGE(dt->mlx_ptr, dt->wind, dt->ply_dn1, dt->player_x * TW + 0,
			(dt->player_y * TH + 0) - j);
	}
	if (j <= 0)
	{
		dt->press = 0;
		dt->reached = 1;
		j = 0;
	}
}

void	player_anime(t_map *dt)
{
	if (!dt->press && dt->key == D)
		IMAGE(dt->mlx_ptr, dt->wind, dt->ply_rt, (dt->player_x * TW),
			dt->player_y * TH);
	if (!dt->press && dt->key == A)
		IMAGE(dt->mlx_ptr, dt->wind, dt->ply_lf, (dt->player_x * TW + 0),
			dt->player_y * TH + 0);
	if (!dt->press && dt->key == W)
		IMAGE(dt->mlx_ptr, dt->wind, dt->ply_up, (dt->player_x * TW + 0),
			dt->player_y * TH + 0);
	if (!dt->press && dt->key == S)
		IMAGE(dt->mlx_ptr, dt->wind, dt->ply_dn, (dt->player_x * TW + 0),
			dt->player_y * TH + 0);
	else if (dt->press && dt->key == D)
		anime_right(dt);
	else if (dt->press && dt->key == A)
		anime_left(dt);
	else if (dt->press && dt->key == W)
		anime_up(dt);
	else if (dt->press && dt->key == S)
		anime_down(dt);
}
