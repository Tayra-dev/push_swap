/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:45:25 by hle-roi           #+#    #+#             */
/*   Updated: 2024/02/13 14:37:05 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

void	swap_a(t_list **stack, int bool)
{
	int	tmp;

	if (lst_len(stack) >= 2)
	{
		tmp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
	}
	if (bool == TRUE)
		ft_printf("sa\n");
}

void	swap_b(t_list **stack, int bool)
{
	int	tmp;

	if (lst_len(stack) >= 2)
	{
		tmp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
	}
	if (bool == TRUE)
		ft_printf("sb\n");
}

void	swap_all(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a, FALSE);
	swap_b(stack_b, FALSE);
	ft_printf("ss\n");
}
