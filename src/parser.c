/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:46:20 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/20 08:30:41 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

static void	add_to_list(t_list **stack, long value, t_data *data)
{
	t_stack_item	*item;
	t_list			*node;

	item = malloc(sizeof(t_stack_item));
	if (item == NULL)
		return ;
	item->value = value;
	node = ft_lstnew(item);
	if (node == NULL)
		exit_program(FAILIURE, EMPTY, data);
	ft_lstadd_back(stack, node);
}


static int	check_repitition(t_list **list)
{
	long	curr;
	t_list	*node1;
	t_list	*node2;

	node1 = *list;
	while (node1)
	{
		curr = get_value(node1);
		node2 = node1->next;
		while (node2)
		{
			// NOTE: use get_value()
			if (curr == get_value(node2))
				return (ERROR);
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return (SUCCESS);
}

static int	check_values(t_list **list)
{
	long	value;
	t_list	*node;

	node = *list;
	while (node)
	{
		// NOTE: use get_value()
		value = get_value(node);
		if (value > INT_MAX || value < INT_MIN)
			return (ERROR);
		node = node->next;
	}
	return (SUCCESS);
}

static void	init_stacks(char **vec, t_data *data)
{
	int	i;

	i = 0;
	while (vec[i])
	{
		if (ft_strisdecimal(vec[i]) == FALSE)
		{
			ft_free_vector(vec);
			handle_error(NULL, data);
		}
		add_to_list(data->stack_a, ft_atol(vec[i]), data);
		i++;
	}
	ft_lstadd_back(data->stack_b, NULL);
}

void	parse_input(int ac, char **av, t_data *data)
{
	int		i;
	char	**tokens;

	i = 1;
	while (i < ac)
	{
		tokens = ft_split(av[i], ' ');
		if (tokens == NULL || tokens[0] == NULL)
			handle_error((void *[]){tokens, NULL}, data);
		init_stacks(tokens, data);
		i++;
		ft_free_vector(tokens);
	}
	if (check_repitition(data->stack_a) == ERROR)
		handle_error(EMPTY, data);
	if (check_values(data->stack_a) == ERROR)
		handle_error(EMPTY, data);
	data->size = ft_lstsize(*data->stack_a);
}
