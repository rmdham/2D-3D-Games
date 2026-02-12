/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_anime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamimsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:28:25 by ahamimsa          #+#    #+#             */
/*   Updated: 2024/05/05 11:29:14 by ahamimsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_anime(t_map *d)
{
	if (d->c != 0)
		IMAGE(d->mlx_ptr, d->wind, d->exit_pic, d->y * TW, d->x
			* TH);
	else
		IMAGE(d->mlx_ptr, d->wind, d->exit1_pic, d->y * TW, d->x
			* TH);
}

void	ft_free(t_map *dt)
{
	int	i;

	i = 0;
	while (i < dt->height)
		free(dt->maptiles[i++]);
	mlx_destroy_window(dt->mlx_ptr, dt->wind);
	mlx_destroy_image(dt->mlx_ptr, dt->ply_up);
	mlx_destroy_image(dt->mlx_ptr, dt->ply_up1);
	mlx_destroy_image(dt->mlx_ptr, dt->ply_rt);
	mlx_destroy_image(dt->mlx_ptr, dt->ply_rt1);
	mlx_destroy_image(dt->mlx_ptr, dt->ply_lf);
	mlx_destroy_image(dt->mlx_ptr, dt->ply_lf1);
	mlx_destroy_image(dt->mlx_ptr, dt->ply_dn);
	mlx_destroy_image(dt->mlx_ptr, dt->ply_dn1);
	mlx_destroy_image(dt->mlx_ptr, dt->enemy);
	mlx_destroy_image(dt->mlx_ptr, dt->enemy1);
	mlx_destroy_image(dt->mlx_ptr, dt->collect);
	mlx_destroy_image(dt->mlx_ptr, dt->ground);
	mlx_destroy_image(dt->mlx_ptr, dt->wall);
	mlx_destroy_image(dt->mlx_ptr, dt->exit_pic);
	mlx_destroy_image(dt->mlx_ptr, dt->exit1_pic);
	free(dt->maptiles);
	free(dt);
}
