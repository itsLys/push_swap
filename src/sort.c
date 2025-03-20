/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 07:37:23 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/20 08:18:16 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int	get_value(t_list *node)
{
	return *(int *) node->content;
}

t_list *find_highest(t_list *list)
{
	t_list *node;

	node = list;
	while (list)
	{
		if (get_value(list) > get_value(node))
			node = list;
		list = list->next;
	}
	return (node);
}


void sort_2(t_data *data)
{
	t_list **stack_a;

	stack_a = data->stack_a;
	if (get_value((*stack_a)) > get_value((*stack_a)->next))
		sa(data);
}

void sort_3(t_data *data)
{
	t_list *highest;
	t_list **stack_a;

	stack_a = data->stack_a;
	highest = find_highest(*data->stack_a);
	if (*stack_a == highest)
		ra(data);
	else if ((*stack_a)->next == highest)
		rra(data);
	if (get_value((*stack_a)) > get_value((*stack_a)->next))
		sa(data);
}

void sort_5(t_data *data)
{

}

void	sort(t_data *data)
{
	if (data->size == 1)
		return ;
	else if (data->size == 2)
		sort_2(data);
	else if (data->size == 3)
		sort_3(data);
	else if (data->size <= 5)
		sort_5(data);

}
