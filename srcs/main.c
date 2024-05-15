/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:03:03 by tkashi            #+#    #+#             */
/*   Updated: 2024/02/07 13:07:43 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/**
 * @brief Prints the contents of the stacks.
 * for needs of verification and debugging
 */
void	print_stacks(t_stacks *stacks)
{
	t_node	*node;

	ft_printf("Stack A:\n");
	node = stacks->s[A];
	while (node)
	{
		ft_printf("%d\n", node->nbr);
		node = node->next;
		if (node == stacks->s[A])
			break ;
	}
	ft_printf("Stack B:\n");
	node = stacks->s[B];
	while (node)
	{
		ft_printf("%d\n", node->nbr);
		node = node->next;
		if (node == stacks->s[B])
			break ;
	}
}

int	main(int argc, char *argv[])
{
	int			i;
	int			start;
	int			num;
	t_stacks	stacks;

	if (argc < 2)
		return (0);
	init_stacks(&stacks);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (error_handle(&stacks));
		start = 0;
		while (argv[i][start] != '\0')
		{
			if (!ft_split_arguments(&stacks, argv[i], &start, &num))
				return (0);
		}
		i++;
	}
	push_swap(&stacks);
	free_stacks(&stacks);
	return (0);
}
