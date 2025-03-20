/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:01:03 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/20 08:08:33 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	ft_lstswap(data->stack_a);
	ft_printf("sa\n");
}

void	sb(t_data *data)
{
	ft_lstswap(data->stack_b);
	ft_printf("sb\n");
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
