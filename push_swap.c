/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:44:32 by iharile           #+#    #+#             */
/*   Updated: 2022/02/05 12:46:42 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "facile.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	compare_string(char *s1, char *s2)
{
	int	i;

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

int	check_int(char **str)
{
	int	i;
	int	j;

	j = 1;
	if (!str)
		return (0);
	while (str[j])
	{
		i = 0;
		if (str[j][i] == '-')
			i++;
		while (str[j][i])
		{
			if (!(str[j][i] >= '0' && str[j][i] <= '9'))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ac == 1 || !check_int(av) || !check_double(av))
	{
		write (1, "Error\n", 6);
		exit(1);
	}
	return (0);
}
