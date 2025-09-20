/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 00:48:05 by eskomo            #+#    #+#             */
/*   Updated: 2025/09/20 18:42:59 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_extract_line(char **remainder);
char	*ft_strjoin(char *remainder, char *buffer);
char	*ft_strdup(char *s);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_readline(int fd, char *remainder);
void	ft_leftover(char *leftover, char **remainder);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif