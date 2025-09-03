/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:36:00 by eskomo            #+#    #+#             */
/*   Updated: 2025/09/03 02:32:53 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int				bytes_read;
	static t_list	leftover;
	char			*buffer;
	char			*real_line;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(*leftover) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		ft_append(**leftover, buffer);
	}
	real_line = ft_extract_line(*leftover);
	return (real_line);
}
