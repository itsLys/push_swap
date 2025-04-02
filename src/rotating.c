/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:02:35 by ihajji            #+#    #+#             */
/*   Updated: 2025/04/02 12:28:34 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rotate(char stack_type, t_data *data)
{
	t_stack	**head;
	t_stack	*first;

	head = NULL;
	if (stack_type == 'a')
		head = data->stack_a;
	else if (stack_type == 'b')
		head = data->stack_b;
	if (head && stack_size(*head) > 1)
	{
		first = *head;
		*head = (*head)->next;
		stack_last(*head)->next = first;
		first->next = NULL;
	}
	ft_printf("r%c\n", stack_type);
}

void	ra(t_data *data)
{
	stack_rotate('a', data);
}

void	rb(t_data *data)
{
	stack_rotate('b', data);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
