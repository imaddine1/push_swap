/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:40:39 by iharile           #+#    #+#             */
/*   Updated: 2022/02/06 11:58:48 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_INPUTS_H

# define CHECK_INPUTS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int	compare_string(char *s1, char *s2);
int	check_double(char **str);
int	max_int(char *str);
int	check_int(char **str);

#endif
