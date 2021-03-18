/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:46:30 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/07 22:36:31 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		g_arr[7][7];
int		g_flag = 0;

void	combnation(int row, int col);

int		get_func(char *str, int *com, int idx, int c_idx)
{
	int	space;

	space = 1;
	while (str[++idx] != '\0')
	{
		if (!(str[idx] == ' ' || (str[idx] >= '1' && str[idx] <= '4')))
			return (0);
		if (str[idx] == ' ')
		{
			if (space || c_idx == 16)
				return (0);
			space = 1;
		}
		if (str[idx] != ' ' && space)
		{
			com[c_idx++] = str[idx] - '0';
			space = 0;
		}
	}
	if (c_idx != 16)
		return (0);
	return (1);
}

int		get_length(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
		idx++;
	return (idx);
}

int		get_command(char *str, int *com)
{
	int idx;
	int c_idx;
	int result;

	c_idx = 0;
	idx = get_length(str);
	result = get_func(str, com, idx, c_idx);
	return (result);
}

void	write_command(int *com)
{
	int i;

	i = 1;
	while (i <= 16)
	{
		if (i <= 4)
			g_arr[0][i] = com[i - 1];
		else if (i <= 8)
			g_arr[5][i - 4] = com[i - 1];
		else if (i <= 12)
			g_arr[i - 8][0] = com[i - 1];
		else
			g_arr[i - 12][5] = com[i - 1];
		i++;
	}
}

int		main(int params, char **str)
{
	int *com;
	int i;
	int valid;

	if (params != 2)
		write(1, "Error\n", 6);
	else
	{
		com = (int *)malloc(sizeof(int) * 16);
		valid = get_command(*str, com);
		if (valid)
		{
			i = 1;
			write_command(com);
			combnation(1, 1);
			if (!g_flag)
				write(1, "Error\n", 6);
		}
		else
			write(1, "Error\n", 6);
		free(com);
	}
	return (0);
}
