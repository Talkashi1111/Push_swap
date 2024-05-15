/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:05:49 by tkashi            #+#    #+#             */
/*   Updated: 2024/02/07 13:05:51 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define FALSE 0
# define TRUE 1
# define A 0
# define B 1
# define SEPARATED 0
# define RR 1
# define RRR 2
# define RA 3
# define RB 4
# define RRA 5
# define RRB 6
# define PA 7
# define PB 8
# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	struct s_node		*next;
	struct s_node		*prev;
	int					nbr;
}				t_node;	

typedef struct s_params
{
	int	src_idx;
	int	target_idx;
	int	price;
	int	algoritm;
}			t_params;

typedef struct s_stacks
{
	t_node			*s[2];
	int				size[2];
}					t_stacks;

void	init_stacks(t_stacks *stacks);
void	free_stacks(t_stacks *stacks);
int		is_whitespace(char c);
int		get_atoi(char *str, int *num);
int		atoi_logics(char *str, int *num, int cnt_minuses);
int		has_duplicates(t_stacks *stacks, int num);
int		add_to_stack(t_stacks *stacks, int num);
int		ft_split_arguments(t_stacks *stacks, char *str, int *start, int *num);
t_node	*pop(t_stacks *stacks, int idx);
void	push(t_stacks *stacks, t_node *node, int idx);
void	rotate(t_stacks *stacks, int idx, int to_print);
void	reverse_rotate(t_stacks *stacks, int idx, int to_print);
void	swap(t_stacks *stacks, int idx, int to_print);
void	ss(t_stacks *stacks, int to_print);
void	rr(t_stacks *stacks, int to_print);
void	rrr(t_stacks *stacks, int to_print);
void	pa(t_stacks *stacks, int to_print);
void	pb(t_stacks *stacks, int to_print);
void	push_swap(t_stacks *stacks);
int		is_sorted(t_stacks *stacks);
int		error_handle(t_stacks *stacks);
void	calc_price(t_stacks *stacks, t_node *node, t_params *params);
int		calc_price_rrr(t_stacks *stacks, int src_idx, int target_idx);
int		calc_price_rr(int src_idx, int target_idx);
int		calc_price_seperate(t_stacks *stacks, int src_idx, int target_idx);
int		get_target_idx(t_stacks *stacks, int nbr);
int		find_min_idx(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	finalize_pos(t_stacks *stacks);
void	apply_sep_move(t_stacks *stacks, int stack_id, int node_idx);
void	sep_move_algo(t_stacks *stacks, t_params *params);
void	apply_rr_move(t_stacks *stacks, int stack_id,
			int smaller_idx, int bigger_idx);
void	apply_rrr_move(t_stacks *stacks, int stack_id,
			int smaller_idx, int bigger_idx);
void	rrr_move_algo(t_stacks *stacks, t_params *params);
void	rr_move_algo(t_stacks *stacks, t_params *params);
#endif