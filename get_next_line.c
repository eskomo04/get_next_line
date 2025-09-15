/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:22:58 by eskomo            #+#    #+#             */
/*   Updated: 2025/09/15 06:24:47 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	remainder = ft_readline(fd, remainder);
	if (!remainder)
	{
		return (NULL);
	}
	line = ft_extract_line(&remainder);
	remainder = ft_leftover(remainder);
	return (line);
}

char	*ft_readline(int fd, char *remainder)
{
	char		*buffer;
	int			bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
	}
	free(buffer);
	return (remainder);
}

char	*ft_extract_line(char **remainder)
{
	char	*line;
	size_t	i;
	char	*temp;

	i = 0;
	while ((*remainder)[i] && (*remainder)[i] != '\n')
		i++;
	if ((*remainder)[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	temp = line;
	while ((*remainder)[i] && (*remainder)[i] != '\n')
		*temp++ = (*remainder)[i++];
	if ((*remainder)[i] == '\n')
		*temp++ = (*remainder)[i++];
	*temp = '\0';
	return (line);
}

char	*ft_leftover(char *remainder)
{
	char	*new_remainder;
	size_t	i;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	new_remainder = ft_strdup(&remainder[i]);
	free(remainder);
	return (new_remainder);
}

