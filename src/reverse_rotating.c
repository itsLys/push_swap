/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotating.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:03:16 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/19 09:03:18 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	t_list	*last;
	t_list	**list;

	if (ft_lstsize(*data->stack_a) <= 1)
		return ;
	last = ft_lstlast(*data->stack_a);
	last->next = *data->stack_a;
	list = data->stack_a;
	while ((*list)->next != last)
		*list = (*list)->next;
	(*list)->next = NULL;
	*data->stack_a = last;
}

void	rrb(t_data *data)
{
	t_list	*last;
	t_list	**list;

	if (ft_lstsize(*data->stack_b) <= 1)
		return ;
	last = ft_lstlast(*data->stack_b);
	last->next = *data->stack_b;
	list = data->stack_b;
	while ((*list)->next != last)
		*list = (*list)->next;
	(*list)->next = NULL;
	*data->stack_b = last;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
