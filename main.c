/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:01:59 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/26 11:00:25 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = handle_args_to_stack_initialization("a", (size_t) argc, argv);
	if (a == NULL)
		return (1);
	b = t_stack__new("b", NULL, NULL);
	handle_sorting(a, b);
	t_stack__free_all(a);
	t_stack__free_all(b);
	return (0);
}
