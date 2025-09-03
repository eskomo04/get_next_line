/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:36:59 by eskomo            #+#    #+#             */
/*   Updated: 2025/09/03 02:57:41 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s);
char	*ft_extract_line(t_list *leftover);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_append(t_list **leftover, char *buffer);
void	ft_clean_leftover(t_list **leftover);
void	ft_lstclear(t_list **lst, void (*del)(void *));

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#endif
