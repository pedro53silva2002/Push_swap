/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peferrei <peferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:01:38 by peferrei          #+#    #+#             */
/*   Updated: 2024/08/09 16:36:05 by peferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef MAX_INT
#  define MAX_INT 2147483647
# endif

# ifndef MIN_INT
#  define MIN_INT -2147483648
# endif

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../Libft/libft.h"

int			main(int argc, char **argv);
void		ft_push_swap(t_list **stack_a, t_list **stack_b);
int			push_swap_checker(char **argv, int argc);
long		ft_atol(const char *str);
int			ft_pushswap_strcmp(const char *s1, const char *s2);
int			ft_pushswap_checkarguments(char **argv);
int			ft_pushswap_checkerrors(char **argv);
int			ft_pushswap_checknumbers(char **argv);
int			ft_pushswap_checkorder(char **argv);
int			ft_pushswap_strlen(t_list *lst);
void		ft_sa(t_list **lst);
void		ft_sb(t_list **lst);
void		ft_ss(t_list **stack_a, t_list **stack_b);
void		ft_pa(t_list **stack_a, t_list **stack_b);
void		ft_pb(t_list **stack_a, t_list **stack_b);
void		ft_ra(t_list **stack_a);
void		ft_rb(t_list **stack_b);
void		ft_rr(t_list **stack_a, t_list **stack_b);
void		ft_rra(t_list **stack_a);
void		ft_rrb(t_list **stack_b);
void		ft_rrr(t_list **stack_a, t_list **stack_b);
t_list		*ft_pushswap_lstnew(int value, int index);
void		ft_free_args(char **str, int argc);
void		ft_free_stacks(t_list **a, t_list **b);
void		ft_index_stack(t_list **stack);
int			ft_push_swap_strlen(char *str);

#endif