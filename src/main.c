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
	printf("stack %c:	\n", c);
	while (node)
	{
		printf("index:	%d", node->index);
		printf(" value:	%ld\n", node->value);
		node = node->next;
		// if (node)
		// 	printf(", ");
	}
	printf("\n");
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
	return sec_lowest;
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

	data->sorted = malloc(sizeof(int) * data->size);
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

void	set_index(t_data *data)
{
	int i;
	t_stack *node;

	init_sorted(data);
	i = 0;
	node = *data->stack_a;
	while (i < data->size)
	{
		node = *data->stack_a;
		while (data->sorted[i] != node->value)
			node = node->next;
		node->index = i;
		i++;
	}
}


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

int get_position(t_stack **stack, t_stack *node)
{
	t_stack *tmp;
	int i;

	i = 0;
	tmp = *stack;
	while (tmp != node)
	{
		tmp = tmp->next;
		i++;
	}
	return i;
}

int get_cost(t_stack **stack, t_stack *node)
{
	int index;
	int size;

	index = get_position(stack, node);
	size = stack_size(*stack);
	if (index > size / 2)
		return size - index;
	else
		return index;

}

t_stack *get_element_in_range(t_stack **stack, int min, int max)
{
	t_stack *node;

	node = *stack;
	while (node)
	{
		if (node->value >= min && node->value <= max)
			break;
		node = node->next;
	}
	return node;
}

t_stack *get_best_in_range(t_stack **stack, int min, int max)
{
	t_stack *node1;
	t_stack *tmp;
	t_stack *node2;

	node1 = get_element_in_range(stack, min, max);
	if (node1 == NULL)
		return NULL;
	tmp = get_element_in_range(&(node1->next), min, max);
	if (tmp == NULL)
		return node1;
	while (tmp)
	{
		node2 = tmp;
		tmp = get_element_in_range(&(node2->next), min, max);
	}
	if (get_cost(stack, node1) <= get_cost(stack, node2))
		return node1;
	else
		return node2;
}

// t_stack *get_best_in_range(t_stack **stack, int min, int max)
// {
// 	t_stack *best = NULL;
// 	int best_cost = 0;
// 	int cost;
// 	t_stack *tmp = *stack;
//
// 	while (tmp)
// 	{
// 		if (tmp->value >= min && tmp->value <= max)
// 		{
// 			cost = get_cost(stack, tmp);
// 			if (best == NULL || cost < best_cost)
// 			{
// 				best = tmp;
// 				best_cost = cost;
// 			}
// 		}
// 		tmp = tmp->next;
// 	}
// 	return best;
// }

void push_rotate_a(t_data *data)
{
	t_stack *target;
	int index;
	int size;

	while (*data->stack_a &&
		((*data->stack_a)->value >= data->min && (*data->stack_a)->value <= data->max))
	{
		pb(data);
		if (*data->stack_b && ((*data->stack_b)->value < (data->min + data->max) / 2))
			rb(data);
	}
	target = get_best_in_range(data->stack_a, data->min, data->max);
	if (!target)
		return;
	index = get_position(data->stack_a, target);
	size = stack_size(*data->stack_a);
	if (index > size / 2)
		rra(data);
	else
		ra(data);
}

int has_element_in_range(t_stack **stack, int min, int max)
{
	t_stack *node;

	node = *stack;
	while (node)
	{
		if (node->value >= min && node->value <= max)
			return TRUE;
		node = node->next;
	}
	return FALSE;
}

void set_data(t_data *data)
{
	int div;

	// NOTE: changes based on size of stack_a
	div = 4;
	data->chunk_size = (stack_size(*data->stack_a) - 5) / div + 1;
	data->min = stack_size(*data->stack_b);
	data->max = data->min + data->chunk_size - 1;
	data->delim = (data->max + data->min) / 2;
	// printf("chunk size:	%d\n", data->chunk_size);
	// printf("min:		%d\n", data->min);
	// printf("max:		%d\n", data->max);
	// printf("delim:		%d\n", data->delim);

}

void merge_back(t_data *data)
{
	t_stack *highest;
	int size;

	while (stack_size(*data->stack_b))
	{
		highest = find_highest(*data->stack_b);
		while (*data->stack_b != highest)
		{
			size = stack_size(*data->stack_b);
			if (get_position(data->stack_b, highest) > size / 2)
				rrb(data);
			else
				rb(data);
		}
		pa(data);
	}
}

void put_elemnt_index_first(t_data *data)
{
	t_stack **stack;

	stack = NULL;
	if (data->stack_type == 'a')
		stack = data->stack_a;
	else if (data->stack_type == 'b')
		stack = data->stack_b;
	// printf("stack type: %c\n" ,data->stack_type);
	// printf("index_pos: %d | pos of half stack: %d\n", data->index_pos, stack_size(*stack)/2 + 1);
	if (data->index_pos < stack_size(*stack) / 2 - 1)
	{
	//	while (data->index != (*stack)->index) {
			// printf("here :/\n");
		for (int i = 0; i < data->index_pos; i++){
			stack_rotate(data);
		}
	}
	else
	{
		//while (data->index != (*stack)->index)

		for (int i = 0; i < stack_size(*stack) - data->index_pos; i++)
			stack_reverse_rotate(data);
	}

	// other function body: push into other stack
	stack_push(data);
	// print_stack(data->stack_a, 'a');
	// print_stack(data->stack_b, 'b');
	if (data->stack_type == 'a')
		data->stack_type = 'b';
	else
		data->stack_type = 'a';
	// printf("---------\nelem_index: %d  delim: %d\n", (*stack)->index, data->delim);
	if ((*stack)->index > data->delim)
		stack_rotate(data);
}

void push_chunk_b(t_data *data)
{
	t_stack *tmp;

	data->stack_type = 'a';
	tmp = *data->stack_a;
	data->index_pos = 0;
	data->index = -2;
	while (tmp)
	{
		if (tmp->index <= data->max)
			break ;
		data->index_pos++;
		data->index = tmp->index;
		tmp = tmp->next;
	}
	put_elemnt_index_first(data);
}


void sort(t_data *data)
{
	while (stack_size(*data->stack_a) > 5)
	{
		set_data(data);
		for (int i = 0; i < data->chunk_size; i++)
			push_chunk_b(data);
	}
	sort_5(data);
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
	// print_stack(data->stack_a, 'a');
	// print_stack(data->stack_b, 'b');
	// printf("after\n");
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
