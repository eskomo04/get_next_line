/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:36:59 by eskomo            #+#    #+#             */
/*   Updated: 2025/09/07 05:37:02 by eskomo           ###   ########.fr       */
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

typedef struct s_list
{
	char				*content;
	struct s_list		*next;
}	t_list;

int		ft_lst_count_char(t_list *leftover);
void	ft_append(t_list **leftover, char *buffer, int bytes_read);
void	ft_clean_leftover(t_list **leftover);
void	ft_lstclear(t_list **leftover);
char	*ft_extract_line(t_list *leftover);
int		ft_strchr(t_list *leftover);
char	*get_next_line(int fd);
t_list	*ft_lstlast(t_list *lst);
void	ft_copy(t_list *leftover, char *real_line);
void	ft_read_append(t_list **leftover, int fd);
void	*ft_memcpy(void *dst, void *src, size_t n);


#endif
