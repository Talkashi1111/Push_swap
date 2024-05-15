/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:05:30 by tkashi            #+#    #+#             */
/*   Updated: 2024/02/07 13:05:32 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_sorted(t_stacks *stacks)
{
	t_node	*node;

	if (stacks->size[A] < 2)
		return (TRUE);
	node = stacks->s[A];
	while (node->next)
	{
		if (node->nbr > node->next->nbr)
			return (FALSE);
		node = node->next;
		if (node->next == stacks->s[A])
			break ;
	}
	return (TRUE);
}

void	sort_three(t_stacks *stacks)
{
	if (stacks->s[A]->nbr > stacks->s[A]->next->nbr
		&& stacks->s[A]->nbr > stacks->s[A]->next->next->nbr)
	{
		rotate(stacks, A, TRUE);
	}
	else if (stacks->s[A]->next->nbr > stacks->s[A]->next->next->nbr)
		reverse_rotate(stacks, A, TRUE);
	if (stacks->s[A]->nbr > stacks->s[A]->next->nbr)
		swap(stacks, A, TRUE);
}

int	find_min_idx(t_stacks *stacks)
{
	t_node	*node;
	int		i;
	int		min_nbr;
	int		min_nbr_idx;

	min_nbr = INT_MAX;
	min_nbr_idx = -1;
	node = stacks->s[A];
	i = 0;
	while (i < stacks->size[A])
	{
		if (node->nbr <= min_nbr)
		{
			min_nbr = node->nbr;
			min_nbr_idx = i;
		}
		node = node->next;
		i++;
	}
	return (min_nbr_idx);
}

int	get_target_idx(t_stacks *stacks, int nbr)
{
	t_node	*node;
	int		i;
	int		last_nbr;
	int		last_nbr_idx;

	last_nbr = INT_MAX;
	last_nbr_idx = -1;
	node = stacks->s[A];
	i = 0;
	while (i < stacks->size[A])
	{
		if (nbr < node->nbr && node->nbr <= last_nbr)
		{
			last_nbr = node->nbr;
			last_nbr_idx = i;
		}
		node = node->next;
		i++;
	}
	if (last_nbr_idx != -1)
		return (last_nbr_idx);
	return (find_min_idx(stacks));
}

void	finalize_pos(t_stacks *stacks)
{
	int	min_idx;
	int	i;

	min_idx = find_min_idx(stacks);
	i = 0;
	if (min_idx == 0)
		return ;
	if (min_idx <= stacks->size[A] / 2)
	{
		while (i < min_idx)
		{
			rotate(stacks, A, TRUE);
			i++;
		}
	}
	else
	{
		while (i < stacks->size[A] - min_idx)
		{
			reverse_rotate(stacks, A, TRUE);
			i++;
		}
	}
}
