/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:48:02 by hle-roi           #+#    #+#             */
/*   Updated: 2024/03/03 17:03:31 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

void	reverse_rotate_a(t_list **stack, int bool)
{
	t_list	*tmp;
	t_list	*current;
	int		i;

	if (lst_len(stack) >= 2)
	{
		i = 0;
		current = *stack;
		while (i < lst_len(stack) - 2)
		{
			i++;
			current = current->next;
		}
		tmp = *stack;
		*stack = current->next;
		current->next = NULL;
		(*stack)->next = tmp;
	}
	if (bool == TRUE)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_list **stack, int bool)
{
	t_list	*tmp;
	t_list	*current;
	int		i;

	if (lst_len(stack) >= 2)
	{
		i = 0;
		current = *stack;
		while (i < lst_len(stack) - 2)
		{
			i++;
			current = current->next;
		}
		tmp = *stack;
		*stack = current->next;
		current->next = NULL;
		(*stack)->next = tmp;
	}
	if (bool == TRUE)
		ft_printf("rrb\n");
}

void	reverse_rotate_all(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_a(stack_a, FALSE);
	reverse_rotate_b(stack_b, FALSE);
	ft_printf("rrr\n");
}

void	reverse_cycle_all(t_list **stack_a, t_list **stack_b, int index)
{
	while (index > 0)
	{
		reverse_rotate_all(stack_a, stack_b);
		index--;
	}
}
