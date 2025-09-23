/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:05:06 by eskomo            #+#    #+#             */
/*   Updated: 2025/09/22 23:36:42 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
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
void	ft_leftover(int fd, char leftover[MAX_FD][BUFFER_SIZE + 1],
			char **remainder);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif