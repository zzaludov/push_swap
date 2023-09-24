/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 04:06:03 by zzaludov          #+#    #+#             */
/*   Updated: 2023/09/23 04:06:06 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_a_2(int value, t_stack *temp_a)
{
	t_stack	*prev;
	int		steps;

	steps = 0;
	prev = lstlast(temp_a);
	while (temp_a != NULL && ((temp_a->i < value && prev->i > value)
			|| (temp_a->i > value && prev->i > value)
			|| (temp_a->i < value && prev->i < value)
			|| prev->i > temp_a->i))
	{
		prev = temp_a;
		temp_a = temp_a->next;
		steps++;
	}
	return (steps);
}

int	count_a(int value, t_stack *a)
{
	t_stack	*temp_a;
	int		steps;

	temp_a = a;
	steps = 0;
	if (temp_a != NULL && (value > lstmax(a) || value < lstmin(a)))
	{
		while (temp_a->i != lstmin(a))
		{
			steps++;
			temp_a = temp_a->next;
		}
	}
	else if (temp_a != NULL)
		steps = count_a_2(value, temp_a);
	return (steps);
}

t_steps	count_min(t_world *w, int b_steps, t_stack *temp_b)
{
	int		a_steps;
	t_steps	current;

	a_steps = 0;
	current.b = b_steps;
	a_steps = count_a(temp_b->i, w->a);
	current.a = a_steps;
	current = count_smallest(w, a_steps, b_steps, current);
	b_steps++;
	return (current);
}

void	count_step(t_world *w, int max)
{
	t_stack	*temp_b;
	t_steps	current;
	int		steps;

	temp_b = w->b;
	steps = 0;
	w->min.smallest = 2147483647;
	while (temp_b != NULL)
	{
		if (temp_b->i >= max)
			current = count_min(w, steps, temp_b);
		if (current.smallest < w->min.smallest)
			w->min = current;
		temp_b = temp_b->next;
		steps++;
	}
}
