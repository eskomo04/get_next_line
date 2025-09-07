/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:36:14 by eskomo            #+#    #+#             */
/*   Updated: 2025/09/07 07:20:24 by eskomo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lst_count_char(t_list *lst)
{
	int	i;
	int	len;

	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			//printf("count char: %c.. lenCurrently: %d\n",lst->content[i], len);		//delete
			len++;
			if (lst->content[i] == '\n')
				return (len);
			i++;
		}
		lst = lst->next;
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

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dst && !src)
		return (NULL);
	i = 0;
	d = (char *)dst;
	s = (char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

void	ft_append(t_list **leftover, char *buffer, int bytes_read)
{
	t_list	*new_node;
	t_list	*last_node;

	if (!buffer)
		return ;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = malloc(sizeof(char) * (bytes_read + 1));
	if (!new_node->content)
	{
		free(new_node);
		return ;
	}
	ft_memcpy(new_node->content, buffer, bytes_read);
	printf("the new_node>: %s\n", new_node->content);
	new_node->content[bytes_read] = '\0';
	new_node->next = NULL;
	last_node = ft_lstlast(*leftover);
	if (!last_node)
		*leftover = new_node;
	else
		last_node->next = new_node;
}

void	ft_clean_leftover(t_list **leftover)
{
	t_list	*last_node;
	t_list	*new_node;
	int		i;
	int		l;

	i = 0;
	if (!leftover)
		return ;
	last_node = ft_lstlast(*leftover);
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	if (!last_node->content[i])
	{
		ft_lstclear(leftover);
		return ;
	}
	i++;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = malloc(sizeof(char) * (BUFFER_SIZE - i));
	l = 0;
	while (last_node->content[i])
		new_node->content[l++] = last_node->content[i++];
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
}
