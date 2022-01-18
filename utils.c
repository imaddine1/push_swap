#include "facile.h"

int	ft_atoi(char *str)
{
	long	res;
	int	sign;
	int	i;

	res = 0;
	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign *= (-1);
			i++;
		}
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - 48;  
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
		{
			write (1, "You are typing number not integer\n", 34);
			exit(1);
		}
		i++;
	}
	return (res * sign);
}
