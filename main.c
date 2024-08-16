/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:38:54 by peferrei          #+#    #+#             */
/*   Updated: 2024/08/12 14:34:23 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include "./Libft/libft.h"

static void	ft_initstack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_pushswap_lstnew(ft_atoi(args[i]), -1);
		ft_lstadd_back(stack, new);
		i++;
	}
	ft_index_stack(stack);
	ft_free_args(args, argc);
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		ft_sa(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		ft_sort_3(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 4)
		ft_sort_4(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		ft_sort_5(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) > 5)
		ft_bit_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc == 1)
		return (0);
	if (push_swap_checker(argv, argc) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	else if (push_swap_checker(argv, argc) == 2)
		return (0);
	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_initstack(stack_a, argc, argv);
	ft_push_swap(stack_a, stack_b);
	ft_free_stacks(stack_a, stack_b);
	return (0);
}
