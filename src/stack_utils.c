#include "push_swap.h"

void clear_stack(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !*stack)
		return ;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

t_stack *stack_last(t_stack *node)
{
	if (node)
		while (node->next)
			node = node->next;
	return node;
}

void	stack_add_front(t_stack **lst, t_stack *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		new->next = NULL;
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack *last;

	if (!new || !stack)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = stack_last(*stack);
	last->next = new;
}

int	stack_size(t_stack *node)
{
	int	count;

	count = 0;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}
