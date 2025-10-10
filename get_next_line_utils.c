/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:56:01 by eskomo            #+#    #+#             */
/*   Updated: 2025/09/20 19:08:26 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * ft_strdup - Duplicates a string by allocating memory for it.
 * @param s The string to duplicate.
 * Return: A pointer to the newly allocated string(\0),
 *			or NULL if allocation fails; after free-ing s.
 */

char	*ft_strdup(char *s)
{
	size_t	i;
	char	*dup;

	if (!s)
		return (NULL);
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
	while (s[i] != '\0')
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
/**
 * ft_strjoin - Joins two strings into a new string.
 * @param remainder save the previous read
 * @param buffer new read
 * Return: A pointer to the newly allocated string, or NULL if allocation fails.
 */

char	*ft_strjoin(char *remainder, char *buffer)
{
	char	*new_str;
	int		len_remainder;
	int		len_buffer;

	if (!remainder)
	{
		remainder = ft_strdup("");
		if (!remainder)
			return (NULL);
	}
	len_remainder = ft_strlen(remainder);
	len_buffer = ft_strlen(buffer);
	new_str = (char *)malloc(sizeof(char) * (len_remainder + len_buffer + 1));
	if (!new_str)
	{
		free(remainder);
		return (NULL);
	}
	ft_strlcpy(new_str, remainder, len_remainder + 1);
	ft_strlcpy(new_str + len_remainder, buffer, len_buffer + 1);
	free(remainder);
	return (new_str);
}

/**
 * ft_strlcpy - Copies a string to a destination buffer with size limit.
 * @param dst The destination buffer.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * Return: The total length of the string it tried to create (length of src).
 */

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	if (!src)
		return (0);
	i = 0;
	while (src[i] != '\0')
		i++;
	src_len = i;
	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
