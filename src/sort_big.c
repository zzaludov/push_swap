/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:51:41 by zzaludov          #+#    #+#             */
/*   Updated: 2023/09/23 03:51:44 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	scan_stack(int max, t_stack *a)
{
	if (a == NULL || a->next == NULL)
		return (-1);
	while (a != NULL)
	{
		if (a->i < max)
		{
			return (0);
		}
		a = a->next;
	}
	return (-1);
}

void	first_half(t_world *w)
{
	while (scan_stack(w->size / 2, w->a) == 0)
	{
		if (w->a->i < w->size / 2 && w->a->i >= w->size / 4)
			com(w, "pb");
		else if (w->a->i < w->size / 4)
		{
			com(w, "pb");
			com(w, "rb");
		}
		else
			com(w, "ra");
	}
}

void	push_to_b(t_world *w)
{
	int	i;
	int	chunk;
	int	ch_1;

	i = 1;
	chunk = w->size / 11;
	ch_1 = w->size / 2 + (chunk * 2);
	first_half(w);
	while (ch_1 <= w->size && lstsize(w->a) > 3)
	{
		if (w->a->i <= ch_1)
			com(w, "pb");
		else
			com(w, "ra");
		if (scan_stack(ch_1, w->a) != 0 && w->size >= 12)
			ch_1 += (chunk * 2);
		if (scan_stack(ch_1, w->a) != 0 && w->size < 12)
			ch_1 += 2;
	}
	while (ch_1 > w->size && lstsize(w->a) > 3)
		com(w, "pb");
}

void	push_to_a(t_world *w)
{
	int	i;

	i = 3;
	while (lstsize(w->b) >= w->size / 2)
	{
		count_step(w, (w->size / 4) * i);
		sort_by_rotate(w, w->min);
		com(w, "pa");
		if ((w->size / 4) * i <= lstsize(w->b))
			i--;
	}
	while (w->b != NULL)
	{
		count_step(w, 0);
		sort_by_rotate(w, w->min);
		com(w, "pa");
	}
}
