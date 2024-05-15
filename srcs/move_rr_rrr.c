/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:03:30 by tkashi            #+#    #+#             */
/*   Updated: 2024/02/07 13:07:39 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	apply_rr_move(t_stacks *stacks, int stack_id,
	int smaller_idx, int bigger_idx)
{
	int	i;

	i = 0;
	while (i < smaller_idx)
	{
		rr(stacks, TRUE);
		i++;
	}
	while (i < bigger_idx)
	{
		rotate(stacks, stack_id, TRUE);
		i++;
	}
}

void	rr_move_algo(t_stacks *stacks, t_params *params)
{
	if (params->src_idx <= params->target_idx)
		apply_rr_move(stacks, A, params->src_idx, params->target_idx);
	else
		apply_rr_move(stacks, B, params->target_idx, params->src_idx);
	pa(stacks, TRUE);
}

void	apply_rrr_move(t_stacks *stacks, int stack_id,
	int smaller_idx, int bigger_idx)
{
	int	i;

	i = 0;
	while (i < smaller_idx)
	{
		rrr(stacks, TRUE);
		i++;
	}
	while (i < bigger_idx)
	{
		reverse_rotate(stacks, stack_id, TRUE);
		i++;
	}
}

void	rrr_move_algo(t_stacks *stacks, t_params *params)
{
	int	rev_src_idx;
	int	rev_target_idx;

	rev_src_idx = stacks->size[B] - params->src_idx;
	rev_target_idx = stacks->size[A] - params->target_idx;
	if (rev_src_idx <= rev_target_idx)
		apply_rrr_move(stacks, A, rev_src_idx, rev_target_idx);
	else
		apply_rrr_move(stacks, B, rev_target_idx, rev_src_idx);
	pa(stacks, TRUE);
}