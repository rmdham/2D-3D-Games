/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloudifa <mloudifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:24:56 by alaaouar          #+#    #+#             */
/*   Updated: 2025/04/29 16:56:31 by mloudifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*ft_read(int fd, char *buf)
{
	char	*new_buf;
	ssize_t	r;

	r = 1;
	new_buf = malloc(BUFFER_SIZE + 1);
	if (!new_buf)
		return (NULL);
	while (r != 0 && !ft_strchr_gnl(buf, '\n'))
	{
		r = read(fd, new_buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(new_buf);
			free (buf);
			return (NULL);
		}
		new_buf[r] = '\0';
		buf = ft_strjoin_gnl(buf, new_buf);
	}
	free (new_buf);
	return (buf);
}

char	*ft_first(char	*buf)
{
	size_t	i;
	char	*b;

	i = 0;
	if (!ft_strlen_gnl(buf))
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	b = ft_substr_gnl(buf, 0, i);
	if (!b)
		return (NULL);
	return (b);
}

char	*ft_second(char *buf)
{
	size_t	i;
	char	*b;
	size_t	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	if (ft_strlen_gnl(buf) == i)
	{
		free (buf);
		return (NULL);
	}
	b = malloc(ft_strlen_gnl(buf) - i + 1);
	if (!b)
	{
		free (buf);
		return (NULL);
	}
	while (buf[i])
		b[j++] = buf[i++];
	free (buf);
	return (b[j] = '\0', b);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*bef;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_read(fd, buf);
	if (!buf)
		return (NULL);
	bef = ft_first(buf);
	buf = ft_second(buf);
	return (bef);
}
