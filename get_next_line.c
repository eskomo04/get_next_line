/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:36:00 by eskomo            #+#    #+#             */
/*   Updated: 2025/09/07 07:20:15 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*ft_extract_line(t_list *leftover)
{
	int			len;
	char		*real_line;

	if (leftover == NULL)
		return (NULL);
	len = ft_lst_count_char(leftover);
	printf("len = %d\n", len);			//Delete
	real_line = malloc(sizeof(char) * (len + 1));
	if (!real_line)
		return (NULL);
	ft_copy(leftover, real_line);
	return (real_line);
}

void	ft_copy(t_list *leftover, char *real_line)
{
	int			i;
	int			l;

	if (leftover == NULL)
		return ;
	l = 0;
	while (leftover)
	{
		i = 0;
		while (leftover->content[i])
		{
			if (leftover->content[i] == '\n')
			{
				real_line[l++] = '\n';
				real_line[l] = '\0';
				return ;
			}
			real_line[l++] = leftover->content[i++];
		}
		leftover = leftover->next;
	}
	real_line[l] = '\0';
}

int	ft_strchr(t_list *list)
{
	int		i;
	t_list	*current;

	if (!list)
		return (0);
	current = list;
	while (current)
	{
		i = 0;
		while (current->content[i])
		{
			if (current->content[i] == '\n')
			{
				return (1);
			}
			i++;
		}
		current = current->next;
	}
	return (0);
}

void	ft_read_append(t_list **leftover, int fd)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	while (!ft_strchr(*leftover) && bytes_read != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		printf("AFTER read.. Bytes: %d; buffer: %s \n", bytes_read, buffer); //delete
		ft_append(leftover, buffer, bytes_read);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*leftover;
	char			*real_line;

	if (fd < 3 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_append(&leftover, fd);
	real_line = ft_extract_line(leftover);
	ft_clean_leftover(&leftover);
	return (real_line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Couldn't locate file\n");
		exit(-1);
	}
	printf("fd = %d\n", fd);

	line = get_next_line(fd);
	// printf("%s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	// while(1)
	// {
	// 	line = get_next_line(fd);
	// 	if(!line)
	// 		break;
	// 	printf("%s", line);
	// 	free(line);
	// }
	close(fd);
}
