/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 03:44:11 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/18 03:44:13 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdlib.h>

int	**ft_map_sorting(char *grid, t_map_params *map)
{
	int	j;
	int	k;
	int	**data;

	j = -1;
	k = 0;
	if (!(data = (int **)malloc(sizeof(*data) * map->lines)) ||
		!(data[++j] = (int *)malloc(sizeof(**data) * map->columns)))
		return (0);
	while (*grid != '\0')
	{
		if (*grid == '\n')
		{
			if (((k != map->columns - 1)) ||
				!(data[++j] = (int *)malloc(sizeof(**data) * map->columns)))
				return (0);
			k = 0;
		}
		if (*grid == map->empty)
			data[j][k++] = -1;
		if (*grid++ == map->obstacles)
			data[j][k++] = 0;
	}
	return (j != map->lines - 1 ? 0 : data);
}
