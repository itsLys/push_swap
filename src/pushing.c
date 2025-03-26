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

// NOTE: stack utils
// void	stack_add_front(t_stack **lst, t_stack *new)
// {
// 	if (!new || !lst)
// 		return ;
// 	if (!*lst)
// 	{
// 		new->next = NULL;
// 		*lst = new;
// 		return ;
// 	}
// 	new->next = *lst;
// 	*lst = new;
// }
// NOTE: end

void	stack_push(t_stack **from, t_stack **to)
{
	t_stack	*node;
	t_stack	*next;

	if (from == NULL || to == NULL || from == to || stack_size(*from) == 0)
		return ;
	node = *from;
	next = (*from)->next;
	stack_add_front(to, node);
	*from = next;
}

void	pa(t_data *data)
{
	stack_push(data->stack_b, data->stack_a);
	ft_printf("pa\n");
}

void	pb(t_data *data)
{
	stack_push(data->stack_a, data->stack_b);
	ft_printf("pb\n");
}
