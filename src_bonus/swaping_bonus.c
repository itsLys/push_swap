/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:01:03 by ihajji            #+#    #+#             */
/*   Updated: 2025/04/02 15:55:15 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(char stack_type, t_data *data)
{
	t_stack	**head;
	t_stack	*first;
	t_stack	*second;

	head = NULL;
	if (stack_type == 'a')
		head = data->stack_a;
	else if (stack_type == 'b')
		head = data->stack_b;
	if (head && stack_size(*head) > 1)
	{
		first = *head;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*head = second;
	}
}

void	sa(t_data *data)
{
	stack_swap('a', data);
}

void	sb(t_data *data)
{
	stack_swap('b', data);
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
