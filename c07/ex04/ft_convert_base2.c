/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:56:55 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/18 19:56:59 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (*base)
	{
		i++;
		base++;
	}
	return (i);
}

int		is_valid_base(char *base)
{
	char	*cur;
	int		i;
	int		j;

	cur = base;
	if (base == 0 || ft_strlen(base) <= 1)
		return (0);
	while (*cur)
	{
		if (*cur == 32 || (*cur >= 9 && *cur <= 13)
				|| *cur == '+' || *cur == '-')
			return (0);
		cur++;
	}
	i = -1;
	while (++i < ft_strlen(base))
	{
		j = i + 1;
		while (j < ft_strlen(base))
		{
			if (base[i] == base[j++])
				return (0);
		}
	}
	return (1);
}

int		ft_get_i(char c, char *base, int base_len)
{
	int	i;

	i = 0;
	while (i < base_len)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int	res;
	int	sign;
	int i;
	int base_len;

	sign = 1;
	res = 0;
	base_len = ft_strlen(base);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (*str)
	{
		i = ft_get_i(*(str++), base, base_len);
		if (i == -1)
			break ;
		res *= base_len;
		res += sign * i;
	}
	return (res);
}

void	ft_putnbr(int nbr, char *base, int base_len, char *res)
{
	unsigned int	nb;

	nb = 0;
	if (nbr == 0)
	{
		*res = base[0];
	}
	else if (nbr < 0)
	{
		*res = '-';
		res++;
		nb = -nbr;
	}
	else
		nb = nbr;
	while (nb > 0)
	{
		*res = base[nb % base_len];
		nb /= base_len;
		res++;
	}
}
