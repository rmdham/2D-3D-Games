/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloudifa <mloudifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:42:34 by slouham           #+#    #+#             */
/*   Updated: 2025/05/06 08:53:17 by mloudifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	close_window(void *param)
{
	(void)param;
	exit (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.data.mlx = mlx_init();
	parsing(&game, argc, argv);
	game.data.mlx_win = mlx_new_window(game.data.mlx, W_WIDTH,
			W_HEIGHT, "Cub3D");
	mlx_hook(game.data.mlx_win, 17, 0, close_window, &game.data);
	init_rendering(&game);
	mlx_hook(game.data.mlx_win, 2, 1L << 0, key_press, &game.data);
	mlx_hook(game.data.mlx_win, 3, 1L << 1, key_release, &game.data);
	mlx_loop_hook(game.data.mlx, &update_player, &game);
	mlx_loop(game.data.mlx);
	return (0);
}
