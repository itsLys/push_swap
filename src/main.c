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
int stack_is_sorted(t_stack *stack);
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
	printf("start is sorted:	%d\n", stack_is_sorted(*stack));
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

void sort_3(t_data *data) {
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
	node->index = -1;
}

void set_data(t_data *data)
{
	int div;

	// NOTE: changes based on size of stack_a
	div = 0;
	if (data->size<= 100)
		div = 5;
	else if (data->size - 5 > 100)
		div = 12;
	// data->chunk_size = (stack_size(*data->stack_a) - 5) / div + 1;
	data->chunk_size = data->size  / div ;
	data->min = stack_size(*data->stack_b);
	data->max = data->min + data->chunk_size - 1;
	data->delim = (data->max + data->min) / 2;
	// printf("chunk size:	%d\n", data->chunk_size);
	// printf("min:		%d\n", data->min);
	// printf("max:		%d\n", data->max);
	// printf("delim:		%d\n", data->delim);

}

int has_element_in_stack(int index, t_stack *node)
{
	while (node)
	{
		if (node->index == index)
			return TRUE;
		node = node->next;
	}
	return FALSE;
}

int find_index(int index, t_stack *stack)
{
	int i;

	i = 0;

	// printf("index:				%d\n", index);
	// printf("stack index:		%d\n", stack->index);
	if (stack == NULL)
		return  ERROR;
	while (stack && stack->index != index)
	{
		stack = stack->next;
		i++;
	}
	if (stack == NULL)
		return ERROR;
	return i;
}

void push_rotate_elemnt(t_stack *node, t_data *data)
{
	stack_push(data);
	if (data->stack_type == 'b')
		data->stack_type = 'a';
	else
		data->stack_type = 'b';
	if (node->index > data->delim)
		stack_rotate(data);
}

void put_elemnt_index_first(int position, t_data *data)
{
	t_stack **stack;
	int i;

	stack = NULL;
	if (data->stack_type == 'a')
		stack = data->stack_a;
	else if (data->stack_type == 'b')
		stack = data->stack_b;
	i = 0;
	if (position < stack_size(*stack) / 2 - 1)
	{
		while (i++ < position)
			stack_rotate(data);
	}
	else
{
		while (i++ < stack_size(*stack) - position)
			stack_reverse_rotate(data);
	}

}

void merge_back(t_data *data)
{
	int top_a;
	int top_b;
	int position;

	while (stack_size(*data->stack_b))
	{
		data->stack_type = 'b';
		top_a = (*data->stack_a)->index;
		top_b = (*data->stack_b)->index;
		if (top_a == top_b - 1)
			pa(data);
		else if (!has_element_in_stack(top_a - 1, *data->stack_b))
		{
		rra(data);
	}
		else if (top_b < top_a && top_b > stack_last(*data->stack_a)->index)
		{
		pa(data);
		ra(data);
	}
		else if (has_element_in_stack(top_a - 1, *data->stack_b))
		{
			position = find_index(top_a - 1, *data->stack_b);
			put_elemnt_index_first(position, data);
			push_rotate_elemnt(*data->stack_b, data);
		}
	}
}


void push_chunk_b(t_data *data)
{
	t_stack *node;
	int position;

	node = *data->stack_a;
	while (node)
	{
		if (node->index <= data->max && node->index != -1)
			break;
		node = node->next;
	}
	if (node == NULL)
		return ;
	position = find_index(node->index, *data->stack_a);
	// printf("position:	%d \n", position);
	// printf("index:		%d \n", node->index);
	// print_stack(data->stack_a, 'a');
	if (position == ERROR)
		return ;
	data->stack_type = 'a';
	put_elemnt_index_first(position, data);
	push_rotate_elemnt(node , data);
}

void sort(t_data *data)
{
	int position;

	while (1)
	{
		set_data(data);
		for (int i = 0; i < data->chunk_size; i++)
			push_chunk_b(data);
		if (stack_size(*data->stack_a) == 0)
			break;
	}
	// sort_5(data);
	merge_back(data);
	data->stack_type = 'a';
	position = find_index(0, *data->stack_a);
	put_elemnt_index_first(position, data);
}

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
