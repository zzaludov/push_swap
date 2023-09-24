/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:36:20 by zzaludov          #+#    #+#             */
/*   Updated: 2023/08/25 21:36:23 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	free_memory(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}

long	long_atoi(const char *nptr)
{
	long	i;
	long	minus;
	long	result;

	i = 0;
	minus = 0;
	result = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			minus++;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		result = (nptr[i] - '0') + (result * 10);
		i++;
	}
	if (minus == 1)
		result = -result;
	return (result);
}

t_steps	count_smallest_2(t_world *w, int a, int b, t_steps current)
{
	if (a <= lstsize(w->a) / 2 && b > lstsize(w->b) / 2)
	{
		current.smallest = a + (lstsize(w->b) - b);
		current.rot_case = 3;
	}
	else if (a > lstsize(w->a) / 2 && b <= lstsize(w->b) / 2)
	{
		current.smallest = b + (lstsize(w->a) - a);
		current.rot_case = 4;
	}
	return (current);
}

t_steps	count_smallest(t_world *w, int a, int b, t_steps current)
{
	if (a <= lstsize(w->a) / 2 && b <= lstsize(w->b) / 2)
	{
		if (a >= b)
			current.smallest = a;
		else
			current.smallest = b;
		current.rot_case = 1;
	}
	else if (a > lstsize(w->a) / 2 && b > lstsize(w->b) / 2)
	{
		if ((lstsize(w->a) - a) >= (lstsize(w->b) - b))
			current.smallest = (lstsize(w->a) - a);
		else
			current.smallest = (lstsize(w->b) - b);
		current.rot_case = 2;
	}
	else
		current = count_smallest_2(w, a, b, current);
	return (current);
}
