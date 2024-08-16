/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_rrr_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:39:50 by peferrei          #+#    #+#             */
/*   Updated: 2024/08/09 16:46:38 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap_bonus.h"
#include "../Libft/libft.h"

void	ft_rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp_next;
	t_list	*tmp_last;
	t_list	*dummy_lst;

	if (ft_pushswap_strlen(*stack_a) <= 1)
		return ;
	tmp = ft_pushswap_lstnew((*stack_a)->value, (*stack_a)->index);
	dummy_lst = *stack_a;
	tmp_last = ft_lstlast(*stack_a);
	tmp_last = ft_pushswap_lstnew(tmp_last->value, tmp_last->index);
	tmp_next = dummy_lst;
	while (dummy_lst->next)
	{
		tmp->value = tmp_next->value;
		tmp->index = tmp_next->index;
		dummy_lst = dummy_lst->next;
		tmp_next->value = dummy_lst->value;
		tmp_next->index = dummy_lst->index;
		dummy_lst->value = tmp->value;
		dummy_lst->index = tmp->index;
	}
	(*stack_a)->value = tmp_last->value;
	(*stack_a)->index = tmp_last->index;
	return (free(tmp), free(tmp_last));
}

void	ft_rrb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp_next;
	t_list	*tmp_last;
	t_list	*dummy_lst;

	if (ft_pushswap_strlen(*stack_b) <= 1)
		return ;
	tmp = ft_pushswap_lstnew((*stack_b)->value, (*stack_b)->index);
	dummy_lst = *stack_b;
	tmp_last = ft_lstlast(*stack_b);
	tmp_last = ft_pushswap_lstnew(tmp_last->value, tmp_last->index);
	tmp_next = dummy_lst;
	while (dummy_lst->next)
	{
		tmp->value = tmp_next->value;
		tmp->index = tmp_next->index;
		dummy_lst = dummy_lst->next;
		tmp_next->value = dummy_lst->value;
		tmp_next->index = dummy_lst->index;
		dummy_lst->value = tmp->value;
		dummy_lst->index = tmp->index;
	}
	(*stack_b)->value = tmp_last->value;
	(*stack_b)->index = tmp_last->index;
	return (free(tmp), free(tmp_last));
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}
