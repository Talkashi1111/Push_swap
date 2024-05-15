/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:05:06 by tkashi            #+#    #+#             */
/*   Updated: 2024/02/07 13:05:21 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	move(t_stacks *stacks, t_params *params)
{
	if (params->algoritm == SEPARATED)
		sep_move_algo(stacks, params);
	else if (params->algoritm == RR)
		rr_move_algo(stacks, params);
	else
		rrr_move_algo(stacks, params);
}

void	transfer_cheapest(t_stacks *stacks)
{
	t_params	cheapest;
	t_params	current;
	t_node		*node;

	node = stacks->s[B];
	cheapest.src_idx = 0;
	calc_price(stacks, node, &cheapest);
	current.src_idx = 1;
	while (current.src_idx < stacks->size[B])
	{
		node = node->next;
		calc_price(stacks, node, &current);
		if (current.price < cheapest.price)
		{
			cheapest.price = current.price;
			cheapest.src_idx = current.src_idx;
			cheapest.target_idx = current.target_idx;
			cheapest.algoritm = current.algoritm;
		}
		current.src_idx++;
	}
	move(stacks, &cheapest);
}

void	push_swap(t_stacks *stacks)
{
	if (is_sorted(stacks))
		return ;
	if (stacks->size[A] == 2)
		return (swap(stacks, A, TRUE));
	if (stacks->size[A] == 3)
		return (sort_three(stacks));
	while (stacks->size[A] > 3)
		pb(stacks, TRUE);
	sort_three(stacks);
	while (stacks->size[B] > 0)
		transfer_cheapest(stacks);
	finalize_pos(stacks);
}
