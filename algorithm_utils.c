/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:08:50 by hle-roi           #+#    #+#             */
/*   Updated: 2024/03/12 11:32:50 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

int	highest_num(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_list	*get_target(t_list *node, t_list **stack_a)
{
	t_list	*current_a;
	t_list	*target;

	current_a = *stack_a;
	target = NULL;
	while (current_a)
	{
		if (current_a->content > node->content)
		{
			if (!target)
				target = current_a;
			else
				if (current_a->content < target->content)
					target = current_a;
		}
		current_a = current_a->next;
	}
	if (!target)
		return (lst_getmin(stack_a));
	return (target);
}

t_list	*get_target_pb(t_list *node, t_list **stack_b)
{
	t_list	*current_b;
	t_list	*target;

	current_b = *stack_b;
	target = NULL;
	while (current_b)
	{
		if (current_b->content < node->content)
		{
			if (!target)
				target = current_b;
			else
				if (target->content < current_b->content)
					target = current_b;
		}
		current_b = current_b->next;
	}
	if (!target)
		return (lst_getmax(stack_b));
	return (target);
}

int	get_cost(t_list *node, t_list *target, t_list **stack_a, t_list **stack_b)
{
	int	median_a;
	int	median_b;
	int	target_index;
	int	node_index;

	median_a = lst_len(stack_a) / 2;
	median_b = lst_len(stack_b) / 2;
	target_index = get_index(target, stack_b);
	node_index = get_index(node, stack_a);
	if (node_index <= median_a && target_index <= median_b)
		return (highest_num(node_index, target_index));
	if (node_index > median_a && target_index > median_b)
		return (highest_num(lst_len(stack_a)
				- node_index, lst_len(stack_b) - target_index));
	if (node_index > median_a && target_index <= median_b)
		return (highest_num(lst_len(stack_a) - node_index, target_index));
	if (node_index <= median_a && target_index > median_b)
		return (highest_num(node_index, lst_len(stack_b) - target_index));
	return (INT_MAX);
}

t_list	*lowest_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_a;
	t_list	*target;
	t_list	*next_push;
	int		lowest_cost;

	current_a = *stack_a;
	lowest_cost = INT_MAX;
	while (current_a)
	{
		target = get_target_pb(current_a, stack_b);
		if (lowest_cost > get_cost(current_a, target, stack_a, stack_b))
		{
			next_push = current_a;
			lowest_cost = get_cost(current_a, target, stack_a, stack_b);
		}
		current_a = current_a->next;
	}
	return (next_push);
}
