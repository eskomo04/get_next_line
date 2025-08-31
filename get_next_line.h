/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:36:59 by eskomo            #+#    #+#             */
/*   Updated: 2025/08/31 20:24:38 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strchr(char *s);
char	*ft_extract_line(char *leftover);
size_t	ft_strlen(char *s);
char	*ft_append(char *s1, char *s2, size_t lens1);

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#endif


