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

#include "push_swap.h"

static int	check_repitition(t_stack **list)
{
	long	curr;
	t_stack	*node1;
	t_stack	*node2;

	node1 = *list;
	while (node1)
	{
		curr = node1->value;
		node2 = node1->next;
		while (node2)
		{
			if (curr == node2->value)
				return (ERROR);
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return (SUCCESS);
}

static int	check_values(t_stack **list)
{
	long	value;
	t_stack	*node;

	node = *list;
	while (node)
	{
		value = node->value;
		if (value > INT_MAX || value < INT_MIN)
			return (ERROR);
		node = node->next;
	}
	return (SUCCESS);
}

static void	add_to_stack(t_stack **stack, long value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->value = value;
	node->next = NULL;
	stack_add_back(stack, node);
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
		add_to_stack(data->stack_a, ft_atol(vec[i]));
		i++;
	}
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
		handle_error(NULL, data);
	if (check_values(data->stack_a) == ERROR)
		handle_error(NULL, data);
	data->size = stack_size(*data->stack_a);
	if (data->size <= 100)
		data->chunks = 5;
	else
		data->chunks = 11;
	data->chunk_size = data->size / data->chunks;
}
