/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:52:28 by iharile           #+#    #+#             */
/*   Updated: 2021/11/22 10:56:31 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	unsigned char	digit;

	digit = (unsigned char)c;
	if (digit >= '0' && digit <= '9')
		return (1);
	return (0);
}