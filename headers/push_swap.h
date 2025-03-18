#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#define INT_MAX (long) 0x7fffffff
#define INT_MIN -INT_MAX - 1
#define EMPTY (void *[]) {NULL}

typedef struct s_stack_item
{
	long value;
} t_stack_item ;

typedef struct s_data
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		size;
	int     *sroted;
}        t_data;
void	parse_input(int ac, char **av, t_data *data);
void	exit_program(int status, void **list, t_data *data);
void	push(t_list **stack, long value, t_data *data);
void	handle_error(void **list, t_data *data);
#endif // !PUSH_SWAP_H

