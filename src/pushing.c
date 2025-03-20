/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:01:44 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/20 08:08:19 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	ft_lstpush(data->stack_b, data->stack_a);
	ft_printf("pa\n");
}

void	pb(t_data *data)
{
	ft_lstpush(data->stack_a, data->stack_b);
	ft_printf("pb\n");
}
