/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_prices.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:02:44 by tkashi            #+#    #+#             */
/*   Updated: 2024/02/07 13:02:47 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	calc_price_seperate(t_stacks *stacks, int src_idx, int target_idx)
{
	int	price;

	if (src_idx < stacks->size[B] / 2)
		price = src_idx;
	else
		price = stacks->size[B] - src_idx;
	if (target_idx < stacks->size[A] / 2)
		price += target_idx;
	else
		price += stacks->size[A] - target_idx;
	return (price);
}

int	calc_price_rr(int src_idx, int target_idx)
{
	int	price;

	if (src_idx <= target_idx)
	{
		price = src_idx;
		price += target_idx - src_idx;
	}
	else
	{
		price = target_idx;
		price += src_idx - target_idx;
	}
	return (price);
}

int	calc_price_rrr(t_stacks *stacks, int src_idx, int target_idx)
{
	int	price;

	if (stacks->size[B] - src_idx <= stacks->size[A] - target_idx)
	{
		price = stacks->size[B] - src_idx;
		price += stacks->size[A] - target_idx - price;
	}
	else
	{
		price = stacks->size[A] - target_idx;
		price += stacks->size[B] - src_idx - price;
	}
	return (price);
}

void	calc_price(t_stacks *stacks, t_node *node, t_params *params)
{
	int	tmp_price;

	params->target_idx = get_target_idx(stacks, node->nbr);
	params->algoritm = SEPARATED; 
	params->price = calc_price_seperate(stacks,
			params->src_idx, params->target_idx);
	tmp_price = calc_price_rr(params->src_idx, params->target_idx);
	if (tmp_price < params->price)
	{
		params->price = tmp_price;
		params->algoritm = RR;
	}
	tmp_price = calc_price_rrr(stacks, params->src_idx, params->target_idx);
	if (tmp_price < params->price)
	{
		params->price = tmp_price;
		params->algoritm = RRR;
	}
}
