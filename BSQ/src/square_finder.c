/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:46:01 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/18 02:50:51 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		ft_square_point(int **map, int line, int col)
{
	int	min;

	if (line == 0 || col == 0)
		return (1);
	min = map[line - 1][col];
	if (map[line][col - 1] < min)
		min = map[line][col - 1];
	if (map[line - 1][col - 1] < min)
		min = map[line - 1][col - 1];
	return (min + 1);
}

void	ft_square_find(int **map, t_map_loc *optimal_loc)
{
	int	i;
	int	j;

	i = optimal_loc->y;
	while (i > optimal_loc->y - optimal_loc->point)
	{
		j = optimal_loc->x;
		while (j > optimal_loc->x - optimal_loc->point)
		{
			map[i][j] = -1;
			j--;
		}
		i--;
	}
}

int		**ft_optimal_locate(int **map, t_map_params map_params)
{
	int			i;
	int			j;
	t_map_loc	optimal_loc;

	optimal_loc.point = -1;
	i = -1;
	while (++i < map_params.lines)
	{
		j = -1;
		while (++j < map_params.columns - 1)
		{
			if (map[i][j] == -1)
			{
				map[i][j] = ft_square_point(map, i, j);
				if (map[i][j] > optimal_loc.point)
				{
					optimal_loc.x = j;
					optimal_loc.y = i;
					optimal_loc.point = map[i][j];
				}
			}
		}
	}
	ft_square_find(map, &optimal_loc);
	return (map);
}
