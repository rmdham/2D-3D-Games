/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloudifa <mloudifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 08:43:56 by mloudifa          #+#    #+#             */
/*   Updated: 2025/05/06 09:34:11 by mloudifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_player(t_player *player)
{
	player->turn_dir = 0;
	player->walk_dir = 0;
	player->velo = 1.5;
	player->rotation_speed = (M_PI / 200);
}

void	draw_sky(t_game *g, int x, int skysize)
{
	int	y;

	y = 0;
	while (y < skysize)
	{
		my_put_pixel(&g->data, x, y, 0x000000);
		y++;
	}
}

void	draw_wall(t_game *g, int x, int skysize, int wallheight)
{
	int	y;

	(void)wallheight;
	y = skysize;
	while (y < W_HEIGHT)
	{
		if (y >= 0 && y < W_HEIGHT)
		{
			if (g->rays.ray_direction[x] == NORTH)
				fetch_pixel_from_texture(g, x, y, N_IDX);
			else if (g->rays.ray_direction[x] == SOUTH)
				fetch_pixel_from_texture(g, x, y, S_IDX);
			else if (g->rays.ray_direction[x] == WEST)
				fetch_pixel_from_texture(g, x, y, W_IDX);
			else if (g->rays.ray_direction[x] == EAST)
				fetch_pixel_from_texture(g, x, y, E_IDX);
		}
		y++;
	}
}

void	draw_floor(t_game *g, int x, double fsize, double wheight)
{
	double	y;

	(void)wheight;
	y = fsize;
	while (y < W_HEIGHT)
	{
		if (y >= 0 && y < W_HEIGHT)
			my_put_pixel(&g->data, x, y, g->data.f);
		y++;
	}
}
