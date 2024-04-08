/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:44:44 by hle-roi           #+#    #+#             */
/*   Updated: 2024/02/13 14:36:28 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_a;
	t_list	*top_b;

	if (stack_b == NULL)
		return ;
	top_a = *stack_a;
	top_b = *stack_b;
	*stack_b = top_b->next;
	top_b->next = top_a;
	*stack_a = top_b;
	ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_a;
	t_list	*top_b;

	if (stack_a == NULL)
		return ;
	top_a = *stack_a;
	top_b = *stack_b;
	*stack_a = top_a->next;
	top_a->next = top_b;
	*stack_b = top_a;
	ft_printf("pb\n");
}
