/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:02:35 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/20 08:08:05 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rotate(t_data *data)
{
	t_stack	**head;
	t_stack	*first;

	head = NULL;
	if (data->stack_type == 'a')
	{
		head = data->stack_a;
		ft_printf("ra\n");
	}
	else if (data->stack_type == 'b')
	{
		head = data->stack_b;
		ft_printf("rb\n");
	}
	if (head && stack_size(*head) > 1)
	{
		first = *head;
		*head = (*head)->next;
		stack_last(*head)->next = first;
		first->next = NULL;
	}
}

void	ra(t_data *data)
{
	data->stack_type = 'a';
	stack_rotate(data);
}

void	rb(t_data *data)
{
	data->stack_type = 'b';
	stack_rotate(data);
}

void	rr(t_data *data)
{
	data->stack_type = 'a';
	ra(data);
	data->stack_type = 'b';
	rb(data);
}
