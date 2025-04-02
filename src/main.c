/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:44:09 by ihajji            #+#    #+#             */
/*   Updated: 2025/04/02 15:38:58 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// test function
// void	print_stack(t_stack **stack, char c)
// {
// 	t_stack	*node;
//
// 	node = *stack;
// 	printf("stack %c:	\n", c);
// 	while (node)
// 	{
// 		printf("index:	%2d", node->index);
// 		printf(" value:	%2ld\n", node->value);
// 		node = node->next;
// 	}
// 	printf("start is sorted:	%d\n", stack_is_sorted(*stack));
// }

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

void	set_data(t_data *data)
{
	int			div;
	static int	range_initialized;

	if (range_initialized)
	{
		if (data->min + 1 < data->max)
			data->min += 1;
		if (data->max + 1 < data->size)
			data->max += 1;
	}
	else
	{
		range_initialized = 1;
		div = 5;
		if (data->size > 100)
			div = 12;
		data->chunk_size = data->size / div;
		data->min = 0;
		data->max = data->chunk_size;
	}
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
	exit_program(SUCCESS, NULL, data);
}
