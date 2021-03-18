/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseonghee <jinseonghee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:44:31 by jinseonghee       #+#    #+#             */
/*   Updated: 2021/03/14 22:09:45 by jinseonghee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	print_unity(char *nb, char **dic, int *i)
{
	int key;

	if (nb[0] != '0')
	{
		if (*i)
			write(1, " ", 1);
		(*i)++;
		key = nb[0] - '0';
		write(1, dic[key], ft_strlen(dic[key]));
	}
}
