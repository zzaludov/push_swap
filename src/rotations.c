/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:44:29 by zzaludov          #+#    #+#             */
/*   Updated: 2023/09/23 03:44:32 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_1(t_world *w, t_steps s)
{
	int	i;

	i = 0;
	while (i < s.a && i < s.b)
	{
		com(w, "rr");
		i++;
	}
	while (i < s.a)
	{
		com(w, "ra");
		i++;
	}
	while (i < s.b)
	{
		com(w, "rb");
		i++;
	}
}

void	rotate_2(t_world *w, t_steps s)
{
	int	i;

	i = 0;
	while (i < lstsize(w->a) - s.a && i < lstsize(w->b) - s.b)
	{
		com(w, "rrr");
		i++;
	}
	while (i < lstsize(w->a) - s.a)
	{
		com(w, "rra");
		i++;
	}
	while (i < lstsize(w->b) - s.b)
	{
		com(w, "rrb");
		i++;
	}
}

void	rotate_3(t_world *w, t_steps s)
{
	int	i;

	i = 0;
	while (i < s.a)
	{
		com(w, "ra");
		i++;
	}
	i = 0;
	while (i < lstsize(w->b) - s.b)
	{
		com(w, "rrb");
		i++;
	}
}

void	rotate_4(t_world *w, t_steps s)
{
	int	i;

	i = 0;
	while (i < lstsize(w->a) - s.a)
	{
		com(w, "rra");
		i++;
	}
	i = 0;
	while (i < s.b)
	{
		com(w, "rb");
		i++;
	}
}

void	sort_by_rotate(t_world *w, t_steps s)
{
	if (w->min.rot_case == 1)
		rotate_1(w, s);
	else if (w->min.rot_case == 2)
		rotate_2(w, s);
	else if (w->min.rot_case == 3)
		rotate_3(w, s);
	else if (w->min.rot_case == 4)
		rotate_4(w, s);
}
