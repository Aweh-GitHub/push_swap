/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack__utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:37:04 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/20 10:58:04 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack	*t_stack__new(t_elem *head, t_elem *tail)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->top = head;
	stack->bot = tail;
	return (stack);
}
t_stack	*t_stack__addtail(t_stack *stack, t_elem *elem)
{
	t_elem	*last;
	t_elem	*old_tail;

	old_tail = stack->bot;
	if (old_tail != NULL)
		old_tail->down = elem;
	elem->up = old_tail;
	last = elem;
	while (last->down != NULL)
		last = last->down;
	stack->bot = last;
	if (stack->top == NULL)
		stack->top = elem;
	return (stack);
}

t_stack	*t_stack__addhead(t_stack *stack, t_elem *elem)
{
	t_elem	*old_head;
	t_elem	*last;
	t_elem	*to_reindex;
	size_t	index;
	
	old_head = stack->top;
	stack->top = elem;
	if (old_head != NULL)
		old_head->up = elem;
	last = elem;
	while (last->down != NULL)
		last = last->down;
	last->down = old_head;
	return (stack);
}

void	t_stack__free_all(t_stack *stack)
{
	t_elem	*scroll;
	t_elem	*to_free;
	
	scroll = stack->bot;
	while (scroll != NULL)
	{
		to_free = scroll;
		scroll = scroll->down;
		free(to_free);
	}
	free(stack);
}
t_elem	*t_stack__remove(t_stack *stack, t_elem *to_remove)
{
	t_elem	*scroll;
	size_t	i;

	i = 0;
	scroll = stack->top;
	while (scroll != NULL)
	{
		if (scroll == to_remove)
			return (t_elem__unlink(scroll));
		i++;
		scroll = scroll->down;
	}
	return (NULL);
}