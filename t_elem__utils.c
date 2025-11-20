/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_elem__utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:46:57 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/20 10:47:47 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	t_elem_add_last(t_elem *elem, t_elem *to_add)
{
	t_elem *scroll;

	scroll = elem;
	while (scroll->up != NULL)
		scroll = scroll->up;
	scroll->up = to_add;
}

t_elem	*t_elem__new(int value, t_elem *next, t_elem *prev)
{
	t_elem	*elem;

	elem = malloc(sizeof(t_elem));
	elem->value = value;
	elem->up = next;
	elem->down = prev;
	return (elem);
}

t_elem	*t_elem__unlink(t_elem *elem)
{
	elem->down->up = elem->up;
	elem->up->down = elem->down;
	return (elem);
}