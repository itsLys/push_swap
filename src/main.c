#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// #define VALUE 0
// #define INDEX 1
// typedef struct s_stack
// {
// 	int	*values;
// 	int size;
// }
// t_frame;

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

void	push(t_list **stack, int value, t_data *data)
{
	int *val_p;
	t_list *node;

	val_p = malloc(sizeof(int));
	if (val_p == NULL)
		return ;
	*val_p = value;

	node = ft_lstnew(val_p);
	if (node == NULL)
		exit_program(FAILIURE, EMPTY, data);
	ft_lstadd_back(stack, node);
}

void parse_args(int ac, char **av, t_data *data)
{
	int	i;
	int	j;
	char **tokens;

	i = 1;
	while (i < ac)
	{
		j = 0;
		tokens = ft_split(av[i], ' ');
		if (tokens == NULL || tokens[j] == NULL)
			handle_error((void *[]){tokens, NULL}, data);
		while (tokens[j])
		{
			if (ft_strisdecimal(tokens[j]) == FALSE)
				handle_error((void *[]) {tokens[j], tokens, NULL}, data);
			push(data->stack_a, ft_atoi(tokens[j]), data);
			free(tokens[j++]);
		}
		i++;
		free(tokens);
	}
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
	parse_args(ac, av, data);
	t_list *member = *(data->stack_a);
	while (member)
	{
		printf("%d, ", *((int *) member->content));
		member = member->next;
	}
	printf("\n");
	exit_program(SUCCESS, EMPTY, data);

}
// NOTE:
// store in a temporary array, when the array is full,
// 	allocate and reallocate and store from beggining

//  1 4 3 5
//  "5 4 3 2 1"
//
//    13 15 32 "9 2 0" "4" 2 6 3"4" -1 " "
//
//    1 3 5 7 "45 54"
//
//    1 3 5 7 "45 54"
//
//
//    stack_a: [x, 4, 6, 57, 99 ];    size_a = 4
//    stack_b: [1];                    size_b
//    push_a
