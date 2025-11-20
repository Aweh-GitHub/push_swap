/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:02:43 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/20 10:49:29 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <stddef.h>

typedef	struct s_stack
{
	struct s_elem	*top;
	struct s_elem	*bot;
}	t_stack;

typedef struct s_elem
{
	int				value;
	struct s_elem	*up;
	struct s_elem	*down;
}	t_elem;

char	**ft_split(char const *s, char c);
int		ft_atoi(char const *nptr);
size_t	ft_strlen(const char *s);

int		ft_isnb(char *s);
size_t	ft_splitlen(char const **split);
t_elem	*ft_strtoelems(char **values);

t_stack	*handle_args_to_stack_initialization(size_t argc, char **argv);

t_elem	*t_elem__new(int value, t_elem *next, t_elem *prev);
void	t_elem__add_last(t_elem *elem, t_elem *to_add);
t_elem	*t_elem__unlink(t_elem *elem);
t_elem	*t_elem__last(t_elem *start);

t_stack	*t_stack__new(t_elem *head, t_elem *tail);
t_stack	*t_stack__addtail(t_stack *stack, t_elem *elem);
t_stack	*t_stack__addhead(t_stack *stack, t_elem *elem);
void	t_stack__free_all(t_stack *stack);
size_t	t_stack__get_size(t_stack *stack);
t_elem	*t_stack__remove(t_stack *stack, t_elem *to_remove);

void	t_stack__print(t_stack *stack);

#endif