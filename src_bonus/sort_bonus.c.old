/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:03:16 by ihajji            #+#    #+#             */
/*   Updated: 2025/04/02 12:06:40 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_data *data)
{
	t_stack	**stack_a;

	stack_a = data->stack_a;
	if (*stack_a == find_highest(*stack_a))
		ra(data);
	else if ((*stack_a)->next == find_highest(*stack_a))
		rra(data);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(data);
}

void	sort_5(t_data *data)
{
	t_stack	*lowest;
	t_stack	*sec_lowest;

	if (stack_size(*data->stack_a) <= 1)
		return ;
	lowest = find_smallest(*data->stack_a);
	sec_lowest = find_sec_smallest(*data->stack_a);
	while (stack_size(*data->stack_a) > 3)
	{
		if (*data->stack_a == lowest || *data->stack_a == sec_lowest)
			pb(data);
		else
			ra(data);
	}
	if (stack_size(*data->stack_a) == 2 && !stack_is_sorted(*data->stack_a))
		sa(data);
	else
		sort_3(data);
	pa(data);
	pa(data);
	if ((*data->stack_a)->value > (*data->stack_a)->next->value)
		sa(data);
}

void	sort(t_data *data)
{
	set_data(data);
	push_chunk_b(data);
	merge_back(data);
}
