/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:52:26 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/14 11:42:30 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		base_check(char *base, int base_len)
{
	int i;
	int j;

	i = 0;
	if (base_len < 2)
		return (1);
	while (base[i++])
	{
		if (base[i] == '+' || base[i] == '-' ||
				(base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (1);
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_str_len(char *base)
{
	int len;

	len = 0;
	while (*base)
	{
		base++;
		len++;
	}
	return (len);
}

int		extract_index(char c, char *base)
{
	int idx;

	idx = 0;
	while (base[idx])
	{
		if (c == base[idx])
			return (idx);
		idx++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		result;
	int		base_len;
	int		sign;
	int		idx;

	result = 0;
	base_len = ft_str_len(base);
	sign = 1;
	if (base_check(base, base_len))
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32 || *str == 45 || *str == 43)
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (*str)
	{
		idx = extract_index(*str, base);
		if (idx == -1)
			break ;
		else
			result = (result * base_len) + idx;
		str++;
	}
	return (sign * result);
}
