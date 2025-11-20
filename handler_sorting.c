/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:45:05 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/20 10:57:58 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *stack)
{
	t_elem	*first;
	t_elem	*second;
	
	first = stack->top;
	if (first == NULL)
		return ;
	second = first->up;
	if (second == NULL)
		return ;
	first->up = second->up;
	first->down = second->down;
	stack->top = second;
	second->up = first;
	second->down = NULL;
}

void	ss(t_stack *a, t_stack *b)
{
	s(a);
	s(b);
}

void	p(t_stack *dst, t_stack *src)
{
	t_elem	*head_transfer;

	head_transfer = src->top;
	t_stack__addhead(dst, head_transfer);
	t_stack__remove(src, head_transfer);
}

void	r(t_stack *stack)
{
	t_elem	*old_head;

	stack->bot = stack->top;
	stack->top = stack->top->down;
}

void	handle_sorting(t_stack *a, t_stack *b)
{
	
}