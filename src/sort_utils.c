/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:15:07 by ihajji            #+#    #+#             */
/*   Updated: 2025/04/02 12:15:09 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	stack_is_sorted(t_stack *stack)
// {
// 	while (stack->next)
// 	{
// 		if (stack->value > stack->next->value)
// 			return (FALSE);
// 		stack = stack->next;
// 	}
// 	return (TRUE);
// }

int	stack_is_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (FALSE);
	while (stack)
	{
		if (stack->next && stack->value > stack->next->value)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*lowest;

	lowest = stack;
	while (stack)
	{
		if (stack->value < lowest->value)
			lowest = stack;
		stack = stack->next;
	}
	return (lowest);
}

t_stack	*find_sec_smallest(t_stack *stack)
{
	t_stack	*lowest;
	t_stack	*sec_lowest;

	lowest = find_smallest(stack);
	if (stack != lowest)
		sec_lowest = stack;
	else
		sec_lowest = stack->next;
	while (stack)
	{
		if ((stack->value < sec_lowest->value) && stack != lowest)
			sec_lowest = stack;
		stack = stack->next;
	}
	return (sec_lowest);
}

t_stack	*find_highest(t_stack *stack)
{
	t_stack	*highest;

	highest = stack;
	while (stack)
	{
		if (stack->value > highest->value)
			highest = stack;
		stack = stack->next;
	}
	return (highest);
}

int	get_position(int index, t_stack *stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (ERROR);
	while (stack && stack->index != index)
	{
		stack = stack->next;
		i++;
	}
	if (stack == NULL)
		return (ERROR);
	return (i);
}
