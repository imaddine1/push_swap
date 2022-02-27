/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:21:28 by iharile           #+#    #+#             */
/*   Updated: 2021/11/27 14:31:45 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	findline(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	if (s[i] == '\n')
		return (0);
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	p = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = 0;
	free (s1);
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*cpy;

	cpy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (cpy == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
