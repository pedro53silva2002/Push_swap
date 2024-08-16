/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:38:54 by peferrei          #+#    #+#             */
/*   Updated: 2024/08/09 16:52:03 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap_bonus.h"
#include "../Libft/libft.h"

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

static int	ft_operations(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(str, "sa", 2) == 0 && ft_push_swap_strlen(str) == 2)
		ft_sa(stack_a);
	else if (ft_strncmp(str, "sb", 2) == 0 && ft_push_swap_strlen(str) == 2)
		ft_sb(stack_b);
	else if (ft_strncmp(str, "ss", 2) == 0 && ft_push_swap_strlen(str) == 2)
		ft_ss(stack_a, stack_b);
	else if (ft_strncmp(str, "pa", 2) == 0 && ft_push_swap_strlen(str) == 2)
		ft_pa(stack_a, stack_b);
	else if (ft_strncmp(str, "pb", 2) == 0 && ft_push_swap_strlen(str) == 2)
		ft_pb(stack_a, stack_b);
	else if (ft_strncmp(str, "ra", 2) == 0 && ft_push_swap_strlen(str) == 2)
		ft_ra(stack_a);
	else if (ft_strncmp(str, "rb", 2) == 0 && ft_push_swap_strlen(str) == 2)
		ft_rb(stack_b);
	else if (ft_strncmp(str, "rr", 2) == 0 && ft_push_swap_strlen(str) == 2)
		ft_rr(stack_a, stack_b);
	else if (ft_strncmp(str, "rra", 3) == 0 && ft_push_swap_strlen(str) == 3)
		ft_rra(stack_a);
	else if (ft_strncmp(str, "rrb", 3) == 0 && ft_push_swap_strlen(str) == 3)
		ft_rrb(stack_b);
	else if (ft_strncmp(str, "rrr", 3) == 0 && ft_push_swap_strlen(str) == 3)
		ft_rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

static int	ft_pushswap_checkfinalorder(t_list **stack)
{
	t_list	**dummy_lst;
	t_list	*tmp_next;

	dummy_lst = stack;
	while ((*dummy_lst)->next)
	{
		tmp_next = (*dummy_lst)->next;
		if ((*dummy_lst)->value > tmp_next->value)
			return (0);
		*dummy_lst = (*dummy_lst)->next;
	}
	return (1);
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	char	*str;
	int		is_valid;

	str = get_next_line(0);
	is_valid = 1;
	while (str != NULL)
	{
		is_valid = ft_operations(str, stack_a, stack_b);
		if (!is_valid)
		{
			ft_printf("Error\n");
			break ;
		}
		free(str);
		str = get_next_line(0);
	}
	free(str);
	if (!is_valid)
		return ;
	if (ft_pushswap_checkfinalorder(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
