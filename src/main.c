/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:44:09 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/20 08:18:40 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// test function
void	print_stack(t_stack **stack, char c)
{
	t_stack	*node;

	node = *stack;
	printf("stack %c:	[", c);
	while (node)
	{
		printf("%ld", node->value);
		node = node->next;
		if (node)
			printf(", ");
	}
	printf("]\n");
}

void	exit_program(int status, void **list, t_data *data)
{
	if (list)
		while (*list)
			free(*(list++));
	clear_stack(data->stack_a);
	clear_stack(data->stack_b);
	free(data->stack_a);
	free(data->stack_b);
	free(data->sorted);
	free(data);
	exit(status);
}

void	handle_error(void **list, t_data *data) // in header
{
	write(STDERR, "Error\n", 6);
	exit_program(FAILIURE, list, data);
}

// NOTE: sorting utils

int stack_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return FALSE;
		stack = stack->next;
	}
	return TRUE;
}

t_stack *find_highest(t_stack *stack)
{
	t_stack	*highest;

	highest = stack;
	while (stack)
	{
		if (stack->value > highest->value)
			highest = stack;
		stack = stack->next;
	}
	return highest;
}


t_stack *find_smallest(t_stack *stack)
{
	t_stack	*lowest;

	lowest = stack;
	while (stack)
	{
		if (stack->value < lowest->value)
			lowest = stack;
		stack = stack->next;
	}
	return lowest;
}

t_stack *find_sec_smallest(t_stack *stack)
{
	t_stack	*lowest;
	t_stack	*sec_lowest;

	lowest = find_smallest(stack);
	sec_lowest = stack;
	while (stack)
	{
		if ((stack->value < sec_lowest->value) && stack != lowest)
			sec_lowest = stack;
		stack = stack->next;
	}
	return sec_lowest;
}

void sort_3(t_data *data)
{
	t_stack **stack_a;

	stack_a = data->stack_a;
	if (*stack_a == find_highest(*stack_a))
		ra(data);
	else if ((*stack_a)->next == find_highest(*stack_a))
		rra(data);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(data);
}

void sort_5(t_data *data)
{
	t_stack *lowest;
	t_stack *sec_lowest;

	lowest = find_smallest(*data->stack_a);
	sec_lowest = find_sec_smallest(*data->stack_a);
	while (stack_size(*data->stack_a) > 3)
	{
		if (*data->stack_a == lowest || *data->stack_a == sec_lowest)
			pb(data);
		else
			ra(data);
	}
	sort_3(data);
	pa(data);
	pa(data);
	if ((*data->stack_a)->value > (*data->stack_a)->next->value)
		sa(data);
}

void ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	init_sorted(t_data *data)
{
	int i;
	int j;
	t_stack *node;

	node = *data->stack_a;
	i = 0;
	while (i < data->size)
	{
		data->sorted[i++] = node->value;
		node = node->next;
	}
	i = 0;
	while (i < data->size - 1)
	{
		j = i + 1;
		while (j < data->size)
		{
			if (data->sorted[i] > data->sorted[j])
				ft_swap(data->sorted + i, data->sorted + j);
			j++;
		}
		i++;
	}
}


// void merge_back(t_data *data)
// {
// 	t_stack *smallest;
//
// 	while (stack_size(*data->stack_b))
// 	{
// 		smallest = find_highest(*data->stack_b);
// 		while (*data->stack_b != smallest)
// 			rb(data);
// 		pa(data);
// 	}
// }
//
// int get_node_index(t_stack *stack, t_stack *node)
// {
// 	int i;
//
// 	i = 0;
// 	while (stack)
// 	{
// 		if (stack == node)
// 			return i;
// 		i++;
// 	}
// 	return ERROR;
// }
//
// void push_rotate(t_stack *stack, t_stack *node, t_data *data)
// {
// 	int mid_list;
//
// 	mid_list = stack_size(*data->stack_a) / 2;
// 	if ((*data->stack_a)->value >= data->min
// 		&& (*data->stack_a)->value <= data->max)
// 		pb(data);
// 	else
// 	{
// 		if (get_node_index(*data->stack_a, node) > mid_list)
// 			rra(data);
// 		else
// 			ra(data);
// 	}
// }

int get_index(t_stack **stack, t_stack *node)
{

}

int get_cost(t_stack **stack, t_stack *node)
{

}

t_stack *get_element_in_range(t_stack **stack, int min, int max)
{
	t_stack *node;

	node = *stack;
	while (node)
	{
		if (node->value >= min || node->value <= max)
			break;
		node = node->next;
	}
	return node;
}

t_stack *get_best_in_range(t_stack **stack, int min, int max)
{
	int cost1;
	int cost2;
	t_stack *node1;
	t_stack *node2;
	t_stack *tmp;

	node1 = get_element_in_range(stack, min, max);
	if (node1 == NULL)
		return NULL;
	node2 = get_element_in_range(&(node1->next), min, max);
	while (node2)
	{
		tmp = node2;
		node2 = get_element_in_range(&(node1->next), min, max);
	}


	return NULL;
}

void sort(t_data *data)
{
	int i;
	t_stack	*node;

	data->sorted = malloc(sizeof(int) * data->size);
	init_sorted(data);
	i = 0;
	while (i < data->chunks)
	{
		data->min = data->sorted[i * data->chunk_size];
		if (i == data->chunks - 1)
			data->max = data->sorted[data->size - 1];
		else
			data->max = data->sorted[(i + 1) * data->chunk_size - 1];
		node = get_best_in_range(data->stack_a, data->min, data->max);
		while (node)
		{
			push_rotate(*data->stack_b, node, data);
			node = get_best_in_range(*data->stack_a, data->min, data->max);
			// if ((*data->stack_a)->value >= min && (*data->stack_a)->value <= max)
			// 	pb(data);
			// else
			// 	ra(data);
		}
		i++;
	}
	merge_back(data);
}

// NOTE: sorting utils end
int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 1)
		return (FAILIURE);
	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return (FAILIURE);
	data->stack_a = ft_calloc(1, sizeof(t_stack *));
	data->stack_b = ft_calloc(1, sizeof(t_stack *));
	if (data->stack_a == NULL || data->stack_b == NULL)
		exit_program(FAILIURE, NULL, data);
	parse_input(ac, av, data);
	if (!stack_is_sorted(*data->stack_a))
	{
		if (stack_size(*data->stack_a) == 2)
			sa(data);
		else if (stack_size(*data->stack_a) == 3)
			sort_3(data);
		else if (stack_size(*data->stack_a) <= 5)
			sort_5(data);
		else
			sort(data);
	}
	// print_stack(data->stack_a, 'a');
	// print_stack(data->stack_b, 'b');
	exit_program(SUCCESS, NULL, data);
}
