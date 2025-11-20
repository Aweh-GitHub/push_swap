/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:59:19 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/20 17:03:53 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_x(t_stack *dst, t_stack *src)
{
	t_elem	*head_transfer;

	head_transfer = src->top;
	if (src->top == NULL)
		return ;
	t_stack__addhead(dst, head_transfer);
	t_stack__remove(src, head_transfer);
}