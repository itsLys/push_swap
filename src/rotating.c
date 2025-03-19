/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:02:35 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/19 10:15:44 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	ft_lstrotate(data->stack_a);
}

void	rb(t_data *data)
{
	ft_lstrotate(data->stack_b);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
