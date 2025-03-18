#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INT_MAX (long) 0x7fffffff
#define INT_MIN -INT_MAX - 1

typedef struct s_data
{
	t_list **stack_a;
	t_list **stack_b;
	int     *sroted;
}        t_data;

int ft_strisempty(char *str)
{
	while (*str && *str == ' ')
		str++;
	return (!*str);

}

int ft_strisdecimal(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	return !(*str);
}

void	exit_program(int status, void **list, t_data *data)
{
	while (*list)
		free(*(list++));
	ft_lstclear(data->stack_a, free);
	ft_lstclear(data->stack_b, free);
	free(data->stack_a);
	free(data->stack_b);
	free(data);
	exit(status);
}

#define EMPTY (void *[]) {NULL}
void	handle_error(void **list, t_data *data)
{
	write(STDERR, "Error\n", 6);
	exit_program(FAILIURE, list, data);
}

void	push(t_list **stack, long value, t_data *data)
{
	long *val_p;
	t_list *node;

	val_p = malloc(sizeof(long));
	if (val_p == NULL)
		return ;
	*val_p = value;

	node = ft_lstnew(val_p);
	if (node == NULL)
		exit_program(FAILIURE, EMPTY, data);
	ft_lstadd_back(stack, node);
}

void	init_stack(char **vec, t_data *data)
{
	while (*vec)
	{
		if (ft_strisdecimal(*vec) == FALSE)
			handle_error((void *[]) {*vec, vec, NULL}, data);
		push(data->stack_a, ft_atol(*vec), data);
		free(*(vec++));
	}
}

int check_repitition(t_list **list)
{
	long	curr;
	t_list	*node;

	node = *list;
	while (node)
	{
		curr = *((long *)node->content);
		node = node->next;
		while (node)
		{
			if (curr == *((long *)node->content))
				return ERROR;
			node = node->next;
		}
	}
	return SUCCESS;
}

int check_values(t_list **list)
{
	long	value;
	t_list	*node;

	node = *list;
	while (node)
	{
		value = *((long *)node->content);
		if (value > INT_MAX || value < INT_MIN)
			return ERROR;
		node = node->next;
	}
	return SUCCESS;
}

void	parse_input(int ac, char **av, t_data *data)
{
	int	i;
	char **tokens;

	i = 1;
	while (i < ac)
	{
		tokens = ft_split(av[i], ' ');
		if (tokens == NULL || tokens[0] == NULL)
			handle_error((void *[]){tokens, NULL}, data);
		init_stack(tokens, data);
		i++;
		free(tokens);
	}
	if (check_repitition(data->stack_a) == ERROR )
		handle_error(EMPTY, data);
	if (check_values(data->stack_a) == ERROR)
		handle_error(EMPTY, data);
}

int main(int ac, char **av)
{
	t_data	*data;

	if (ac == 1)
		return FAILIURE;
	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return FAILIURE;
	data->stack_a = ft_calloc(1, sizeof(t_list *));
	data->stack_b = ft_calloc(1, sizeof(t_list *));
	if (data->stack_a == NULL || data->stack_b == NULL)
		exit_program(FAILIURE, EMPTY, data);
	parse_input(ac, av, data);
	t_list *member = *(data->stack_a);
	while (member)
	{
		printf("%ld, ", *((long *) member->content));
		member = member->next;
	}
	printf("\n");
	exit_program(SUCCESS, EMPTY, data);

}
