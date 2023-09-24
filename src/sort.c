/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:59:18 by zzaludov          #+#    #+#             */
/*   Updated: 2023/09/23 03:59:21 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	till_three(t_world *w)
{
	int	x;
	int	y;
	int	z;

	x = w->a->i;
	y = w->a->next->i;
	z = w->a->next->next->i;
	if (x > y && y < z && x < z)
		com(w, "sa");
	else if (x > y && y > z && x > z)
	{
		com(w, "sa");
		com(w, "rra");
	}
	else if (x < y && y > z && x < z)
	{
		com(w, "sa");
		com(w, "ra");
	}
	else if (x > y && y < z && x > z)
		com(w, "ra");
	else if (x < y && y > z && x > z)
		com(w, "rra");
}

void	till_five(t_world *w)
{
	while (lstsize(w->a) > 3)
		com(w, "pb");
	till_three(w);
	if (w->size == 5)
	{
		if (w->b->i == 3 && w->b->next->i == 2)
			com(w, "rr");
		else if (w->b->i == 3 && w->b->next->i == 4)
			com(w, "rrr");
		else if (w->b->i == 3)
			com(w, "sb");
	}
	while (w->b != NULL)
	{
		if (w->b->i == w->a->i - 1 || (w->b->i == lstlast(w->a)->i + 1))
			com(w, "pa");
		else if (w->b->i == w->a->next->i - 1)
			com(w, "ra");
		else
			com(w, "rra");
	}
}

int	find_min(t_stack *a)
{
	int		steps;
	t_stack	*temp;

	steps = 0;
	temp = a;
	while (temp->i != lstmin(temp))
	{
		temp = temp->next;
		steps++;
	}
	return (steps);
}

void	sort(t_world *w)
{
	int	min;

	if (w->size == 2 && w->a->i > w->a->next->i)
		com(w, "sa");
	else if (w->size <= 3)
		till_three(w);
	else if (w->size <= 5)
		till_five(w);
	else
	{
		push_to_b(w);
		till_three(w);
		push_to_a(w);
	}
	min = find_min(w->a);
	if (min <= lstsize(w->a) / 2)
	{
		while (w->a->i != lstmin(w->a))
			com(w, "ra");
	}
	else
	{
		while (w->a->i != lstmin(w->a))
			com(w, "rra");
	}
}
