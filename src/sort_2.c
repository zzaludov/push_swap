/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:31:01 by zzaludov          #+#    #+#             */
/*   Updated: 2023/08/25 18:31:04 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_world *w)
{
	while (w->a->n < w->b->n && w->a->n != w->min)
		com(w, "rrb");
	com(w, "pb");
	if (w->a->n == w->min)
		com(w, "rb");
}

void	rev_rotate_a(t_world *w)
{
	if (lstlast(w->a)->n > w->b->n)
	{
		com(w, "rra");
		com(w, "pb");
	}
	else if (w->b->next->next != NULL && lstlast(w->a)->n < w->b->n 
		&& lstlast(w->a)->n > w->b->next->n
		&& lstlast(w->a)->n > w->b->next->next->n)
	{
		com(w, "rra");
		com(w, "pb");
		com(w, "sb");
	}
	else if (lstlast(w->a)->n < w->b->n
		&& lstlast(w->a)->n < lstlast(w->b)->n)
	{
		com(w, "rra");
		com(w, "pb");
		com(w, "rb");
	}
	else
		rotate_b(w);
}

void	rotate_a(t_world *w)
{
	if (w->a->next->n > w->b->n)
	{
		com(w, "ra");
		com(w, "pb");
	}
	else if (w->b->next->next != NULL && w->a->next->n < w->b->n
		&& w->a->next->n > w->b->next->n
		&& w->a->next->n > w->b->next->next->n)
	{
		com(w, "ra");
		com(w, "pb");
		com(w, "sb");
	}
	else if (w->a->next->n < w->b->n
		&& w->a->next->n < lstlast(w->b)->n)
	{
		com(w, "ra");
		com(w, "pb");
		com(w, "rb");
	}
	else
		rev_rotate_a(w);
}

void	turkish_algorithm(t_world *w)
{
	com(w, "pb");
	com(w, "pb");
	if (w->b->n < w->b->next->n)
		com(w, "sb");
	while (w->a->next->next->next != NULL)
	{
		if (w->b->next->next != NULL && w->a->n < w->b->n
			&& w->a->n > w->b->next->n && w->a->n > w->b->next->next->n) 
		{
			com(w, "pb");
			com(w, "sb");
		}
		else if (w->a->n < w->b->n && w->a->n < lstlast(w->b)->n)
		{
			com(w, "pb");
			com(w, "rb");
		}
		else if (w->a->n > w->b->n)
			com(w, "pb");
		else
			rotate_a(w);
	}
}
