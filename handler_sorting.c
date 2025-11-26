/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:45:05 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/26 10:57:33 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "debug_push_swag.h"
#include <stdio.h>

t_elem	*get_last_ascending_elem(t_stack *stack)
{
	t_elem	*scroll;

	scroll = stack->top;
	while (scroll != NULL)
	{
		if (scroll->value > scroll->down->value)
			return (scroll);
		scroll = scroll->down;
	}
	return (NULL);
}

void	handle_sorting(t_stack *a, t_stack *b)
{
	size_t	byte_i;
	size_t	elem_i;
	size_t	max_bits;
	size_t	a_size;

	max_bits = 0;
	while (((a->size - 1) >> max_bits) != 0)
		max_bits++;
	byte_i = 0;
	while (byte_i < max_bits)
	{
		a_size = a->size;
		elem_i = 0;
		while (elem_i < a_size)
		{
			if ((a->top->rank >> byte_i & 1) == 0)
				p_x(b, a);
			else
				r_x(a);
			elem_i++;
		}
		while (b->top)
			p_x(a, b);
		byte_i++;
	}
}
