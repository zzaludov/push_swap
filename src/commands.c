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

int	compare(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	while ((!s1 && !s2) || i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i] || s1[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	rotate_com(t_world *w, char *c)
{
	w->flag = 0;
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
	else if (compare(c, "rr", ft_strlen(c)) == 0)
	{
		rotate(&w->a);
		rotate(&w->b);
	}
	else
		w->flag = 1;
}

void	com(t_world *w, char *c)
{
	w->flag = 0;
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
		rotate_com(w, c);
	if (w->flag == 0 && w->checker == 0)
		ft_printf("%s\n", c);
}
