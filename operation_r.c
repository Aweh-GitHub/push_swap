/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:59:43 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/26 11:03:11 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_x(t_stack *stack)
{
	t_elem	*old_top;
	t_elem	*old_bot;

	if (!stack->top || !stack->top->down)
		return ;
	ft_putstr("r");
	ft_putstr(stack->name);
	ft_putstr("\n");
	old_top = stack->top;
	old_bot = stack->bot;
	stack->top = old_top->down;
	stack->top->up = NULL;
	old_bot->down = old_top;
	old_top->up = old_bot;
	old_top->down = NULL;
	stack->bot = old_top;
}
