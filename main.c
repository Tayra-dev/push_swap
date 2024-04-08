/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:04:12 by hle-roi           #+#    #+#             */
/*   Updated: 2024/03/12 12:02:56 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

void	free_list(t_list **stack)
{
	t_list	*current;
	t_list	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	sort_three(t_list **stack)
{
	t_list	*max;

	max = lst_getmax(stack);
	if (max == *stack)
		rotate_a(stack, TRUE);
	else if ((*stack)->next == max)
		reverse_rotate_a(stack, TRUE);
	if ((*stack)->content > (*stack)->next->content)
		swap_a(stack, TRUE);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	if (is_sort(stack_a))
		return (free_list(stack_a));
	else if (lst_len(stack_a) == 2)
	{
		swap_a(stack_a, TRUE);
		return (free_list(stack_a));
	}
	else if (lst_len(stack_a) == 3)
	{
		sort_three(stack_a);
		return (free_list(stack_a));
	}
	else
	{
		turk_algorithm(stack_a, stack_b, lst_len(stack_a));
		return (free_list(stack_a));
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*new;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			new = ft_lstnew(ft_atoi(argv[i++]));
			if (new == NULL)
				return (free_list(&stack_a), print_error(), 0);
			ft_lstadd_back(&stack_a, new);
		}
	}
	if (argc == 2)
	{
		if (parse_string(argv[1], &stack_a))
			return (free_list(&stack_a), print_error(), 0);
	}
	if (check_dupe(&stack_a) == 0 && argc != 1)
		push_swap(&stack_a, &stack_b);
}
