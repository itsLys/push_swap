/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:01:44 by ihajji            #+#    #+#             */
/*   Updated: 2025/04/02 15:55:15 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(char stack_type, t_data *data)
{
	t_stack	*node;
	t_stack	*next;
	t_stack	**from;
	t_stack	**to;

	from = NULL;
	to = NULL;
	if (stack_type == 'a')
	{
		from = data->stack_b;
		to = data->stack_a;
	}
	else if (stack_type == 'b')
	{
		from = data->stack_a;
		to = data->stack_b;
	}
	if (stack_size(*from) > 0)
	{
		node = *from;
		next = (*from)->next;
		stack_add_front(to, node);
		*from = next;
	}
}

void	pa(t_data *data)
{
	stack_push('a', data);
}

void	pb(t_data *data)
{
	stack_push('b', data);
}
