/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:25:17 by zzaludov          #+#    #+#             */
/*   Updated: 2023/09/23 03:25:20 by zzaludov         ###   ########.fr       */
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
	int				i;
	struct s_stack	*next;
}	t_stack;

typedef struct s_steps
{
	int	a;
	int	b;
	int	rot_case;
	int	smallest;
}	t_steps;

typedef struct s_count
{
	int	a;
	int	rb;
	int	rrb;
}	t_count;

typedef struct s_world
{
	t_stack	*a;
	t_stack	*b;
	t_steps	min;
	int		size;
	int		flag;
	int		checker;
}	t_world;

//init.c
t_stack	*a_init(t_world	*w, int size, char **argv, int add);
int		check_if_sorted(t_stack *a);

//list_functions.c
t_stack	*lstnew(int n, int i);
t_stack	*lstlast(t_stack *lst);
void	lstadd_back(t_stack **lst, t_stack *new);
void	lstclear(t_stack **head);
int		lstsize(t_stack *lst);
int		lstmin(t_stack *lst);
int		lstmax(t_stack *lst);

//commands.c
void	com(t_world *w, char *c);

//operations.c
void	swap(t_stack **stack);
void	push(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);

//sort.c
void	sort(t_world *w);
void	count_step(t_world *w, int max);
t_steps	count_smallest(t_world *w, int a, int b, t_steps current);
void	sort_by_rotate(t_world *w, t_steps s);
void	push_to_a(t_world *w);
void	push_to_b(t_world *w);

//utils.c
void	exit_error(void);
void	free_memory(void **ptr);
long	long_atoi(const char *nptr);

#endif
