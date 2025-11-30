/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:45:17 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/30 16:56:32 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_x(t_stack *stack, int print)
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

void	rev_rotate_rotate(t_stack *a, t_stack *b)
{
    rev_rotate_x(a, 0);
    rev_rotate_x(b, 0);
    ft_putstr("rrr\n");
}