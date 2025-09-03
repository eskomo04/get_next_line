/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:36:14 by eskomo            #+#    #+#             */
/*   Updated: 2025/09/03 02:36:07 by eskomo           ###   ########.fr       */
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

char	*ft_strchr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == "\n")
		{
			return (&s[i]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_extract_line(t_list *leftover)
{
	int			size;
	int			i;
	int			l;
	char		*real_line;


	size = ft_lstsize(*leftover);
	real_line = malloc(sizeof(char) * size + 2);
	if (!real_line)
		return (NULL);
	l = 0;
	while (leftover)
	{
		i = 0;
		while (leftover->content[i])
		{
			real_line[l] = leftover->content[i];
			if (leftover->content[i] == '\n')
				break ;
			l++;
			i++;
		}
		if (leftover->content[i] == '\n')
			break ;
		leftover = leftover->next;
	}
	real_line[l] = '\0';
	return (real_line);
}

//		Linkedlist
int	ft_lstsize(t_list *lst)
{
	int	i;
	int	len;

	if (!list)
		return (NULL);
	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i] != '\n')
		{
			i++;
			len++;
		}
		lst = lst->next;
	}
	return (len);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		retrun ();
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
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
	t_list *last_node;
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
        ft_lstclear(leftover, free);
        return;
    }
	while (last_node->content[i] != '\0' && last_node->content[++i])
	{
		new_node->content[l] = last_node->content[i];
		l++;
	}
	new_node->content[l] = '\0';
	new_node->next = NULL;
	ft_lstclear(leftover, free);
	*leftover = new_node;
}


void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
//			Linked list
