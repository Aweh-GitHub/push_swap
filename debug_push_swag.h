/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_push_swag.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:46:33 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/20 10:57:42 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	t_stack__print(t_stack *stack)
{
	t_elem	*elem;

	if (stack == NULL)
		return ;
	printf("$$$ STACK - %p\n\n", stack);
	printf("head: %p\n", stack->top);
	printf("tail: %p\n", stack->bot);
	printf("\n\n");
	elem = stack->top;
	while (elem != NULL)
	{
		printf("### ELEM - %p\n", elem);
		printf("(\?\?) value: %d\n", elem->value);
		printf("(^^) UP: %p\n", elem->up);
		printf("(vv) DOWN: %p\n", elem->down);
		printf("###");
		printf("\n\n");
		elem = elem->down;
	}
}