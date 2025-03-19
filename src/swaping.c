/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:01:03 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/19 09:01:04 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	void	*tmp;
	t_list	*node;
	t_list	*next;

	if (ft_lstsize(*data->stack_a) <= 1)
		return ;
	node = *data->stack_a;
	next = (*data->stack_a)->next;
	tmp = node->content;
	node->content = next->content;
	next->content = tmp;
}

void	sb(t_data *data)
{
	void	*tmp;
	t_list	*node;
	t_list	*next;

	if (ft_lstsize(*data->stack_b) <= 1)
		return ;
	node = *data->stack_b;
	next = (*data->stack_b)->next;
	tmp = node->content;
	node->content = next->content;
	next->content = tmp;
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
