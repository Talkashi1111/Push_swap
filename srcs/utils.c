/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:05:37 by tkashi            #+#    #+#             */
/*   Updated: 2024/02/07 13:05:38 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f');
}

int	has_duplicates(t_stacks *stacks, int num)
{
	t_node	*node;

	if (stacks->size[A] == 0)
		return (FALSE);
	if (stacks->size[A] == 1)
	{
		if (stacks->s[A]->nbr == num)
			return (TRUE);
		return (FALSE);
	}
	node = stacks->s[A];
	while (node->next != stacks->s[A])
	{
		if (node->nbr == num)
			return (TRUE);
		node = node->next;
	}
	if (node->nbr == num)
		return (TRUE);
	return (FALSE);
}

int	error_handle(t_stacks *stacks)
{
	free_stacks(stacks);
	ft_printf("Error\n");
	return (0);
}

int	ft_split_arguments(t_stacks *stacks, char *str, int *start, int *num)
{
	int		count;
	int		end;

	count = 0;
	end = 0;
	while (str[*start] != '\0')
	{
		while (str[*start] != '\0' && is_whitespace(str[*start]))
			(*start)++;
		end = *start;
		while (str[end] != '\0' && !is_whitespace(str[end]))
			end++;
		if (end == *start && count == 0)
			return (error_handle(stacks));
		if (end > *start)
		{
			if (!get_atoi(&str[*start], num) || !add_to_stack(stacks, *num))
				return (error_handle(stacks));
			count++;
		}
		*start = end;
	}
	return (1);
}
