/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:56:01 by eskomo            #+#    #+#             */
/*   Updated: 2025/09/15 06:14:52 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = 0;
	while (s[i])
		i++;
	dup = (char *)malloc(i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *remainder, char *buffer)
{
	char	*new_str;
	char	*temp;

	if (!remainder)
		remainder = ft_strdup("");
	if (!remainder || !buffer)
		return (NULL);
	new_str = (char *)malloc(sizeof(char)
			* ((ft_strlen(remainder) + ft_strlen(buffer)) + 1));
	if (!new_str)
		return (NULL);
	temp = new_str;
	while (*remainder)
		*temp++ = *remainder++;
	while (*buffer)
		*temp++ = *buffer++;
	*temp = '\0';
	return (new_str);
}
