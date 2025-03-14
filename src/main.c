#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

#define VALUE 0
#define RANK 1
typedef struct s_stack
{
	int    *stack[2];
	int		size;
}
t_stack;

typedef struct s_data
{
	t_stack stack_a;
	t_stack stack_b;
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

int main(int ac, char **av)
{
	if (ac == 1)
		return FAILIURE;
	int i = 1;
	int j;
	char **tokens;
	t_data	*data;
	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return FAILIURE;
	while (i < ac)
	{
		j = 0;
		tokens = ft_tokenize(av[i]);
		while (tokens[j])
		{
			printf("str is empty:\"%s\"	%d\n", tokens[j], ft_strisempty(tokens[j]));
			if (ft_strisempty(tokens[j]))
			{
				return FAILIURE;
			}
			if (!ft_strisdecimal(tokens[j]))
			{
				return FAILIURE;
			}
			printf("token	%s\n", tokens[j]);
			j++;
		}
		i++;
		ft_free_vector(tokens);
	}

}

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
