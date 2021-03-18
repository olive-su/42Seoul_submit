/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:27:07 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/14 15:22:13 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int		is_valid(int *queen, int cl)
{
	int		i;

	i = 0;
	while (i < cl)
	{
		if (queen[i] == queen[cl] || abs(i - cl) == abs(queen[i] - queen[cl]))
			return (0);
		i++;
	}
	return (1);
}

void	back_tracking(int *queen, int col, int *result)
{
	int		row;
	char	c;

	row = 0;
	if (col == 10)
	{
		while (row < 10)
		{
			c = queen[row] + 48;
			write(1, &c, 1);
			row++;
		}
		(*result)++;
		write(1, "\n", 1);
	}
	else
	{
		while (row < 10)
		{
			queen[col] = row;
			if (is_valid(queen, col))
				back_tracking(queen, col + 1, result);
			row++;
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		queen[10];
	int		col;
	int		result;

	result = 0;
	col = 0;
	back_tracking(queen, col, &result);
	return (result);
}
