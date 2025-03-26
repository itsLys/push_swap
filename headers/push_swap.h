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
# define INT_MAX 2147483647L
# define INT_MIN -2147483648L

typedef struct s_stack
{
	long	value;
	int		index;
	struct s_stack *next;
	// struct s_stack_item previous;
}			t_stack;

typedef struct s_data
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	int		min;
	int		max;
	int		delim;
	int		size;
	int		*sorted;
	int		chunks;
	int		chunk_size;
	int		middle;
}			t_data;
void		parse_input(int ac, char **av, t_data *data);
void		exit_program(int status, void **list, t_data *data);
void		handle_error(void **list, t_data *data);

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

int			stack_size(t_stack *node);
void		stack_add_back(t_stack **stack, t_stack *new);
void		stack_add_front(t_stack **lst, t_stack *new);
t_stack		*stack_last(t_stack *node);
void 		clear_stack(t_stack **stack);

void	set_index(t_data *data);
#endif // !PUSH_SWAP_H
