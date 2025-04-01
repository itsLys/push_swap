/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotating.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:03:16 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/20 08:07:52 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

void	stack_reverse_rotate(t_data *data)
{
	t_stack **head;
	t_stack	*last;
	t_stack	**list;

	head = NULL;
	if (data->stack_type == 'a')
	{
		head = data->stack_a;
		ft_printf("rra\n");
	}
	else if (data->stack_type == 'b')
	{
		head = data->stack_b;
		ft_printf("rrb\n");
	}
	if (head && stack_size(*head) > 1)
	{
		last = stack_last(*head);
		last->next = *head;
		list = head;
		while ((*list)->next != last)
			*list = (*list)->next;
		(*list)->next = NULL;
		*head = last;
	}
}

void	rra(t_data *data)
{
	char prev;

	prev = data->stack_type;
	data->stack_type = 'a';
	stack_reverse_rotate(data);
	data->stack_type = prev;
}

void	rrb(t_data *data)
{
	char prev;

	prev = data->stack_type;
	data->stack_type = 'b';
	stack_reverse_rotate(data);
	data->stack_type = prev;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
