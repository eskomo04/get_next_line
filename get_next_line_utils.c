/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:56:01 by eskomo            #+#    #+#             */
/*   Updated: 2025/09/18 02:19:11 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * ft_strdup - Duplicates a string by allocating memory for it.
 * @param s The string to duplicate.
 * Return: A pointer to the newly allocated string(\0),
 *			or NULL if allocation fails.
 */

char	*ft_strdup(const char *s)
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
/**
 * ft_strjoin - Joins two strings into a new string.
 * @param remainder save the previous read
 * @param buffer new read
 * Return: A pointer to the newly allocated string, or NULL if allocation fails.
 */

char	*ft_strjoin(char *remainder, char *buffer)
{
	char	*new_str;
	int		i;
	int		j;

	if (!remainder)
	{
		free(remainder);
		return (ft_strdup(buffer));
	}
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(remainder)
				+ ft_strlen(buffer) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (remainder[i])
	{
		new_str[i] = remainder[i];
		i++;
	}
	while (buffer[j])
		new_str[i++] = buffer[j++];
	new_str[i] = '\0';
	free(remainder);
	return (new_str);
}


// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*result;
// 	size_t	i;
// 	size_t	j;

// 	if (!s2)
// 		return (free(s1), NULL);
// 	i = 0;
// 	if (s1)
// 		i = ft_strlen(s1);
// 	j = ft_strlen(s2);
// 	result = malloc(sizeof(char) * (i + j + 1));
// 	if (!result)
// 		return (free(s1), free(s2), NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1 && s1[j])
// 		result[i++] = s1[j++];
// 	j = 0;
// 	while (s2[j] && s2[j] != '\n')
// 		result[i++] = s2[j++];
// 	if (s2[j] == '\n')
// 		result[i++] = '\n';
// 	if (s1)
// 		free(s1);
// 	return (free(s2), result);
// }

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
