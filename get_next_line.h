/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:36:59 by eskomo            #+#    #+#             */
/*   Updated: 2025/09/06 17:12:51 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

int		ft_lstsize(t_list *leftover);
void	ft_append(t_list **leftover, char *buffer);
void	ft_clean_leftover(t_list **leftover);
void	ft_lstclear(t_list **leftover, t_list *new_node);
char	*ft_extract_line(t_list *leftover);
char	*ft_strchr(t_list *s);
char	*get_next_line(int fd);
t_list	*ft_lstlast(t_list *lst);

#endif
