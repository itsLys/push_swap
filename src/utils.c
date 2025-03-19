/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:47:14 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/18 07:48:54 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	exit_program(int status, void **list, t_data *data)
{
	while (*list)
		free(*(list++));
	ft_lstclear(data->stack_a, free);
	ft_lstclear(data->stack_b, free);
	free(data->stack_a);
	free(data->stack_b);
	free(data);
	exit(status);
}

void	handle_error(void **list, t_data *data)
{
	write(STDERR, "Error\n", 6);
	exit_program(FAILIURE, list, data);
}
