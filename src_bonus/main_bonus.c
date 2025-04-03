/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:44:09 by ihajji            #+#    #+#             */
/*   Updated: 2025/04/02 18:31:18 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	exit_program(int status, void **list, t_data *data)
{
	get_next_line(FREE_BUFFER);
	if (list)
		while (*list)
			free(*(list++));
	clear_stack(data->stack_a);
	clear_stack(data->stack_b);
	free(data->stack_a);
	free(data->stack_b);
	free(data->action);
	free(data);
	exit(status);
}

void	handle_error(void **list, t_data *data) // in header
{
	write(STDERR, "Error\n", 6);
	exit_program(FAILIURE, list, data);
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
	if (stack_is_sorted(*data->stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit_program(SUCCESS, NULL, data);
}
