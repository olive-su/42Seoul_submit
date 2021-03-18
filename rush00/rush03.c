/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 12:54:28 by sugkim            #+#    #+#             */
/*   Updated: 2021/02/21 12:54:37 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	top_line(int x)
{
	ft_putchar('A');
	while (x > 2)
	{
		ft_putchar('B');
		x--;
	}
	if (x != 1)
	{
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	middle_line(int x, int y)
{
	int	x_count;

	while (y > 2)
	{
		x_count = x;
		ft_putchar('B');
		while (x_count > 2)
		{
			ft_putchar(' ');
			x_count--;
		}
		if (x != 1)
		{
			ft_putchar('B');
		}
		y--;
		ft_putchar('\n');
	}
}

void	bottom_line(int x, int y)
{
	if (y != 1)
	{
		ft_putchar('A');
		while (x > 2)
		{
			ft_putchar('B');
			x--;
		}
		if (x != 1)
		{
			ft_putchar('C');
		}
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	top_line(x);
	middle_line(x, y);
	bottom_line(x, y);
}
