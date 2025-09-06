/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:36:00 by eskomo            #+#    #+#             */
/*   Updated: 2025/09/06 17:23:58 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(t_list *leftover)
{
	int			size;
	int			i;
	int			l;
	char		*real_line;

	size = ft_lstsize(leftover);
	real_line = malloc(sizeof(char) * (size + 1));
	if (!real_line)
		return (NULL);
	l = 0;
	while (leftover)
	{
		i = 0;
		while (((char *)leftover->content)[i++])
		{
			real_line[l++] = ((char *)leftover->content)[i];
			if (((char *)leftover->content)[i] == '\n')
				break ;
		}
		if (((char *)leftover->content)[i] == '\n')
			break ;
		leftover = leftover->next;
	}
	real_line[l] = '\0';
	return (real_line);
}

int	ft_strchr(t_list *leftover)
{
	int		i;
	t_list	*temp;
	char	*str;

	if (!leftover)
		return (NULL);
	str = (char *)leftover->content;
	i = 0;
	while (leftover)
	{
		temp = leftover->next;
		str = (char *)leftover->content;
		while (str[i])
		{
			if (str[i] == '\n')
			{
				return (1);
			}
			i++;
		}
		leftover = temp;
	}
	return (NULL);
}

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
	while (!ft_strchr(leftover.content) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		ft_append(&leftover, buffer);
	}
	real_line = ft_extract_line(&leftover);
	ft_clean_leftover(&leftover);
	return (real_line);
}
