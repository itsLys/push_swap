/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:46:42 by ihajji            #+#    #+#             */
/*   Updated: 2025/04/02 18:37:05 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

static void	handle_swap(char *action, t_data *data)
{
	if (ft_strcmp("sa\n", action) == 0)
		sa(data);
	else if (ft_strcmp("sb\n", action) == 0)
		sb(data);
	else if (ft_strcmp("ss\n", action) == 0)
		ss(data);
}

static void	handle_rotate(char *action, t_data *data)
{
	if (ft_strcmp("ra\n", action) == 0)
		ra(data);
	else if (ft_strcmp("rb\n", action) == 0)
		rb(data);
	else if (ft_strcmp("rr\n", action) == 0)
		rr(data);
}

static void	handle_reverse_rotate(char *action, t_data *data)
{
	if (ft_strcmp("rra\n", action) == 0)
		rra(data);
	else if (ft_strcmp("rrb\n", action) == 0)
		rrb(data);
	else if (ft_strcmp("rrr\n", action) == 0)
		rrr(data);
}

static void	handle_push(char *action, t_data *data)
{
	if (ft_strcmp("pa\n", action) == 0)
		pa(data);
	else if (ft_strcmp("pb\n", action) == 0)
		pb(data);
}

void	read_stdin(t_data *data)
{
	data->action = get_next_line(0);
	while (data->action)
	{
		if (ft_strcmp("sa\n", data->action) == 0
			|| ft_strcmp("sb\n", data->action) == 0
			|| ft_strcmp("ss\n", data->action) == 0)
			handle_swap(data->action, data);
		else if (ft_strcmp("ra\n", data->action) == 0
			|| ft_strcmp("rb\n", data->action) == 0
			|| ft_strcmp("rr\n", data->action) == 0)
			handle_rotate(data->action, data);
		else if (ft_strcmp("rra\n", data->action) == 0
			|| ft_strcmp("rrb\n", data->action) == 0
			|| ft_strcmp("rrr\n", data->action) == 0)
			handle_reverse_rotate(data->action, data);
		else if (ft_strcmp("pa\n", data->action) == 0
			|| ft_strcmp("pb\n", data->action) == 0)
			handle_push(data->action, data);
		else
			handle_error(NULL, data);
		free(data->action);
		data->action = get_next_line(0);
	}
}
