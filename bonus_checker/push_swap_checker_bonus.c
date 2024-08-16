/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:04:43 by peferrei          #+#    #+#             */
/*   Updated: 2024/08/09 15:04:22 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap_bonus.h"
#include "../Libft/libft.h"

int	ft_pushswap_checkarguments(char **argv)
{
	int		i;
	int		j;

	i = -1;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else if ((argv[i][j] == '-' || argv[i][j] == '+') && j == 0)
				j++;
			else
				return (0);
		}
	}
	return (1);
}

int	ft_pushswap_checknumbers(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		while (argv[j])
		{
			if ((ft_atoi(argv[i]) == ft_atoi(argv[j])) && i != j)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_pushswap_int_limits(char **argv)
{
	int		i;
	long	nbr;

	i = -1;
	while (argv[++i])
	{
		nbr = ft_atol(argv[i]);
		if (nbr > MAX_INT || nbr < MIN_INT)
			return (0);
	}
	return (1);
}

int	ft_pushswap_checkorder(char **argv)
{
	int	i;

	i = 0;
	while (argv[i + 1])
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	push_swap_checker(char **argv, int argc)
{
	int		i;
	char	**str;

	i = 0;
	str = argv;
	str++;
	if (argc == 2 && !ft_strchr(str[0], ' ')
		&& !ft_pushswap_checkarguments(str))
		return (0);
	if (argc == 2)
		str = ft_split(str[0], ' ');
	if (!ft_pushswap_checkarguments(str) || !ft_pushswap_checknumbers(str)
		|| !ft_pushswap_int_limits(str))
	{
		ft_free_args(str, argc);
		return (0);
	}
	if (ft_pushswap_checkorder(str))
	{
		ft_free_args(str, argc);
		return (2);
	}
	ft_free_args(str, argc);
	return (1);
}
