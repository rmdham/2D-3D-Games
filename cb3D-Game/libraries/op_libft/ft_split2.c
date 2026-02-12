/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloudifa <mloudifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:51:34 by mloudifa          #+#    #+#             */
/*   Updated: 2025/04/29 16:58:57 by mloudifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"


static int	ft_countwords(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == 9 || s[i] == 32))
			i++;
		if (s[i] && (s[i] != 9 && s[i] != 32))
			count++;
		while (s[i] && (s[i] != 9 && s[i] != 32))
			i++;
	}
	return (count);
}

static void	ft_free(char **ret, int p)
{
	int	i;

	i = 0;
	while (i <= p)
	{
		free(ret[i]);
		i++;
	}
	free (ret);
}

static void	ft_storewords(char **ret, char *s)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	p = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == 9 || s[i] == 32))
			i++;
		if (s[i] && (s[i] != 9 && s[i] != 32))
			j = i;
		while (s[i] && (s[i] != 9 && s[i] != 32))
			i++;
		if (i != j)
		{
			ret[p] = ft_substr(s, j, i - j);
			if (!ret[p])
				ft_free(ret, p);
			p++;
		}
	}
}

char	**ft_split2(char const *s)
{
	int		words;
	char	**ret;

	if (s == NULL)
		return (0);
	words = ft_countwords((char *)s);
	ret = malloc((words + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ft_storewords(ret, (char *)s);
	ret[words] = NULL;
	return (ret);
}
