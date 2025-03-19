/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:44:09 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/19 09:08:21 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// test function
void	print_stack(t_list **stack, char c)
{
	t_list	*node;

	node = *stack;
	printf("stack %c:	[", c);
	while (node)
	{
		printf("%ld", ((t_stack_item *)(node->content))->value);
		node = node->next;
		if (node)
			printf(", ");
	}
	printf("]\n");
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 1)
		return (FAILIURE);
	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return (FAILIURE);
	data->stack_a = ft_calloc(1, sizeof(t_list *));
	data->stack_b = ft_calloc(1, sizeof(t_list *));
	if (data->stack_a == NULL || data->stack_b == NULL)
		exit_program(FAILIURE, EMPTY, data);
	parse_input(ac, av, data);
	print_stack(data->stack_a, 'a');
	rra(data);
	print_stack(data->stack_a, 'a');
	exit_program(SUCCESS, EMPTY, data);
}
