/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:46:20 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/18 07:49:32 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	init_stack(char **vec, t_data *data)
{
	while (*vec)
	{
		if (ft_strisdecimal(*vec) == FALSE)
			handle_error((void *[]) {*vec, vec, NULL}, data);
		push(data->stack_a, ft_atol(*vec), data);
		free(*(vec++));
	}
}
static int check_repitition(t_list **list)
{
	long	curr;
	t_list	*node1;
	t_list	*node2;

	node1 = *list;
	while (node1)
	{
		curr = ((t_stack_item *)(node1->content))->value;
		node2 = node1->next;
		while (node2)
		{

			if (curr == ((t_stack_item *)(node2->content))->value)
				return ERROR;
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return SUCCESS;
}

static int check_values(t_list **list)
{
	long	value;
	t_list	*node;

	node = *list;
	while (node)
	{
		value = ((t_stack_item *)(node->content))->value;
		if (value > INT_MAX || value < INT_MIN)
			return ERROR;
		node = node->next;
	}
	return SUCCESS;
}

void	parse_input(int ac, char **av, t_data *data)
{
	int	i;
	char **tokens;

	i = 1;
	while (i < ac)
	{
		tokens = ft_split(av[i], ' ');
		if (tokens == NULL || tokens[0] == NULL)
			handle_error((void *[]){tokens, NULL}, data);
		init_stack(tokens, data);
		i++;
		free(tokens);
	}
	if (check_repitition(data->stack_a) == ERROR )
		handle_error(EMPTY, data);
	if (check_values(data->stack_a) == ERROR)
		handle_error(EMPTY, data);
	data->size = ft_lstsize(*data->stack_a);
}
