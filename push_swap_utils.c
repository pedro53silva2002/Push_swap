/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:06:10 by peferrei          #+#    #+#             */
/*   Updated: 2024/08/08 14:40:28 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include "./Libft/libft.h"

static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	ft_index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

t_list	*ft_pushswap_lstnew(int value, int index)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list *) * 2);
	if (!elem)
		return (NULL);
	elem->value = value;
	if (index == -1)
		elem->index = -1;
	else
		elem->index = index;
	elem->next = NULL;
	return (elem);
}

int	ft_pushswap_strlen(t_list *lst)
{
	int		i;
	t_list	*dummy_lst;

	i = 0;
	dummy_lst = lst;
	while (dummy_lst)
	{
		i++;
		dummy_lst = dummy_lst->next;
	}
	return (i);
}
