/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 04:08:34 by zzaludov          #+#    #+#             */
/*   Updated: 2023/09/23 04:08:42 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_stack *a)
{
	t_stack	*temp;

	temp = a;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->i > temp->next->i)
			return (0);
		temp = temp->next;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	struct s_world	w;
	char			**argm;
	int				i;

	w.b = NULL;
	if (argc == 2)
	{
		i = 0;
		argm = ft_split(argv[1], ' ');
		while (argm[i])
			i++;
		w.a = a_init(&w, i, argm, 0);
		free_memory((void **)argm);
	}
	else
		w.a = a_init(&w, argc - 1, argv, 1);
	if (argc > 1)
	{
		if (check_if_sorted(w.a) == 0)
			sort(&w);
		lstclear(&w.a);
		if (check_if_sorted(w.a) == 0)
			lstclear(&w.b);
	}
	return (0);
}
