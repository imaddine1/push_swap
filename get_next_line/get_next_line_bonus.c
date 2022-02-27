/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:08:35 by iharile           #+#    #+#             */
/*   Updated: 2021/11/27 20:25:53 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*bf_line(char *s)
{
	int		i;
	char	*p;
	int		j;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			break ;
	if (s[i] == '\n')
		i++;
	p = malloc (sizeof(char) * (i + 1));
	j = -1;
	while (++j < i)
		p[j] = s[j];
	p[j] = 0;
	return (p);
}

char	*af_line(char *s, size_t j)
{
	size_t		i;
	char		*p;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	if (s[i] == '\0')
	{
		free (s);
		return (0);
	}
	p = malloc (sizeof(char) * (ft_strlen(&s[i]) + 1));
	while (i < ft_strlen(s))
		p[j++] = s[i++];
	p[j] = '\0';
	free (s);
	return (p);
}

char	*norminette_25(int fd, char *buff, char *new, int size)
{
	if (!buff)
	{
		size = read (fd, new, size);
		if (size == 0 || size == -1)
		{
			free (new);
			return (0);
		}
		new[size] = '\0';
		buff = ft_strdup(new);
	}
	while (findline(buff) && size)
	{
		size = read (fd, new, size);
		if (size == -1)
		{	
			free (new);
			return (0);
		}
		new[size] = '\0';
		buff = ft_strjoin(buff, new);
	}
	free(new);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[MAX_FD];
	char		*new;
	char		*old;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	new = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	buff[fd] = norminette_25(fd, buff[fd], new, BUFFER_SIZE);
	if (!buff[fd])
		return (0);
	old = bf_line(buff[fd]);
	buff[fd] = af_line(buff[fd], 0);
	return (old);
}
