/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:04:52 by tkashi            #+#    #+#             */
/*   Updated: 2024/02/07 13:05:01 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pa(t_stacks *stacks, int to_print)
{
	t_node	*node;

	node = pop(stacks, B);
	if (node)
		push(stacks, node, A);
	if (to_print)
		ft_printf("pa\n");
}

void	pb(t_stacks *stacks, int to_print)
{
	t_node	*node;

	node = pop(stacks, A);
	if (node)
		push(stacks, node, B);
	if (to_print)
		ft_printf("pb\n");
}

void	swap(t_stacks *stacks, int idx, int to_print)
{
	int		tmp;

	if (stacks->size[idx] > 1)
	{
		tmp = stacks->s[idx]->nbr;
		stacks->s[idx]->nbr = stacks->s[idx]->next->nbr;
		stacks->s[idx]->next->nbr = tmp;
	}
	if (to_print && idx == A)
		ft_printf("sa\n");
	else if (to_print)
		ft_printf("sb\n");
}

void	ss(t_stacks *stacks, int to_print)
{
	swap(stacks, A, FALSE);
	swap(stacks, B, FALSE);
	if (to_print)
		ft_printf("ss\n");
}
