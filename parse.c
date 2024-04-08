/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:49:12 by hle-roi           #+#    #+#             */
/*   Updated: 2024/03/12 11:35:26 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

int	lowest_num(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	check_dupe(t_list **stack)
{
	t_list	*current;
	t_list	*current_two;

	current = *stack;
	while (current)
	{
		current_two = *stack;
		while (current_two)
		{
			if (current->content == current_two->content
				&& current != current_two)
			{
				free_list(stack);
				print_error();
				return (1);
			}
			current_two = current_two->next;
		}
		current = current->next;
	}
	return (0);
}

int	parse_string(char *str, t_list **stack)
{
	char	**split;
	int		i;
	t_list	*new;

	i = 0;
	split = ft_split(str, ' ');
	if (!split || split[0] == NULL)
		exit(0);
	while (split[i])
	{
		new = ft_lstnew(ft_atoi(split[i]));
		if (new == NULL)
		{
			while (split[i])
				free(split[i++]);
			free(split);
			return (1);
		}
		ft_lstadd_back(stack, new);
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

void	print_stack(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = stack_a;
	current_b = stack_b;
	ft_printf("---------------\n");
	while (current_a || current_b)
	{
		if (current_a)
		{
			ft_printf("%d ", current_a->content);
			current_a = current_a->next;
		}
		else
			ft_printf("  ");
		if (current_b)
		{
			ft_printf("%d\n", current_b->content);
			current_b = current_b->next;
		}
		else
			ft_printf(" \n");
	}
	ft_printf("---------------\n");
}
