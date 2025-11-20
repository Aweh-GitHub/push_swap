/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:59:43 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/20 17:04:38 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_x(t_stack *stack)
{
	t_elem	*old_top;
	t_elem	*old_bot;

	old_top = stack->top;
	old_bot = stack->bot;
	if (old_top == old_bot)
		return ;
	stack->bot = stack->top;
	stack->bot->up = old_bot;
	old_bot->down = stack->bot;
	stack->top = old_top->down;
	stack->top->up = NULL;
	stack->bot->down = NULL;
}

void	rr(t_stack *a, t_stack *b)
{
	r(a);
	r(b);
}