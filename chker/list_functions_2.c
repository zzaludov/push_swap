/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:31:32 by zzaludov          #+#    #+#             */
/*   Updated: 2023/09/23 03:31:35 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	lstsize(t_stack *lst)
{
	int	lenght;

	lenght = 0;
	while (lst)
	{
		lst = lst->next;
		lenght++;
	}
	return (lenght);
}

int	lstmin(t_stack *lst)
{
	int	min;

	min = 2147483647;
	while (lst != NULL)
	{
		if (lst->i < min)
			min = lst->i;
		lst = lst->next;
	}
	return (min);
}

int	lstmax(t_stack *lst)
{
	int	max;

	max = -2147483648;
	while (lst != NULL)
	{
		if (lst->i > max)
			max = lst->i;
		lst = lst->next;
	}
	return (max);
}
