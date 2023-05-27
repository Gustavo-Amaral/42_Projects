/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:22:56 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/27 21:42:06 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *buffer)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if(!temp)
		return(NULL);
	while (!ft_strchr(temp, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

static char	*get_line(char *buffer)
{
	size_t	i;
	char	*line;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*only_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	temp = ft_calloc(ft_strlen(buffer) - i, sizeof(char));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i] != '\0')
		temp[j++] = buffer[i++];
	temp[j] = '\0';
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*st_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	st_buffer = read_file(fd, st_buffer);
	if (!st_buffer)
		return (NULL);
	line = get_line(st_buffer);
	st_buffer = only_next_line(st_buffer);
	return (line);
}
