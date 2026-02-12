/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamimsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:32:53 by ahamimsa          #+#    #+#             */
/*   Updated: 2024/05/04 15:34:07 by ahamimsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_buffreadline(int fd, char *line)
{
	char	*buffer;
	ssize_t	readfilebytes;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
	{
		return (NULL);
	}
	readfilebytes = 1;
	while (!ft_strchr(line, '\n') && readfilebytes > 0)
	{
		readfilebytes = read(fd, buffer, BUFFER_SIZE);
		if (readfilebytes == -1)
		{
			free(buffer);
			if (line)
				free(line);
			return (NULL);
		}
		buffer[readfilebytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*geti_line(char *line_b_chyata)
{
	int		i;
	char	*line;

	i = 0;
	if (!line_b_chyata[i])
		return (NULL);
	while (line_b_chyata[i] && line_b_chyata[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		free(line);
	i = 0;
	while (line_b_chyata[i] && line_b_chyata[i] != '\n')
	{
		line[i] = line_b_chyata[i];
		i++;
	}
	if (line_b_chyata[i] == '\n')
	{
		line[i] = '\0';
	}
	return (line);
}

char	*ft_chyata(char *line_b_chyata)
{
	int		i;
	int		j;
	char	*chyata;

	i = 0;
	while (line_b_chyata[i] && line_b_chyata[i] != '\n')
		i++;
	if (!line_b_chyata[i])
	{
		free(line_b_chyata);
		return (NULL);
	}
	chyata = malloc(ft_strlen(line_b_chyata) - i + 1);
	if (!chyata)
	{
		free(chyata);
		return (NULL);
	}
	i++;
	j = 0;
	while (line_b_chyata[i])
		chyata[j++] = line_b_chyata[i++];
	chyata[j] = '\0';
	free(line_b_chyata);
	return (chyata);
}

char	*get_next_line(int fd)
{
	static char	*line_b_chyata;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_b_chyata = get_buffreadline(fd, line_b_chyata);
	if (!line_b_chyata)
	{
		return (NULL);
	}
	line = geti_line(line_b_chyata);
	line_b_chyata = ft_chyata(line_b_chyata);
	return (line);
}
