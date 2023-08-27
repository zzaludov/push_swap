/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:14:34 by zzaludov          #+#    #+#             */
/*   Updated: 2023/08/17 18:14:37 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <math.h>
# include "../FT_LIBRARY/ft_library.h"

typedef struct s_stack
{
	int				n;
	int				h;
	int				t;
	int				f;
	struct s_stack	*next;
}	t_stack;

typedef struct s_world
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	int		max;
	int		min;
	int		max_a;
	int		min_a;
	int		flag;
//	int		flag_2;
}	t_world;

// list functions
t_stack	*lstnew(int n);
t_stack	*lstlast(t_stack *lst);
void	lstadd_back(t_stack **lst, t_stack *new);
int	lstsize(t_stack *lst);
void	lstclear(t_stack **lst, void (*del)(void *));
// commands
void	com(t_world *w, char *c);
void	swapping(t_world *w);
void	pushing(t_world *w);
void	rotating(t_world *w);
// operations
void	push(t_stack **a, t_stack **b);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);
//sort_1
void	sort_tree(t_world *w);
void	till_four(t_world *w);
void	till_three(t_world *w);
void	turkish_algorithm(t_world *w);

void	start(t_world *w);
// utils
int	compare(const char *s1, const char *s2, size_t n);
void	exit_error();

#endif
