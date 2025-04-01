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

void	stack_swap(t_data *data)
{

	t_stack **head;
	t_stack	*first;
	t_stack	*second;

	head = NULL;
	if (data->stack_type == 'a')
	{
		head = data->stack_a;
		ft_printf("sa\n");
	}
	else
	{
		head = data->stack_b;
		ft_printf("sb\n");
	}
	first = *head;
	second = first->next;

	first->next = second->next;
	second->next = first;
	*head = second;
}

void	sa(t_data *data)
{
	char prev;

	prev = data->stack_type;
	data->stack_type = 'a';
	stack_swap(data);
	data->stack_type = prev;
}

void	sb(t_data *data)
{
	char prev;

	prev = data->stack_type;
	data->stack_type = 'b';
	stack_swap(data);
	data->stack_type = prev;
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
