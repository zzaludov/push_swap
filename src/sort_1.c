/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:08:26 by zzaludov          #+#    #+#             */
/*   Updated: 2023/08/21 20:08:28 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	till_three(t_world *w)
{
	int	x;
	int	y;
	int	z;

	x = w->a->n;
	y = w->a->next->n;
	z = w->a->next->next->n;
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

void	till_four(t_world *w)
{
//	till_three(w);
	if (w->b->n > w->a->n && w->b->n < w->a->next->n)
		com(w, "ra");
	else if (w->b->n > w->a->next->n && w->b->n < w->a->next->next->n)
		com(w, "rra");
	com(w, "pa");
/*	if (w->a->n < w->min_a)
		w->min_a = w->a->n;
	if (w->a->n > w->max_a)
		w->max_a = w->a->n;*/
	while (w->a->n > lstlast(w->a)->n)
			com(w, "rra");
	w->min_a = w->a->n;
	w->max_a = lstlast(w->a)->n;
}

void	sort_tree(t_world *w)
{
	if (w->size <= 3)
		till_three(w);
	else if (w->size == 4)
	{
		com(w, "pb");
		till_three(w);
		till_four(w);
/*		while (w->a->n > lstlast(w->a)->n)
			com(w, "rra");*/
	}
	else
		start(w);
	{
//		turkish_algorithm(w);
/*		while (w->b->next != NULL)
		{
			com(w, "pa");
			till_three(w);
		}*/
		till_four(w);
/*		while (w->b->next != NULL)
		{
			if (w->b->n < w->a->n && w->b->n > lstlast(w->a)->n)
				com(w, "pa");
			else if (w->b->n < w->min_a && w->min_a == w->a->n)
			{
				com(w, "pa");
				w->min_a = w->a->n;
			}
			else if (w->b->n > w->max_a && w->max_a == w->a->n)
			{
				com(w, "pa");
				w->max_a = w->a->n;
				printf("%d ", w->max_a);
			}
			else
				com(w, "rrr");
//				rotating(w); //pridat NULL
//			till_four(w);
		}*/
		while (w->b != NULL)
//		while ((w->a->n != w->min || lstlast(w->a)->n != w->max) || w->b != NULL)
		{
			if (w->b != NULL && w->b->n < w->a->n && w->b->n > lstlast(w->a)->n)
			{;
				com(w, "pa");
				printf("size: %i\n", lstsize(w->b));
			}
//			swapping(w);
			if (w->b != NULL && w->b->next != NULL)
				com(w, "rrr");
/*			else
				com(w, "rra");*/
		}
	}
}
