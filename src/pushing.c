/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:01:44 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/19 09:01:44 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	t_list	*node;
	t_list	*next;

	if (ft_lstsize(*data->stack_b) == 0)
		return ;
	node = *data->stack_b;
	next = (*data->stack_b)->next;
	ft_lstadd_front(data->stack_a, node);
	*data->stack_b = next;
}

void	pb(t_data *data)
{
	t_list	*node;
	t_list	*next;

	if (ft_lstsize(*data->stack_a) == 0)
		return ;
	node = *data->stack_a;
	next = (*data->stack_a)->next;
	ft_lstadd_front(data->stack_b, node);
	*data->stack_a = next;
}
