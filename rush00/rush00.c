/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:47:00 by sugkim            #+#    #+#             */
/*   Updated: 2021/02/21 12:54:54 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	side_line(int x)
{
	ft_putchar('o');
	while (x > 2)
	{
		ft_putchar('-');
		x--;
	}
	if (x != 1)
	{
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	center_line(int x, int y)
{
	int x_count;

	while (y > 2)
	{
		x_count = x;
		ft_putchar('|');
		while (x_count > 2)
		{
			ft_putchar(' ');
			x_count--;
		}
		if (x != 1)
		{
			ft_putchar('|');
		}
		y--;
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	side_line(x);
	if (x > 1)
	{
		center_line(x, y);
		side_line(x);
	}
}
