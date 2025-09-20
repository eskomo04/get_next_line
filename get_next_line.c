/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:22:58 by eskomo            #+#    #+#             */
/*   Updated: 2025/09/20 17:23:35 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		*remainder;
	char		*line;
	static char	leftover[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	remainder = NULL;
	if (leftover[0] != '\0')
	{
		remainder = ft_strdup(leftover);
		if (!remainder)
		{
			return (NULL);
		}
	}
	remainder = ft_readline(fd, remainder);
	if (!remainder)
	{
		leftover[0] = '\0';
		return (NULL);
	}
	line = ft_extract_line(&remainder);
	ft_leftover(leftover, remainder);
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
	char	*temp;

	if (!remainder || (*remainder)[0] == '\0')
		return (free(remainder), NULL);
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
/**
 * ft_leftover - Updates the leftover buffer with
 * 				 any remaining characters for the "next_line"
 * @param leftover The Array to store leftover characters
 * @param remainder The string containing the remaining characters
 * 					 of the current line (+ the next line)
 * Return: void
 */

void	ft_leftover(char *leftover, char *remainder)
{
	size_t	i;

	if (!leftover)
		return ;
	if (!remainder)
	{
		leftover[0] = '\0';
		return ;
	}
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	if (remainder[i] == '\0')
		leftover[0] = '\0';
	else
		ft_strlcpy(leftover, &remainder[i], BUFFER_SIZE + 1);
	free(remainder);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("read_error.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
