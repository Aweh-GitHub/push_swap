/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:00:13 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/20 17:05:39 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_x(t_stack *stack)
{
	t_elem	*old_top;
	t_elem	*old_bot;

	old_top = stack->top;
	old_bot = stack->bot;
	if (old_top == old_bot)
		return ;
	stack->top = stack->bot;
	stack->top->down = old_top;
	stack->bot = old_bot->up;
	old_top->up = stack->top;
	stack->top->up = NULL;
	stack->bot->down = NULL;
}

void	rrr(t_stack *a, t_stack *b)
{
	rrx(a);
	rrx(b);
}