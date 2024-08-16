/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_sp.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:29:48 by peferrei          #+#    #+#             */
/*   Updated: 2024/08/09 16:47:16 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include "./Libft/libft.h"

void	ft_sa(t_list **lst)
{
	int		nbr;
	t_list	*dummy_lst;

	if (ft_pushswap_strlen(*lst) <= 1)
	{
		return ;
	}
	dummy_lst = *lst;
	nbr = dummy_lst->value;
	dummy_lst = dummy_lst->next;
	(*lst)->value = dummy_lst->value;
	lst = &(*lst)->next;
	(*lst)->value = nbr;
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_list **lst)
{
	int		nbr;
	t_list	*dummy_lst;

	if (ft_pushswap_strlen(*lst) <= 1)
	{
		return ;
	}
	dummy_lst = *lst;
	nbr = dummy_lst->value;
	dummy_lst = dummy_lst->next;
	(*lst)->value = dummy_lst->value;
	lst = &(*lst)->next;
	(*lst)->value = nbr;
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
	ft_putstr_fd("ss\n", 1);
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (ft_pushswap_strlen(*stack_b) <= 0)
	{
		return ;
	}
	tmp = ft_pushswap_lstnew((*stack_b)->value, (*stack_b)->index);
	ft_lstadd_front(stack_a, tmp);
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	free(tmp);
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (ft_pushswap_strlen(*stack_a) <= 0)
	{
		return ;
	}
	tmp = ft_pushswap_lstnew((*stack_a)->value, (*stack_a)->index);
	ft_lstadd_front(stack_b, tmp);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	free(tmp);
	ft_putstr_fd("pb\n", 1);
}
