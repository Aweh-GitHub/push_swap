/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:01:59 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/20 11:00:37 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "debug_push_swag.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = handle_args_to_stack_initialization((size_t) argc, argv);
	if (a == NULL)
		return (1);
	b = t_stack__new(NULL, NULL);
	t_stack__print(a);
	
	return (0);
}