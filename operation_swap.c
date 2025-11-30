/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:40:04 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/30 17:09:25 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_x(t_stack *stack, int print)
{
	t_elem	*first;
	t_elem	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->down;
	first->down = second->down;
	if (second->down)
		second->down->up = first;
	else
		stack->bot = first;
	second->up = NULL;
	second->down = first;
	first->up = second;
	stack->top = second;
	if (print)
	{
		ft_putstr("s");
		ft_putstr(stack->name);
		ft_putstr("\n");
	}
}

void	swap_swap(t_stack *a, t_stack *b)
{
	swap_x(a, 0);
	swap_x(b, 0);
	ft_putstr("ss\n");
}
