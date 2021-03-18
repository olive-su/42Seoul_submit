/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 01:47:33 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/09 02:26:40 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex1(unsigned char c)
{
	c /= 16;
	if (c > 9)
		c += 87;
	else
		c += 48;
	write(1, "\\", 1);
	write(1, &c, 1);
}

void	print_hex2(unsigned char c)
{
	c %= 16;
	if (c > 9)
		c += 87;
	else
		c += 48;
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str > 126)
		{
			print_hex1((int)*str);
			print_hex2((int)*str);
		}
		else
			write(1, str, 1);
		str++;
	}
}
