/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotating.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:03:16 by ihajji            #+#    #+#             */
/*   Updated: 2025/04/02 12:28:16 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

void	stack_reverse_rotate(char stack_type, t_data *data)
{
	t_stack	**head;
	t_stack	*last;
	t_stack	**list;

	head = NULL;
	if (stack_type == 'a')
		head = data->stack_a;
	else if (stack_type == 'b')
		head = data->stack_b;
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
	ft_printf("rr%c\n", stack_type);
}

void	rra(t_data *data)
{
	stack_reverse_rotate('a', data);
}

void	rrb(t_data *data)
{
	stack_reverse_rotate('b', data);
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
