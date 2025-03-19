/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:02:35 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/19 09:02:35 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	t_list	*first;

	if (ft_lstsize(*data->stack_a) <= 1)
		return ;
	first = *data->stack_a;
	*data->stack_a = (*data->stack_a)->next;
	ft_lstlast(*data->stack_a)->next = first;
	first->next = NULL;
}

void	rb(t_data *data)
{
	t_list	*first;

	if (ft_lstsize(*data->stack_b) <= 1)
		return ;
	first = *data->stack_b;
	*data->stack_b = (*data->stack_b)->next;
	ft_lstlast(*data->stack_b)->next = first;
	first->next = NULL;
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
