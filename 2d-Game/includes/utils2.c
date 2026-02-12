/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamimsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:48:04 by ahamimsa          #+#    #+#             */
/*   Updated: 2024/05/04 15:54:26 by ahamimsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initializer(t_map *dt)
{
	dt->x = 0;
	dt->y = 0;
	dt->c_player = 0;
	dt->exit = 0;
	dt->c = 0;
	dt->counter = 0;
	dt->press = 0;
}

void	initializer2(t_map *dt)
{
	dt->x = 0;
	dt->y = 0;
	dt->counter = 0;
	dt->press = 0;
	dt->key = 5;
	dt->reached = 1;
	dt->moves = 0;
}

int	exit_game(t_map *dt, char *s)
{
	perror(s);
	mlx_destroy_window(dt->mlx_ptr, dt->wind);
	exit(1);
}

int	err_msg(char *s)
{
	perror(s);
	return (1);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	lenght;

	lenght = ft_strlen((char *)s) + 1;
	dup = malloc(sizeof(char) * lenght);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, lenght);
	return (dup);
}
