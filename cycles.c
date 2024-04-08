/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:58:48 by hle-roi           #+#    #+#             */
/*   Updated: 2024/03/03 17:03:08 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

void	cycle_a(t_list **stack, int index)
{
	while (index > 0)
	{
		rotate_a(stack, TRUE);
		index--;
	}
}

void	cycle_b(t_list **stack, int index)
{
	while (index > 0)
	{
		rotate_b(stack, TRUE);
		index--;
	}
}

void	reverse_cycle_a(t_list **stack, int index)
{
	while (index > 0)
	{
		reverse_rotate_a(stack, TRUE);
		index--;
	}
}

void	reverse_cycle_b(t_list **stack, int index)
{
	while (index > 0)
	{
		reverse_rotate_b(stack, TRUE);
		index--;
	}
}

void	cycle_all(t_list **stack_a, t_list **stack_b, int index)
{
	while (index > 0)
	{
		rotate_all(stack_a, stack_b);
		index--;
	}
}
