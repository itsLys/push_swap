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

void	stack_rotate(t_stack **head)
{
	t_stack	*first;

	if (head == NULL || stack_size(*head) <= 1)
		return ;
	first = *head;
	*head = (*head)->next;
	stack_last(*head)->next = first;
	first->next = NULL;
}

void	ra(t_data *data)
{
	stack_rotate(data->stack_a);
	ft_printf("ra\n");
}

void	rb(t_data *data)
{
	stack_rotate(data->stack_b);
	ft_printf("rb\n");
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
