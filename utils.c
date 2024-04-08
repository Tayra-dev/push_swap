/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:16:36 by hle-roi           #+#    #+#             */
/*   Updated: 2024/02/19 12:26:02 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

int	lst_len(t_list **stack)
{
	int		i;
	t_list	*current;

	i = 0;
	current = *stack;
	while (current->next != NULL)
	{
		i++;
		current = current->next;
	}
	i++;
	return (i);
}

int	is_sort(t_list **stack)
{
	int		tmp;
	t_list	*current;

	current = *stack;
	tmp = current->content;
	while (current)
	{
		if (current->content < tmp)
			return (0);
		tmp = current->content;
		current = current->next;
	}
	return (1);
}

int	get_index(t_list *elt, t_list **stack)
{
	t_list	*current;
	int		i;

	current = *stack;
	i = 0;
	while (current)
	{
		if (current == elt)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

t_list	*lst_getmax(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	current = *stack;
	tmp = current;
	while (current)
	{
		if (current->content >= tmp->content)
			tmp = current;
		current = current->next;
	}
	return (tmp);
}

t_list	*lst_getmin(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	current = *stack;
	tmp = current;
	while (current)
	{
		if (current->content <= tmp->content)
			tmp = current;
		current = current->next;
	}
	return (tmp);
}
