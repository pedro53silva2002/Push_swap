/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_rr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:34:36 by peferrei          #+#    #+#             */
/*   Updated: 2024/08/06 16:29:38 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include "./Libft/libft.h"

void	ft_ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp_last;
	t_list	*tmp_first;
	t_list	*dummy_lst;

	if (ft_pushswap_strlen(*stack_a) <= 1)
	{
		return ;
	}
	dummy_lst = *stack_a;
	tmp_first = ft_pushswap_lstnew((*stack_a)->value, (*stack_a)->index);
	tmp_last = ft_lstlast(*stack_a);
	while (dummy_lst->next)
	{
		tmp = dummy_lst;
		dummy_lst = dummy_lst->next;
		tmp->value = dummy_lst->value;
		tmp->index = dummy_lst->index;
	}
	tmp_last->value = tmp_first->value;
	tmp_last->index = tmp_first->index;
	free(tmp_first);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp_last;
	t_list	*tmp_first;
	t_list	*dummy_lst;

	if (ft_pushswap_strlen(*stack_b) <= 1)
	{
		return ;
	}
	dummy_lst = *stack_b;
	tmp_first = ft_pushswap_lstnew((*stack_b)->value, (*stack_b)->index);
	tmp_last = ft_lstlast(*stack_b);
	while (dummy_lst->next)
	{
		tmp = dummy_lst;
		dummy_lst = dummy_lst->next;
		tmp->value = dummy_lst->value;
		tmp->index = dummy_lst->index;
	}
	tmp_last->value = tmp_first->value;
	tmp_last->index = tmp_first->index;
	free(tmp_first);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
	ft_putstr_fd("rr\n", 1);
}
