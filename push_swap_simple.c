/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:11:27 by peferrei          #+#    #+#             */
/*   Updated: 2024/08/12 17:17:13 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include "./Libft/libft.h"

static int	ft_pushswap_checkstackorder(t_list **stack)
{
	t_list	*dummy_lst;
	t_list	*next_value;

	dummy_lst = *stack;
	while (dummy_lst->next)
	{
		next_value = dummy_lst->next;
		if (dummy_lst->value > next_value->value)
			return (0);
		dummy_lst = dummy_lst->next;
	}
	return (1);
}

static int	ft_get_min(t_list **stack)
{
	int		min;
	t_list	*dummy_lst;

	dummy_lst = *stack;
	min = dummy_lst->value;
	while (dummy_lst)
	{
		if (dummy_lst->value < min)
			min = dummy_lst->value;
		dummy_lst = dummy_lst->next;
	}
	return (min);
}

void	ft_sort_3(t_list **stack_a, t_list **stack_b)
{
	int		top;
	t_list	*mid;

	mid = (*stack_a)->next;
	top = (mid->next)->value;
	if (ft_pushswap_checkstackorder(stack_a))
		mid = (*stack_a)->next;
	else if (top < mid->value && mid->value < (*stack_a)->value)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (top < (*stack_a)->value && (*stack_a)->value > mid->value)
		ft_ra(stack_a);
	else if (mid->value > top && top < (*stack_a)->value)
		ft_rra(stack_a);
	else if (mid->value > (*stack_a)->value && (*stack_a)->value < top)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if ((*stack_a)->value < top && top > mid->value)
		ft_sa(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

void	ft_sort_4(t_list **stack_a, t_list **stack_b)
{
	int		min_nbr;
	int		i;
	t_list	*dummy_lst;

	min_nbr = ft_get_min(stack_a);
	i = 0;
	dummy_lst = *stack_a;
	while (dummy_lst->value != min_nbr)
	{
		i++;
		dummy_lst = dummy_lst->next;
	}
	if (i <= 2)
	{
		while ((*stack_a)->value != min_nbr)
			ft_ra(stack_a);
	}
	else
	{
		while ((*stack_a)->value != min_nbr)
			ft_rra(stack_a);
	}
	ft_pb(stack_a, stack_b);
	ft_sort_3(stack_a, stack_b);
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	int		min_nbr;
	int		i;
	t_list	*dummy_lst;

	min_nbr = ft_get_min(stack_a);
	i = 0;
	dummy_lst = *stack_a;
	while (dummy_lst->value != min_nbr)
	{
		i++;
		dummy_lst = dummy_lst->next;
	}
	if (i <= 3)
	{
		while ((*stack_a)->value != min_nbr)
			ft_ra(stack_a);
	}
	else
	{
		while ((*stack_a)->value != min_nbr)
			ft_rra(stack_a);
	}
	ft_pb(stack_a, stack_b);
	ft_sort_4(stack_a, stack_b);
}

	/* if ((*stack_a)->value > dummy_lst->value
		&& dummy_lst->value != min_nbr)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else
	{
		if (dummy_lst->value == min_nbr)
			ft_ra(stack_a);
		else if (!((*stack_a)->value == min_nbr))
			ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
		if (!ft_pushswap_checkstackorder(stack_a))
			ft_sa(stack_a);
	} */