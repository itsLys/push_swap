/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:44:09 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/18 07:50:32 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_data	*data;

	if (ac == 1)
		return FAILIURE;
	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return FAILIURE;
	data->stack_a = ft_calloc(1, sizeof(t_list *));
	data->stack_b = ft_calloc(1, sizeof(t_list *));
	if (data->stack_a == NULL || data->stack_b == NULL)
		exit_program(FAILIURE, EMPTY, data);
	parse_input(ac, av, data);
	// sa(data);
	pb(data);
	t_list *node_a = *(data->stack_a);
	t_list *node_b = *(data->stack_b);
	printf("stack_a:	");
	while (node_a)
	{
		printf("%ld, ", ((t_stack_item *)(node_a->content))->value);
		node_a = node_a->next;
	}
	printf("\n");
	printf("stack_b:	");
	// while (node_b)
	// {
	// 	printf("%ld, ", ((t_stack_item *)(node_b->content))->value);
	// 	node_b = node_b->next;
	// }
	printf("\n");
	exit_program(SUCCESS, EMPTY, data);

}
