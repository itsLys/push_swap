/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:01:03 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/20 08:08:33 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (!head || !*head || stack_size(*head) <= 1)
		return ;
	first = *head;
	second = first->next;

	first->next = second->next;
	second->next = first;
	*head = second;
}

void	sa(t_data *data)
{
	stack_swap(data->stack_a);
	ft_printf("sa\n");
}

void	sb(t_data *data)
{
	stack_swap(data->stack_b);
	ft_printf("sb\n");
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
