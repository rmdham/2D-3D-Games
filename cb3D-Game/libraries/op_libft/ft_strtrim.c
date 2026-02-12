/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloudifa <mloudifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:47:25 by ahamimsa          #+#    #+#             */
/*   Updated: 2025/04/29 16:59:09 by mloudifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_check_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	s;
	size_t	e;
	size_t	i;
	size_t	length;

	if (!s1 || !set)
		return (NULL);
	s = 0;
	while (s1[s] && ft_check_set(s1[s], set) == 1)
		s++;
	e = ft_strlen(s1);
	while (e > s && ft_check_set(s1[e - 1], set) == 1)
		e--;
	length = e - s;
	trimmed = (char *)malloc(sizeof(s1[s]) * (length + 1));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (s < e)
		trimmed[i++] = s1[s++];
	trimmed[i] = 0;
	return (trimmed);
}
