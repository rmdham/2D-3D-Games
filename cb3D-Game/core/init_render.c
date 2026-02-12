/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloudifa <mloudifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:16:49 by mloudifa          #+#    #+#             */
/*   Updated: 2025/05/06 08:52:47 by mloudifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	render_3d_scene(t_game *g)
{
	int		i;
	float	raydistance;

	i = 0;
	g->projdistance = (float)(W_WIDTH / 2) / tan(FOV / 2);
	while (i < W_WIDTH)
	{
		raydistance = g->rays.ray_distance[i] \
			* cos(g->rays.rayangle[i] - g->player.player_angle);
		g->wall_height = (DISP_SIZE / raydistance) * g->projdistance;
		g->sky_size = (W_HEIGHT / 2.0) - (g->wall_height / 2.0);
		g->floor_size = (W_HEIGHT / 2.0) + (g->wall_height / 2.0);
		g->wall_index = g->wall_height;
		if (g->wall_height > W_HEIGHT)
			g->wall_height = W_HEIGHT;
		draw_sky(g, i, g->sky_size);
		draw_wall(g, i, g->sky_size, g->wall_height);
		draw_floor(g, i, g->floor_size, g->wall_height);
		i++;
	}
	return (0);
}

int	update_player(t_game *g)
{
	float	step;
	float	cstep;

	g->player.player_angle += g->player.turn_dir * g->player.rotation_speed;
	step = (float)g->player.walk_dir * g->player.velo;
	cstep = (float)g->player.cwalk_dir * g->player.velo;
	if (!collided_wall(g->player.xpos, g->player.ypos, g, 0))
	{
		if (step != 0)
		{
			g->player.xpos += cos(g->player.player_angle) * step;
			g->player.ypos += sin(g->player.player_angle) * step;
		}
		if (g->player.cwalk_dir == 1 || g->player.cwalk_dir == -1)
		{
			g->player.xpos += cos(g->player.player_angle + M_PI_2) * cstep;
			g->player.ypos += sin(g->player.player_angle + M_PI_2) * cstep;
		}
	}
	render_3d_scene(g);
	cast_rays(g);
	mlx_put_image_to_window(g->data.mlx, g->data.mlx_win, \
	g->data.img, 0, 0);
	return (0);
}

int init_rendering(t_game *game)
{
    game->data.img = mlx_new_image(game->data.mlx, W_WIDTH, \
        W_HEIGHT);
        game->data.addr = mlx_get_data_addr(game->data.img \
        , &game->data.bits_per_pixel, &game->data.line_length, &game->data.endian);
        game->surface_scale = 20.0 / (game->map_w * game->map_h);
        if (game->surface_scale > 0.4)
            game->surface_scale = 0.4;
        render_player(game ,&game->player);
        cast_rays(game);
    return (0);
    
}