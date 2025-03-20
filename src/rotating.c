/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:02:35 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/20 08:08:05 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	ft_lstrotate(data->stack_a);
	ft_printf("ra\n");
}

void	rb(t_data *data)
{
	ft_lstrotate(data->stack_b);
	ft_printf("rb\n");
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
