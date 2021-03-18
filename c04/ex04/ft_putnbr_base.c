/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:52:26 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/14 10:31:04 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		base_count(char *base)
{
	int	i;

	i = 0;
	while (*base)
	{
		base++;
		i++;
	}
	return (i);
}

int		base_check(char *base, int base_len)
{
	int	i;
	int j;

	i = 0;
	if (base_len < 2)
		return (1);
	while (base[i])
	{
		if (*base == '+' || *base == '-')
			return (1);
		j = i;
		while (j--)
		{
			if (base[i] == base[j])
				return (1);
		}
		i++;
	}
	return (0);
}

void	nbr_base(int nbr, char *base, int base_len)
{
	char c;

	if (nbr >= base_len)
	{
		nbr_base(nbr / base_len, base, base_len);
		nbr_base(nbr % base_len, base, base_len);
	}
	else
	{
		c = base[nbr];
		write(1, &c, 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = base_count(base);
	if (base_check(base, base_len))
	{
		return ;
	}
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		nbr_base(nbr / -base_len, base, base_len);
		nbr_base(nbr % -base_len, base, base_len);
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		nbr_base(nbr, base, base_len);
	}
	else
		nbr_base(nbr, base, base_len);
	return ;
}
