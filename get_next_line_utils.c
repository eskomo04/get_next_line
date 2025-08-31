/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:36:14 by eskomo            #+#    #+#             */
/*   Updated: 2025/08/31 20:51:56 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == "\n")
		{
			return (&s[i]);
		}
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*copy;

	len = 0;
	i = 0;
	len = ft_strlen(s1);
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	while (i <= len)
	{
		copy[i] = s1[i];
		i++;
	}
	return (copy);
}

char	*ft_extract_line(char *leftover)
{
	int		i;
	char	*real_line;

	i = ft_strlen(leftover);
	real_line = malloc((sizeof(char *)) * (i + 1));
	if (!real_line || !leftover)
		return (NULL);
	if (!leftover)
		free(real_line);
	i = 0;
	while (!leftover && leftover[i] != "\n")
	{
		real_line[i] = leftover[i];
		i++;
	}
	real_line[i] = '\0';
	return (real_line);
}

char	*ft_append(char *leftover, char *buffer)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	newstr = malloc((sizeof(char *)) * (ft_strlen(leftover)
				+ ft_strlen(buffer) + 1));
	if (!newstr)
		return (NULL);
	i = -1;
	if (leftover)
	{
		while (leftover[++i] != '\0')
			newstr[i] = leftover[i];
	}
	j = 0;
	while (buffer[j] != '\0')
	{
		newstr[j + i] = buffer[j];
		j++;
	}
	newstr[ft_strlen(leftover) + ft_strlen(buffer) - 1] = '\0';
	free(leftover);
	return (newstr);
}
