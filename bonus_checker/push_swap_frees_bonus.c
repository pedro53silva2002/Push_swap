/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_frees_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:22:32 by peferrei          #+#    #+#             */
/*   Updated: 2024/08/09 15:04:07 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap_bonus.h"
#include "../Libft/libft.h"

void	ft_free_args(char **str, int argc)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (str[i])
			i++;
		while (i >= 0)
		{
			free(str[i]);
			i--;
		}
		free(str);
	}
	else
		return ;
}

void	ft_free_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp)
	{
		temp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = temp;
	}
	free(stack_a);
	temp = *stack_b;
	while (temp)
	{
		temp = (*stack_b)->next;
		free(*stack_b);
		*stack_b = temp;
	}
	free(stack_b);
}
