/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:55:48 by hle-roi           #+#    #+#             */
/*   Updated: 2024/03/06 13:27:12 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

void	final_cycle(t_list **stack_a)
{
	t_list	*min_elt;
	int		index;

	min_elt = lst_getmin(stack_a);
	index = get_index(min_elt, stack_a);
	while (*stack_a != min_elt)
	{
		if (index > lst_len(stack_a) / 2)
			reverse_rotate_a(stack_a, TRUE);
		else
			rotate_a(stack_a, TRUE);
	}
}

void	resort(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_b;
	t_list	*target;
	int		index;

	current_b = *stack_b;
	while (current_b)
	{
		target = get_target(current_b, stack_a);
		index = get_index(target, stack_a);
		if (index > lst_len(stack_a) / 2)
			reverse_cycle_a(stack_a, lst_len(stack_a) - index);
		else
			cycle_a(stack_a, index);
		current_b = current_b->next;
		pa(stack_a, stack_b);
	}
	final_cycle(stack_a);
}

void	manage_cycle(int current_i, int target_i, t_list **s_a, t_list **s_b)
{
	if (current_i > lst_len(s_a) / 2 && target_i > lst_len(s_b) / 2)
		reverse_cycle_all(s_a, s_b,
			lowest_num(lst_len(s_a) - current_i, lst_len(s_b) - target_i));
	if (current_i <= lst_len(s_a) / 2 && target_i <= lst_len(s_b) / 2)
		cycle_all(s_a, s_b, lowest_num(current_i, target_i));
}

void	end_cycle(int current_i, int target_i, t_list **s_a, t_list **s_b)
{
	if (current_i > lst_len(s_a) / 2)
		reverse_cycle_a(s_a, lst_len(s_a) - current_i);
	else
		cycle_a(s_a, current_i);
	if (target_i > lst_len(s_b) / 2)
		reverse_cycle_b(s_b, lst_len(s_b) - target_i);
	else
		cycle_b(s_b, target_i);
}

void	turk_algorithm(t_list **stack_a, t_list **stack_b, int max_i)
{
	t_list	*current;
	t_list	*target;
	int		current_index;
	int		target_index;

	if (max_i-- > 3 && !is_sort(stack_a))
		pb(stack_a, stack_b);
	if (max_i-- > 3 && !is_sort(stack_a))
		pb(stack_a, stack_b);
	if (is_sort(stack_b))
		swap_b(stack_b, TRUE);
	while (max_i-- > 3 && !is_sort(stack_a))
	{
		current = lowest_cost(stack_a, stack_b);
		target = get_target_pb(current, stack_b);
		current_index = get_index(current, stack_a);
		target_index = get_index(target, stack_b);
		manage_cycle(current_index, target_index, stack_a, stack_b);
		current_index = get_index(current, stack_a);
		target_index = get_index(target, stack_b);
		end_cycle(current_index, target_index, stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	resort(stack_a, stack_b);
}
