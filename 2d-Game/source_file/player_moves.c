/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamimsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:46:33 by ahamimsa          #+#    #+#             */
/*   Updated: 2024/05/05 09:46:36 by ahamimsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_right(t_map *dt)
{
	dt->player_x++;
	dt->moves++;
	dt->press = 1;
	dt->reached = 0;
	dt->key = D;
}

void	move_left(t_map *dt)
{
	dt->player_x--;
	dt->moves++;
	dt->press = 1;
	dt->reached = 0;
	dt->key = A;
}

void	move_up(t_map *dt)
{
	dt->player_y--;
	dt->moves++;
	dt->press = 1;
	dt->reached = 0;
	dt->key = W;
}

void	move_down(t_map *dt)
{
	dt->player_y++;
	dt->moves++;
	dt->press = 1;
	dt->reached = 0;
	dt->key = S;
}

void	all_moves(int key, t_map *dt)
{
	if (key == D)
		move_right(dt);
	else if (key == A)
		move_left(dt);
	else if (key == W)
		move_up(dt);
	else if (key == S)
		move_down(dt);
}
