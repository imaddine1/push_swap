/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:40:39 by iharile           #+#    #+#             */
/*   Updated: 2022/02/09 16:27:47 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// check inputs
int		compare_string(char *s1, char *s2);
int		check_double(char **str);
int		max_int(char *str);
int		check_int(char **str);
// sorting fun
void	sort_tab(int *arr, int lb, int ub);
void	merge(int *arr, int lb, int mid, int ub);
// global

// pb pa
void	pb(t_list **g_stack_a, t_list **g_stack_b);
void	pa(t_list **g_stack_a, t_list **g_stack_b);
#endif
