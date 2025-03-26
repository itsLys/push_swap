/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotating.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:03:16 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/20 08:07:52 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

void	stack_reverse_rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	**list;

	if (head == NULL || stack_size(*head) <= 1)
		return ;
	last = stack_last(*head);
	last->next = *head;
	list = head;
	while ((*list)->next != last)
		*list = (*list)->next;
	(*list)->next = NULL;
	*head = last;
}

void	rra(t_data *data)
{
	stack_reverse_rotate(data->stack_a);
	ft_printf("rra\n");
}

void	rrb(t_data *data)
{
	stack_reverse_rotate(data->stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
