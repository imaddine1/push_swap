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


int	check_double(int *nbr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (nbr[i] == nbr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i] && (str[i]>= '0' && str[i] <= '9' ))
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);
}

int	main (int ac, char **av)
{
	int	i;
	int	*integer;
	int	j;

	i = 1;
	j = 0;
	if (ac == 1)
	{
		write (1, "Error\n", 6);
		exit(1);
	}
	while (i < ac)
	{
		if (!check_int(av[i]))
		{
			write (1, "print just numbers\n", 19);
			exit(1);
		}
		i++;
	}
	integer = malloc (sizeof(int) * (ac - 1));
	if (!integer)
		return (0);
	i = 1;
	while (av[i])
	{
		integer[i - 1] = ft_atoi(av[i]);
		i++;
	}
	if (!check_double(integer, ac - 1))
	{
		write (1, "forbiden insert the same number\n", 32);
		exit(1);
	}
	return (0);
}
