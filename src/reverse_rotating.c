/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotating.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:03:16 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/20 08:07:52 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

void	rra(t_data *data)
{
	ft_lstreverse_rotate(data->stack_a);
	ft_printf("rra\n");
}

void	rrb(t_data *data)
{
	ft_lstreverse_rotate(data->stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
