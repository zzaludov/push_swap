/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:28:07 by zzaludov          #+#    #+#             */
/*   Updated: 2023/09/23 03:28:12 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(int i, char **argv)
{
	int		j;
	long	c;

	j = 0;
	while (argv[i][j])
	{
		if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
			return (-1);
		j++;
	}
	j = 0;
	while (j < i)
	{
		if (ft_strlen(argv[j]) == ft_strlen(argv[i])
			&& ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
			return (-1);
		j++;
	}
	c = long_atoi(argv[i]);
	if (c > 2147483647 || c < -2147483648)
		return (-1);
	return (0);
}

int	indexing(int number, int *n, int size)
{
	int	i;
	int	less;

	i = 0;
	less = 0;
	while (i < size)
	{
		if (n[i] <= number)
			less++;
		i++;
	}
	return (less);
}

t_stack	*create_lists(t_world *w, t_stack *a, int *numbers)
{
	t_stack	*new;
	int		i;
	int		index;	

	i = 0;
	while (i < w->size)
	{
		index = indexing(numbers[i], numbers, w->size);
		new = lstnew(numbers[i], index);
		if (!new)
			exit_error();
		lstadd_back(&a, new);
		i++;
	}
	return (a);
}

t_stack	*a_init(t_world	*w, int size, char **argv, int add)
{
	t_stack	*a;
	int		i;
	int		*numbers;

	i = 0;
	a = NULL;
	numbers = (int *) malloc (sizeof(int) * size);
	w->size = size;
	w->checker = 0;
	while (i < size)
	{
		if (check_input(i + add, argv) != 0)
		{
			if (add == 0)
				free_memory((void **)argv);
			free(numbers);
			exit_error();
		}
		numbers[i] = ft_atoi(argv[i + add]);
		i++;
	}
	a = create_lists(w, a, numbers);
	free(numbers);
	return (a);
}
