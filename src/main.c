/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:10:34 by zzaludov          #+#    #+#             */
/*   Updated: 2023/08/17 18:10:37 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_index (t_world w)
{
	while (w.a != NULL) 
	{
		w.a->h = (int)((float)((float)(w.a->n - w.min) / (w.max - w.min)) /(float) 0.5);
		w.a->t = (int)((float)((float)(w.a->n - w.min) / (w.max - w.min)) /(float) 0.33);
		w.a->f = (int)((float)((float)(w.a->n - w.min) / (w.max - w.min)) /(float)0.2);
		w.a = w.a->next;
	}
}

void	check_input(int i, char **argv)
{
	int	j;

	j = 0;
	while (argv[i][j])
	{
		if (argv[i][j] < '0' || argv[i][j] > '9')
			exit_error();
		j++;
	}
	j = 0;
	while (j < i)
	{
		if (ft_strlen(argv[j]) == ft_strlen(argv[i])
			&& ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
			exit_error();
		j++;
	}
	//int min and max	
}

t_stack	*a_init(t_world	*w, int size, char **argv, int add)
{
	t_stack	*a;
	t_stack	*new;
	int		i;

	i = 0;
	a = NULL;
	w->min = 2147483647;
	w->max = -2147483648;
	w->size = size;
	while (i < size)
	{
		check_input(i + add, argv);
		new = lstnew(ft_atoi(argv[i + add])); //int min and max
		if (!new)
			exit_error();
		if (new->n > w->max)
			w->max = new->n;
		if (new->n < w->min)
			w->min = new->n;
		lstadd_back(&a, new);
		i++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	struct s_world	w;
	char			**argm;
	int				i;

	w.b = NULL;
	if (argc == 2) // check argc == 1
	{
		i = 0;
		argm = ft_split(argv[1], ' ');
		while (argm[i])
			i++;
		w.a = a_init(&w, i, argm, 0);
		// free argm
	}
	else
		w.a = a_init(&w, argc - 1, argv, 1);
	a_index (w);
	sort_tree(&w);
	printf ("\na: ");
	while (w.a != NULL) 
	{
		printf("%d ", w.a->n);
//		printf("%d ", w.a->h);
		w.a = w.a->next;
	}
	printf ("\nb: ");
	while (w.b != NULL) 
	{
		printf("%d ", w.b->n);
		w.b = w.b->next;
	}
	lstclear(&w.a, free);
	lstclear(&w.b, free);
	return (0);
}
