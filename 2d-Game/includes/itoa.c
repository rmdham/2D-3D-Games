/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamimsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:35:16 by ahamimsa          #+#    #+#             */
/*   Updated: 2024/05/04 15:35:32 by ahamimsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sorc;
	size_t	i;

	if (dst == src)
		return (dst);
	if (!dst && !src)
		return (NULL);
	dest = (char *)dst;
	sorc = (char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = sorc[i];
		i++;
	}
	return (dest);
}

size_t	count_word_str(long nb)
{
	size_t	len;

	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	if (nb == 0)
	{
		len++;
		return (len);
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	*allocation_str(size_t len)
{
	char	*str;

	str = (char *)malloc(len + 1);
	if (!(str))
		return (NULL);
	return (str);
}

char	*if_zero(char *str)
{
	str[0] = 48;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_word_str((long)n);
	str = allocation_str(len);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		if_zero(str);
	while (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	while (n > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}
