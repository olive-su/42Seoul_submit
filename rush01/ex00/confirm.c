/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:47:33 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/07 22:31:53 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int g_arr[7][7];
extern int g_flag;

int		up_to_down(void)
{
	int i;
	int cnt;
	int max_h;
	int j;

	i = 1;
	while (i <= 4)
	{
		cnt = 0;
		max_h = -1;
		j = 1;
		while (j <= 4)
		{
			if (g_arr[j][i] > max_h)
				max_h = g_arr[j][i];
			if (g_arr[j][i] >= max_h)
				cnt++;
			j++;
		}
		if (cnt != g_arr[0][i])
			return (0);
		i++;
	}
	return (1);
}

int		down_to_up(void)
{
	int i;
	int cnt;
	int max_h;
	int j;

	i = 1;
	while (i <= 4)
	{
		cnt = 0;
		max_h = -1;
		j = 4;
		while (j >= 1)
		{
			if (g_arr[j][i] > max_h)
				max_h = g_arr[j][i];
			if (g_arr[j][i] >= max_h)
				cnt++;
			j--;
		}
		if (cnt != g_arr[5][i])
			return (0);
		i++;
	}
	return (1);
}

int		left_to_right(void)
{
	int cnt;
	int max_h;
	int i;
	int j;

	i = 1;
	while (i <= 4)
	{
		cnt = 0;
		max_h = -1;
		j = 1;
		while (j <= 4)
		{
			if (g_arr[i][j] > max_h)
				max_h = g_arr[i][j];
			if (g_arr[i][j] >= max_h)
				cnt++;
			j++;
		}
		if (cnt != g_arr[i][0])
			return (0);
		i++;
	}
	return (1);
}

int		right_to_left(void)
{
	int cnt;
	int max_h;
	int i;
	int j;

	i = 1;
	while (i <= 4)
	{
		cnt = 0;
		max_h = -1;
		j = 4;
		while (j >= 1)
		{
			if (g_arr[i][j] > max_h)
				max_h = g_arr[i][j];
			if (g_arr[i][j] >= max_h)
				cnt++;
			j--;
		}
		if (cnt != g_arr[i][5])
			return (0);
		i++;
	}
	return (1);
}

void	confirm(void)
{
	int check;

	check = 1;
	check = check * up_to_down();
	check = check * down_to_up();
	check = check * left_to_right();
	check = check * right_to_left();
	g_flag = check;
}
