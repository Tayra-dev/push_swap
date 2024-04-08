/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:07:40 by hle-roi           #+#    #+#             */
/*   Updated: 2024/03/14 14:28:19 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSLIB_H
# define PSLIB_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/includes/ft_printf.h"

# define TRUE 1
# define FALSE 0

void	turk_algorithm(t_list **stack_a, t_list **stack_b, int max_i);

void	cycle_a(t_list **stack, int index);
void	cycle_b(t_list **stack, int index);
void	reverse_cycle_a(t_list **stack, int index);
void	reverse_cycle_b(t_list **stack, int index);
void	cycle_all(t_list **stack_a, t_list **stack_b, int index);
void	reverse_cycle_all(t_list **stack_a, t_list **stack_b, int index);

void	sort_three(t_list **stack);

int		parse_string(char *str, t_list **stack);
void	print_stack(t_list *stack_a, t_list *stack_b);
int		lowest_num(int a, int b);
int		check_dupe(t_list **stack);

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

void	swap_a(t_list **stack, int bool);
void	swap_b(t_list **stack, int bool);
void	swap_all(t_list **stack_a, t_list **stack_b);

void	rotate_a(t_list **stack, int bool);
void	rotate_b(t_list **stack, int bool);
void	rotate_all(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack, int bool);
void	reverse_rotate_b(t_list **stack, int bool);
void	reverse_rotate_all(t_list **stack_a, t_list **stack_b);

int		lst_len(t_list **stack);
int		is_sort(t_list **stack);
int		get_index(t_list *elt, t_list **stack);
t_list	*lst_getmax(t_list **stack);
t_list	*lst_getmin(t_list **stack);

t_list	*get_target(t_list *node, t_list **stack_b);
t_list	*get_target_pb(t_list *node, t_list **stack_b);
t_list	*lowest_cost(t_list **stack_a, t_list **stack_b);

void	free_list(t_list **stack);

void	print_error(void);

#endif