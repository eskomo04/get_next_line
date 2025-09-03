/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:36:14 by eskomo            #+#    #+#             */
/*   Updated: 2025/09/03 03:07:22 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

int	ft_lstsize(t_list *leftover)
{
	int	i;
	int	len;

	if (!leftover)
		return (NULL);
	len = 0;
	while (leftover)
	{
		i = 0;
		while (leftover->content[i] != '\n')
		{
			i++;
			len++;
		}
		leftover = leftover->next;
	}
	return (len);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_append(t_list **leftover, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*leftover);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		retrun (NULL);
	if (!last_node)
		*leftover = new_node;
	else
		last_node->next = new_node;
	new_node->content = buffer;
	new_node->next = NULL;
}

void	ft_clean_leftover(t_list **leftover)
{
	t_list	*last_node;
	t_list	*new_node;
	int		i;
	int		l;

	last_node = ft_lstlast(*leftover);
	new_node = malloc(sizeof(t_list));
	i = 0;
	l = 0;
	while (last_node->content[i] != '\0' && last_node->content[i] != '\n')
		i++;
	new_node->content = malloc(sizeof(char) * (ft_strlen(last_node->content) - i + 1));
	if (!last_node->content[i])
	{
		ft_lstclear(leftover);
		return ;
	}
	while (last_node->content[i] != '\0' && last_node->content[++i])
		new_node->content[l++] = last_node->content[i];
	new_node->content[l] = '\0';
	new_node->next = NULL;
	ft_lstclear(leftover);
	*leftover = new_node;
}

void	ft_lstclear(t_list **leftover)
{
	t_list	*temp;

	if (leftover == NULL)
		return ;
	while (*leftover != NULL)
	{
		temp = (*leftover)->next;
		free((*leftover)->content);
		free(*leftover);
		*leftover = temp;
	}
	*leftover = NULL;
}
