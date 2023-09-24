/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:15:28 by zzaludov          #+#    #+#             */
/*   Updated: 2023/08/18 22:29:57 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	push(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*new;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	while ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
	}
	(*stack)->next = first;
	new = first->next;
	first->next = NULL;
	*stack = new;
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next != NULL)
	{
		last = temp ;
		temp = temp->next;
	}
	temp->next = *stack;
	*stack = temp;
	last->next = NULL;
}
