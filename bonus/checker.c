/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:22:00 by zzaludov          #+#    #+#             */
/*   Updated: 2023/09/23 12:22:07 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	sort_check(t_world *w)
{
	if (check_if_sorted(w->a) == 0 || lstsize(w->b) != 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

void	sort_by_ps(t_world *w, char *comnd)
{
	char	*c;
	int		i;

	c = (char *) malloc (sizeof(char *) * ft_strlen(comnd));
	i = ft_strlcpy(c, comnd, ft_strlen(comnd));
	com(w, c);
	if (w->flag == 1)
	{
		free(c);
		free(comnd);
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	free(c);
}

void	read_input(t_world *w)
{
	char	*comnd;

	comnd = get_next_line(0);
	if (comnd)
	{
		while (comnd)
		{
			sort_by_ps(w, comnd);
			free(comnd);
			comnd = get_next_line(0);
		}
	}
	free(comnd);
	sort_check(w);
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
		read_input(&w);
		lstclear(&w.a);
		if (check_if_sorted(w.a) == 0)
			lstclear(&w.b);
	}
	return (0);
}
