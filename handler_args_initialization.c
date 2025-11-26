/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_args_initialization.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:12:48 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/26 11:07:56 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_ranks(t_stack *stack)
{
	t_elem	*ref;
	t_elem	*cmp;
	int		rank;

	rank = 0;
	ref = stack->top;
	while (ref != NULL)
	{
		cmp = stack->top;
		while (cmp != NULL)
		{
			if (cmp != ref && cmp->value < ref->value)
				rank++;
			cmp = cmp->down;
		}
		ref->rank = rank;
		rank = 0;
		ref = ref->down;
	}
	return (stack);
}

static int	are_values_uniques(t_stack *stack)
{
	t_elem	*ref;
	t_elem	*cmp;

	ref = stack->top;
	while (ref != NULL)
	{
		cmp = ref->up;
		while (cmp != NULL)
		{
			if (cmp != ref && cmp->value == ref->value)
				return (0);
			cmp = cmp->down;
		}
		ref = ref->down;
	}
	return (1);
}

static int	are_all_strvalues_valid(char **str_values)
{
	size_t	i;

	i = 0;
	while (str_values[i] != NULL)
	{
		if (!ft_isnb(str_values[i]))
			return (0);
		i++;
	}
	return (1);
}

t_stack	*handle_args_to_stack_initialization\
(char *stack_name, size_t argc, char **argv)
{
	size_t	argv_i;
	char	**strvalues;
	t_stack	*stack;

	argv_i = 1;
	stack = t_stack__new(stack_name, NULL, NULL);
	while (argv_i < argc)
	{
		strvalues = ft_split(argv[argv_i], ' ');
		if (!are_all_strvalues_valid(strvalues))
			return (t_stack__free_all(stack), NULL);
		stack = t_stack__addtail(stack, ft_strtoelems(strvalues));
		if (!are_values_uniques(stack))
			return (t_stack__free_all(stack), NULL);
		argv_i++;
	}
	return (init_ranks(stack));
}
