/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:11:34 by ihajji            #+#    #+#             */
/*   Updated: 2025/04/02 17:30:56 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define CUSTOM_INT_MAX 2147483647L
# define CUSTOM_INT_MIN -2147483648L

typedef struct s_stack
{
	long			value;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	t_stack			**stack_a;
	t_stack			**stack_b;
	int				min;
	int				max;
	int				size;
	int				*sorted;
	int				chunk_size;
	char			*action;
}					t_data;

// void	print_stack(t_stack **stack, char c);
//test

// main
void				parse_input(int ac, char **av, t_data *data);
void				exit_program(int status, void **list, t_data *data);
void				handle_error(void **list, t_data *data);
void				set_data(t_data *data);

// stack actions
void				stack_push(char stack_type, t_data *data);
void				stack_rotate(char stack_type, t_data *data);
void				stack_reverse_rotate(char stack_type, t_data *data);
void				sa(t_data *data);
void				sb(t_data *data);
void				ss(t_data *data);
void				pa(t_data *data);
void				pb(t_data *data);
void				ra(t_data *data);
void				rb(t_data *data);
void				rr(t_data *data);
void				rra(t_data *data);
void				rrb(t_data *data);
void				rrr(t_data *data);

// stack utils
int					stack_size(t_stack *node);
void				stack_add_back(t_stack **stack, t_stack *new);
void				stack_add_front(t_stack **lst, t_stack *new);
t_stack				*stack_last(t_stack *node);
void				clear_stack(t_stack **stack);

// sorting
void				sort_3(t_data *data);
void				sort_5(t_data *data);
void				sort(t_data *data);

// sort utils
int					get_position(int index, t_stack *stack);
t_stack				*find_highest(t_stack *stack);
t_stack				*find_sec_smallest(t_stack *stack);
t_stack				*find_smallest(t_stack *stack);
int					stack_is_sorted(t_stack *stack);

// push_swap
void				init_sorted(t_data *data);
void				set_index(t_data *data);
void				put_elemnt_index_first(int pos, char stack, t_data *data);
void				merge_back(t_data *data);
void				push_chunk_b(t_data *data);
#endif // !PUSH_SWAP_H
