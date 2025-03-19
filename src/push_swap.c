
#include "push_swap.h"
#include "libft.h"
// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// NOTE: WORKING
void	sa(t_data *data)
{
	void	*tmp;
	t_list	*node;
	t_list	*next;

	if (ft_lstsize(*data->stack_a) <= 1)
		return ;
	node = *data->stack_a;
	next = (*data->stack_a)->next;
	tmp = node->content;
	node->content = next->content;
	next->content = tmp;
}
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
// NOTE: WORKING
void	sb(t_data *data)
{
	void	*tmp;
	t_list	*node;
	t_list	*next;

	if (ft_lstsize(*data->stack_b) <= 1)
		return ;
	node = *data->stack_b;
	next = (*data->stack_b)->next;
	tmp = node->content;
	node->content = next->content;
	next->content = tmp;
}
// ss : sa and sb at the same time.
// NOTE: WORKING
void ss(t_data *data)
{
	sa(data);
	sb(data);
}
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// NOTE: WORKING
void pa(t_data *data)
{
	t_list *node;
	t_list *next;

	if (ft_lstsize(*data->stack_b) == 0)
		return ;
	node = *data->stack_b;
	next = (*data->stack_b)->next;
	ft_lstadd_front(data->stack_a, node);
	*data->stack_b = next;
}
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// NOTE: WORKING
void pb(t_data *data)
{
	t_list *node;
	t_list *next;

	if (ft_lstsize(*data->stack_a) == 0)
		return ;
	node = *data->stack_a;
 	next = (*data->stack_a)->next; 
	ft_lstadd_front(data->stack_b, node);
	*data->stack_a = next;
}
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time
