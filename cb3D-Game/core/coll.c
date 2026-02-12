/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coll.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloudifa <mloudifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 08:46:50 by mloudifa          #+#    #+#             */
/*   Updated: 2025/05/06 09:38:25 by mloudifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

unsigned int	my_pixel_get(t_textures *text, int x, int y)
{
	char	*dst;

	if (x < 0 || x > text->w)
		return (0);
	if (y < 0 || y > text->h)
		return (0);
	dst = text->addr + (y * text->tline_length + x * (text->tbbp / 8));
	return (*(unsigned int *) dst);
}

void	fetch_pixel_from_texture(t_game *g, int x, int y, int dir)
{
	int		color;
	double	tx;
	double	ty;
	double	text_scale;

	tx = 0;
	ty = 0;
	text_scale = (double)g->arr_text[dir].h / g->wall_index;
	if (dir == N_IDX || dir == S_IDX)
	{
		tx = (((int)g->rays.inter_x[x] % DISP_SIZE) * \
		g->arr_text[dir].w) / DISP_SIZE; 
		ty = (y - g->sky_size) * text_scale;
	}
	if (dir == E_IDX || dir == W_IDX)
	{
		tx = (((int)g->rays.inter_y[x] % DISP_SIZE) * \
		g->arr_text[dir].w) / DISP_SIZE;
		ty = (y - g->sky_size) * text_scale;
	}
	color = my_pixel_get(&g->arr_text[dir], tx, ty);
	my_put_pixel(&g->data, x, y, color);
}

int	check_collision(float x, float y, t_game *g)
{
	int	map_x;
	int	map_y;
	int	buff_x;
	int	buff_y;

	buff_x = floor((x + (DISP_SIZE / 9)) / DISP_SIZE);
	buff_y = floor((y + (DISP_SIZE / 9)) / DISP_SIZE);
	map_x = floor(x / DISP_SIZE);
	map_y = floor(y / DISP_SIZE);
	if (g->map[buff_y][buff_x] == '1')
		return (1);
	buff_x = floor((x - (DISP_SIZE / 9)) / DISP_SIZE);
	buff_y = floor((y + (DISP_SIZE / 9)) / DISP_SIZE);
	if (g->map[buff_y][buff_x] == '1')
		return (1);
	buff_x = floor((x - (DISP_SIZE / 9)) / DISP_SIZE);
	buff_y = floor((y - (DISP_SIZE / 9)) / DISP_SIZE);
	if (g->map[buff_y][buff_x] == '1')
		return (1);
	buff_x = floor((x + (DISP_SIZE / 9)) / DISP_SIZE);
	buff_y = floor((y - (DISP_SIZE / 9)) / DISP_SIZE);
	if (g->map[buff_y][buff_x] == '1')
		return (1);
	return ((g->map[map_y][map_x] == '1'));
}

int	check_ray_collision(float x, float y, t_game *g)
{
	int	map_x;
	int	map_y;

	map_x = floor(x / DISP_SIZE);
	map_y = floor(y / DISP_SIZE);
	return (g->map[map_y][map_x] == '1' \
			|| g->map[map_y][map_x] == '\n' \
			|| g->map[map_y][map_x] == '\0' \
			|| g->map[map_y][map_x] == ' ' );
}

int	collided_wall(float x, float y, t_game *g, int mode)
{
	float	step;
	float	cstep;
	float	p_angle;

	p_angle = g->player.player_angle + g->player.turn_dir * \
		g->player.rotation_speed;
	step = (float)g->player.walk_dir * g->player.velo;
	cstep = (float)g->player.cwalk_dir * g->player.velo;
	if (mode == 0 && step != 0)
	{
		x += cos(p_angle) * step;
		y += sin(p_angle) * step;
	}
	if (mode == 0 && (g->player.cwalk_dir == 1 || g->player.cwalk_dir == -1))
	{
		x += cos(p_angle + M_PI_2) * cstep;
		y += sin(p_angle + M_PI_2) * cstep;
	}
	if (mode == 0)
		return (check_collision(x, y, g));
	else
		return (check_ray_collision(x, y, g));
}
