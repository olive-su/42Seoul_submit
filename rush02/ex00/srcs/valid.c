/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseonghee <jinseonghee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:52:02 by jinseonghee       #+#    #+#             */
/*   Updated: 2021/03/14 22:14:09 by jinseonghee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		num_offset(char *file)
{
	int i;

	i = 0;
	while (file[i] >= '0' && file[i] <= '9')
		i++;
	return (i);
}

int		space_offset(char *file)
{
	int	i;

	i = 0;
	while (file[i] == ' ')
		i++;
	return (i);
}

int		printable_offset(char *file)
{
	int i;

	i = 0;
	while (file[i] >= 32 && file[i] <= 126)
		i++;
	return (i);
}

int		valid_file(char *file)
{
	int		i;
	int		len;

	i = 0;
	while (file[i])
	{
		while (file[i] == '\n')
			i++;
		if (file[i] == '\0')
			break ;
		len = num_offset(file + i);
		if (len == 0 || len >= 39)
			return (0);
		i += len;
		i += space_offset(file + i);
		if (file[i] != ':')
			return (0);
		i++;
		i += space_offset(file + i);
		i += printable_offset(file + i);
		if (file[i] != '\n')
			return (0);
	}
	return (1);
}
