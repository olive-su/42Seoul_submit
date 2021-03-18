/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:31:43 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/07 22:35:27 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int		g_arr[7][7];
extern int		g_flag;
int				g_row_check[7][7];
int				g_col_check[7][7];

void	confirm();

void	ft_run(void)
{
	int		i;
	int		j;
	char	temp;

	if (g_flag == 1)
	{
		i = 1;
		j = 1;
		while (i < 5)
		{
			j = 1;
			while (j < 5)
			{
				temp = g_arr[i][j] + '0';
				write(1, &temp, 1);
				if (j != 4)
					write(1, " ", 1);
				j++;
			}
			i++;
			write(1, "\n", 1);
		}
	}
}

void	check_one(int row, int col, int k, int val)
{
	g_row_check[row][k] = val;
	g_col_check[col][k] = val;
}

void	combnation(int row, int col)
{
	int k;

	if (col > 4)
		return ;
	if (row > 4)
	{
		confirm();
		ft_run();
		return ;
	}
	k = 0;
	while (++k <= 4)
	{
		if (g_row_check[row][k] == 0 & g_col_check[col][k] == 0)
		{
			check_one(row, col, k, 1);
			g_arr[row][col] = k;
			combnation(row, col + 1);
			if (g_flag)
				return ;
			if (col == 4)
				combnation(row + 1, 1);
			check_one(row, col, k, 0);
		}
	}
}
