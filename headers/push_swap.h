/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:11:34 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/20 08:16:04 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define INT_MAX 0x7fffffffL
// WARN: FIX
# define INT_MIN -INT_MAX - 1
# define EMPTY  \
	(void *[]) \
	{          \
		NULL   \
	}

typedef struct s_stack_item
{
	long	value;
}			t_stack_item;

typedef struct s_data
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		size;
	int		*sroted;
}			t_data;
void		parse_input(int ac, char **av, t_data *data);
void		exit_program(int status, void **list, t_data *data);
void		handle_error(void **list, t_data *data);
int	get_value(t_list *node);

void		sa(t_data *data);
void		sb(t_data *data);
void		ss(t_data *data);
void		pa(t_data *data);
void		pb(t_data *data);
void		ra(t_data *data);
void		rb(t_data *data);
void		rr(t_data *data);
void		rra(t_data *data);
void		rrb(t_data *data);
void		rrr(t_data *data);

void sort_3(t_data *data);
void	sort(t_data *data);
#endif // !PUSH_SWAP_H
