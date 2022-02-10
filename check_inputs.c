/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:41:07 by iharile           #+#    #+#             */
/*   Updated: 2022/02/10 12:22:48 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	check_double(char **str)
{
	int	j;
	int	k;

	j = 1;
	while (str[j])
	{
		k = j + 1;
		while (str[k])
		{
			if (ft_atoi(str[j]) == ft_atoi(str[k]))
				return (0);
			k++;
		}
		j++;
	}
	return (1);
}

int	max_int(char *str)
{
	int		sign;
	long	res;
	int		i;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		i++;
	}
	if (res * sign < -2147483648 || res * sign > 2147483647)
		return (0);
	return (1);
}

int	check_int(char **str)
{
	int		i;
	int		j;

	j = 1;
	while (str[j])
	{
		i = 0;
		if (str[j][i] == '\0')
			return (0);
		if (str[j][i] == '-' || str[j][i] == '+')
			i++;
		while (str[j][i])
		{
			if (!(str[j][i] >= '0' && str[j][i] <= '9') || !max_int(str[j]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
