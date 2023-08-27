/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:52:56 by zzaludov          #+#    #+#             */
/*   Updated: 2023/08/20 21:53:00 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_com(t_world *w, char *c)
{
	int	flag;

	flag = 0;
	if (compare(c, "rra", ft_strlen(c)) == 0)
		rev_rotate(&w->a);
	else if (compare(c, "rrb", ft_strlen(c)) == 0)
		rev_rotate(&w->b);
	else if (compare(c, "rrr", ft_strlen(c)) == 0)
	{
		rev_rotate(&w->a);
		rev_rotate(&w->b);
	}
	else if (compare(c, "ra", ft_strlen(c)) == 0)
		rotate(&w->a);
	else if (compare(c, "rb", ft_strlen(c)) == 0)
		rotate(&w->b);
	else if (compare(c, "rr", ft_strlen(c)) == 0) // does not work
	{
		rotate(&w->a);
		rotate(&w->b);
	}
	else
		flag = 1;
	return (flag);
}

void	com(t_world *w, char *c)
{
	int	flag;

	flag = 0;
	if (compare(c, "sa", ft_strlen(c)) == 0)
		swap(&w->a);
	else if (compare(c, "sb", ft_strlen(c)) == 0)
		swap(&w->b);
	else if (compare(c, "ss", ft_strlen(c)) == 0)
	{
		swap(&w->a);
		swap(&w->b);
	}
	else if (compare(c, "pa", ft_strlen(c)) == 0)
		push (&w->a, &w->b);
	else if (compare(c, "pb", ft_strlen(c)) == 0)
		push (&w->b, &w->a);
	else
		flag = rotate_com(w, c);
	if (flag == 0)
	{
		w->flag = 1;
		ft_printf("%s\n", c);
	}
	if (c[0] != 's' && flag == 0)
		swapping(w);
/*	if (c[0] != 'p' && flag == 0)
		pushing(w);*/
}
