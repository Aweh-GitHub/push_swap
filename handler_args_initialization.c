/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_args_initialization.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:12:48 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/20 10:58:09 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (cmp->value == ref->value)
				return (0);
			cmp = cmp->up;
		}
		ref = ref->up;
	}
	return (1);
}

static int	are_all_strvalues_valid(char **str_values)
{
	size_t i;

	i = 0;
	while (str_values[i] != NULL)
	{
		if (!ft_isnb(str_values[i]))
			return (0);
		i++;
	}
	return (1);
}
t_stack	*handle_args_to_stack_initialization(size_t argc, char **argv)
{
	size_t	argv_i;
	char	**strvalues;
	t_stack	*stack;

	argv_i = 1;
	stack = t_stack__new(NULL, NULL);
	while (argv_i < argc)
	{
		strvalues = ft_split(argv[argv_i], ' ');
		if (!are_all_strvalues_valid(strvalues))
			return (t_stack__free_all(stack), NULL);
		if (!are_values_uniques(t_stack__addtail(stack, ft_strtoelems(strvalues))))
			return (t_stack__free_all(stack), NULL);
		argv_i++;
	}
	return (stack);
}