/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:01:44 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/20 08:08:19 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_data *data)
{
	t_stack	*node;
	t_stack	*next;
	t_stack **from;
	t_stack **to;

	from = NULL;
	to = NULL;
	if (data->stack_type == 'a')
	{
		from = data->stack_a;
		to = data->stack_b;
		ft_printf("pb\n");
	}
	else if (data->stack_type == 'b')
	{

		from = data->stack_b;
		to = data->stack_a;
		ft_printf("pa\n");
	}
	node = *from;
	next = (*from)->next;
	stack_add_front(to, node);
	*from = next;
}

void	pa(t_data *data)
{
	data->stack_type = 'b';
	stack_push(data);
}

void	pb(t_data *data)
{
	data->stack_type = 'a';
	stack_push(data);
}
