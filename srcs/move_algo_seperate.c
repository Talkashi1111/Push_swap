/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_algo_seperate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:03:16 by tkashi            #+#    #+#             */
/*   Updated: 2024/02/07 13:07:41 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	apply_sep_move(t_stacks *stacks, int stack_id, int node_idx)
{
	int	i;

	i = 0;
	if (node_idx < stacks->size[stack_id] / 2)
	{
		while (i < node_idx)
		{
			rotate(stacks, stack_id, TRUE);
			i++;
		}
	}
	else
	{
		while (i < stacks->size[stack_id] - node_idx)
		{
			reverse_rotate(stacks, stack_id, TRUE);
			i++;
		}
	}
}

void	sep_move_algo(t_stacks *stacks, t_params *params)
{
	apply_sep_move(stacks, B, params->src_idx);
	apply_sep_move(stacks, A, params->target_idx);
	pa(stacks, TRUE);
}
