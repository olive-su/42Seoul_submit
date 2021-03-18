/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 03:44:03 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/18 03:44:04 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "map.h"
#include "tools.h"
#include <stdlib.h>

void	ft_map_print(int **map, t_map_params *params)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = -1;
	if (!(str = malloc(sizeof(*str) * params->columns + 1)))
		return ;
	while (++i < params->lines)
	{
		k = 0;
		j = -1;
		while (++j < params->columns - 1)
		{
			if (map[i][j] == -1)
				str[k++] = params->fill;
			else if (map[i][j] == 0)
				str[k++] = params->obstacles;
			else
				str[k++] = params->empty;
		}
		str[k++] = '\n';
		str[k] = '\0';
		ft_putstr(str);
	}
}
