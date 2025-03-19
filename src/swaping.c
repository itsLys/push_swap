/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:01:03 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/19 10:17:18 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	ft_lstswap(data->stack_a);
}

void	sb(t_data *data)
{
	ft_lstswap(data->stack_b);
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
