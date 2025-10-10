/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:04:52 by eskomo            #+#    #+#             */
/*   Updated: 2025/10/10 21:36:40 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		*remainder;
	char		*line;
	static char	leftover [MAX_FD][BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((leftover[fd][0] = '\0'), (NULL));
	if (fd >= MAX_FD)
		return (NULL);
	remainder = NULL;
	if (leftover[fd][0] != '\0')
	{
		remainder = ft_strdup(leftover[fd]);
		if (!remainder)
			return (NULL);
	}
	remainder = ft_readline(fd, remainder);
	if (!remainder)
	{
		leftover[fd][0] = '\0';
		return (NULL);
	}
	line = ft_extract_line(&remainder);
	ft_leftover(fd, leftover, &remainder);
	return (line);
}
/**
 * ft_readline - Reads from a file descriptor until a newline is found
 * 			 or end of file is reached.
 * @param fd The file descriptor of the file to read from.
 * @param remainder The string containing the remaining characters
 * 				 of the current line (+ the next line)
 * Return: The updated remainder string, or NULL if allocation fails.
 */

char	*ft_readline(int fd, char *remainder)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(remainder), NULL);
	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(remainder);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if (!remainder)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (remainder);
}
/**
 * ft_extract_line - Extracts a line from the remainder string.
 * @param remainder The string containing the remaining characters
 * 					of the current line (+ the next line)
 * Return: The extracted line, or NULL if allocation fails.
 */

char	*ft_extract_line(char **remainder)
{
	char	*line;
	size_t	i;

	if (!remainder || !*remainder || (*remainder)[0] == '\0')
		return (NULL);
	i = 0;
	while ((*remainder)[i] && (*remainder)[i] != '\n')
		i++;
	if ((*remainder)[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
	{
		free(*remainder);
		*remainder = NULL;
		return (NULL);
	}
	ft_strlcpy(line, *remainder, i + 1);
	return (line);
}
/**
 * ft_leftover - Updates the leftover buffer with
 * 				 any remaining characters for the "next_line"
 * @param leftover The Array to store leftover characters
 * @param remainder The string containing the remaining characters
 * 					 of the current line (+ the next line)
 * Return: void
 */

void	ft_leftover(int fd, char leftover[MAX_FD][BUFFER_SIZE + 1],
					char **remainder)
{
	size_t	i;

	if (!remainder || !*remainder)
	{
		leftover[fd][0] = '\0';
		return ;
	}
	i = 0;
	while ((*remainder)[i] && (*remainder)[i] != '\n')
		i++;
	if ((*remainder)[i] == '\n')
		i++;
	if ((*remainder)[i] == '\0')
		leftover[fd][0] = '\0';
	else
		ft_strlcpy(leftover[fd], &(*remainder)[i],
			ft_strlen(&(*remainder)[i]) + 1);
	free(*remainder);
	*remainder = NULL;
}

// int	main(void)
// {
// 	int	fd;
// 	char *line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
