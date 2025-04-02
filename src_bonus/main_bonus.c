/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:44:09 by ihajji            #+#    #+#             */
/*   Updated: 2025/04/02 16:03:12 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
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
	// free(data->sorted);
	free(data);
	exit(status);
}

void	handle_error(void **list, t_data *data) // in header
{
	write(STDERR, "Error\n", 6);
	exit_program(FAILIURE, list, data);
}

// void	set_data(t_data *data)
// {
// 	int			div;
// 	static int	range_initialized;
//
// 	if (range_initialized)
// 	{
// 		if (data->min + 1 < data->max)
// 			data->min += 1;
// 		if (data->max + 1 < data->size)
// 			data->max += 1;
// 	}
// 	else
// 	{
// 		range_initialized = 1;
// 		div = 5;
// 		if (data->size > 100)
// 			div = 12;
// 		data->chunk_size = data->size / div;
// 		data->min = 0;
// 		data->max = data->chunk_size;
// 	}
// }

void	read_stdin(t_data *data)
{
	char	*action;

	action = get_next_line(0);
	while (action)
	{
		if (ft_strcmp("sa", action))
			sa(data);
		else if (ft_strcmp("sb", action))
			sb(data);
		else if (ft_strcmp("ss", action))
			ss(data);
		else if (ft_strcmp("ra", action))
			ra(data);
		else if (ft_strcmp("rb", action))
			rb(data);
		else if (ft_strcmp("rr", action))
			rr(data);
		else if (ft_strcmp("rra", action))
			rra(data);
		else if (ft_strcmp("rrb", action))
			rrb(data);
		else if (ft_strcmp("rrr", action))
			rrr(data);
		else if (ft_strcmp("pa", action))
			pa(data);
		else if (ft_strcmp("pb", action))
			pb(data);
		else
			handle_error(NULL, data);
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
	read_stdin(data);
	// while (action)
	// {
	// 	if (ft_strcmp("sa", action))
	// 		sa(data);
	// 	else if (ft_strcmp("sb", action))
	// 		sb(data);
	// 	else if (ft_strcmp("ss", action))
	// 		ss(data);
	// 	else if (ft_strcmp("ra", action))
	// 		ra(data);
	// 	else if (ft_strcmp("rb", action))
	// 		rb(data);
	// 	else if (ft_strcmp("rr", action))
	// 		rr(data);
	// 	else if (ft_strcmp("rra", action))
	// 		rra(data);
	// 	else if (ft_strcmp("rrb", action))
	// 		rrb(data);
	// 	else if (ft_strcmp("rrr", action))
	// 		rrr(data);
	// 	else if (ft_strcmp("pa", action))
	// 		pa(data);
	// 	else if (ft_strcmp("pb", action))
	// 		pb(data);
	// 	else
	// 		handle_error(NULL, data);
	// }
	if (stack_is_sorted(*data->stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit_program(SUCCESS, NULL, data);
}
