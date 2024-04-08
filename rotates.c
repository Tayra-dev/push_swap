/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:42:10 by hle-roi           #+#    #+#             */
/*   Updated: 2024/02/13 14:36:54 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

void	rotate_a(t_list **stack, int bool)
{
	t_list	*tmp;
	t_list	*current;

	if (lst_len(stack) >= 2)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = tmp;
		tmp->next = NULL;
	}
	if (bool == TRUE)
		ft_printf("ra\n");
}

void	rotate_b(t_list **stack, int bool)
{
	t_list	*tmp;
	t_list	*current;

	if (lst_len(stack) >= 2)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = tmp;
		tmp->next = NULL;
	}
	if (bool == TRUE)
		ft_printf("rb\n");
}

void	rotate_all(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a, FALSE);
	rotate_b(stack_b, FALSE);
	ft_printf("rr\n");
}
