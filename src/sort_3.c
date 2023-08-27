/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:17:47 by zzaludov          #+#    #+#             */
/*   Updated: 2023/08/25 21:17:51 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start(t_world *w)
{
	com(w, "pb");
	com(w, "pb");
	while (lstsize(w->b) < w->size - 3)
//	while (w->b != NULL)
	{
		w->flag = 0;
//		printf("size: %i\n", lstsize(w->b));
		pushing(w);
		rotating(w);
//		pushing(w);
		if (w->flag == 0)
		{
			com(w, "rr");
//			com(w, "rrb");
		}
	}
}

void	swapping(t_world *w)
{
	if (w->b != NULL && w->a != NULL && w->a->next != NULL && w->b->next != NULL
		&& w->b->n < w->b->next->n && w->a->n < w->a->next->n)
		com(w, "ss");
	else if (w->b != NULL && w->b->next != NULL && w->b->n < w->b->next->n)
		com(w, "sb");
	else if (w->a != NULL && w->a->next != NULL && w->a->n > w->a->next->n)
		com(w, "sa");
}

void	pushing(t_world *w)
{
/*	if (w->flag_2 == 0)
	{*/
		if (w->a->n > w->b->n && w->a->f < 3) // NULL condition
			com(w, "pb");
		else if (w->a->n < w->b->n && w->a->f > 1)
			com(w, "pa");
/*	}
	else
	{
		if (w->a->n > w->b->n)
			com(w, "pb");
		else if (w->a->n < w->b->n)
			com(w, "pa");
	}*/
}

void	rotating(t_world *w) // NULL condition
{
	if (w->a->n > w->b->next->n && w->a->n < w->b->n
		&& w->a->f < 3)
		com(w, "ra");
	else if (w->b->n < w->a->next->n && w->b->n > w->a->n
		&& w->b->f > 1)
		com(w, "rb");
	else if (w->a->n > w->b->next->n && w->a->n < w->b->n
		&& w->a->f < 3
		&& w->b->n < w->a->next->n && w->b->n > w->a->n
		&& w->b->f > 1)
		com(w, "rr");
}
