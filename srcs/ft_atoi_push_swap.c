/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:02:23 by tkashi            #+#    #+#             */
/*   Updated: 2024/02/07 13:04:33 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	atoi_logics(char *str, int *num, int cnt_minuses)
{
	if (!ft_isdigit(*str))
		return (FALSE);
	if (*num > 0 && cnt_minuses % 2 == 1)
		*num *= -1;
	if (*num < INT_MIN / 10 || (*num == INT_MIN / 10 && *str - '0' > 8))
		return (FALSE);
	if (*num > INT_MAX / 10 || (*num == INT_MAX / 10 && *str - '0' > 7))
		return (FALSE);
	if (cnt_minuses % 2 == 1)
		*num = *num * 10 - (*str - '0');
	else
		*num = *num * 10 + (*str - '0');
	return (TRUE);
}

int	get_atoi(char *str, int *num)
{
	int	cnt_minuses;

	*num = 0;
	cnt_minuses = 0;
	while ((*str == '+' || *str == '-') && *str != '\0')
	{
		if (*str == '-')
			cnt_minuses++;
		str++;
	}
	if (!ft_isdigit(*str))
		return (FALSE);
	while (*str != '\0' && !is_whitespace(*str))
	{
		if (!atoi_logics(str, num, cnt_minuses))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
