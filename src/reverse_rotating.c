/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotating.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:03:16 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/19 10:15:44 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	ft_lstreverse_rotate(data->stack_a);
}

void	rrb(t_data *data)
{
	ft_lstreverse_rotate(data->stack_b);
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
