/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:45:17 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/30 16:45:51 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_x(t_stack *stack, int print)
{
    t_elem	*last;
    t_elem	*before_last;

    if (!stack || stack->size < 2)
        return ;
    last = stack->bot;
    before_last = last->up;
    before_last->down = NULL;
    stack->bot = before_last;
    last->down = stack->top;
    last->up = NULL;
    stack->top->up = last;
    stack->top = last;
    if (print)
    {
        ft_putstr("rr");
        ft_putstr(stack->name);
        ft_putstr("\n");
    }
}

void	rrr(t_stack *a, t_stack *b)
{
    rr_x_internal(a, 0);
    rr_x_internal(b, 0);
    ft_putstr("rrr\n");
}