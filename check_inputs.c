/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:41:07 by iharile           #+#    #+#             */
/*   Updated: 2022/02/06 13:23:11 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_inputs.h"
#include "libft/libft.h"

int	compare_string(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]))
		i++;
	if ((ft_strlen(s1) == i) && (ft_strlen(s2) == i))
		return (0);
	return (1);
}

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
			if (!compare_string(str[j], str[k]))
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
	if (str[i] == '-')
	{
		sign *= (-1);
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		else
			return (0);
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
		if (str[j][i] == '-')
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
