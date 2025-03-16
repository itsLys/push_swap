#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

#define VALUE 0
#define INDEX 1
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

void	push(t_list **stack, int value, t_data *data)
{
	int *val_p;

	val_p = malloc(sizeof(int));
	if (val_p == NULL)
		return ;
	*val_p = value;
	ft_lstadd_back(stack, ft_lstnew(val_p));
}

int main(int ac, char **av)
{
	int i = 1;
	int j;
	char **tokens;
	t_data	*data;

	if (ac == 1)
		return FAILIURE;
	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return FAILIURE;
	data->stack_a = ft_calloc(1, sizeof(t_list *));
	data->stack_b = ft_calloc(1, sizeof(t_list *));
	while (i < ac)
	{
		j = 0;
		tokens = ft_tokenize(av[i]);
		if (tokens[j] == NULL)
			return FAILIURE;
		while (tokens[j])
		{
			if (ft_strisempty(tokens[j]))
			{
				return FAILIURE;
			}
			if (!ft_strisdecimal(tokens[j]))
			{
				return FAILIURE;
			}
			push(data->stack_a, ft_atoi(tokens[j]), data);
			j++;
		}
		i++;
		ft_free_vector(tokens);
	}
	t_list *member = *(data->stack_a);
	while (member)
	{
		printf("%d, ", *((int *) member->content));
		member = member->next;
	}
	printf("\n");

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
