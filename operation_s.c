/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:57:44 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/20 17:03:37 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_x(t_stack *stack)
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