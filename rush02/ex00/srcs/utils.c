/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseonghee <jinseonghee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:44:36 by jinseonghee       #+#    #+#             */
/*   Updated: 2021/03/14 22:32:37 by jinseonghee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int		ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (!to_find)
		return (-1);
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == to_find[j])
		{
			while (to_find[j] && str[i + j] && str[i + j] == to_find[j])
				j++;
			if (!to_find[j])
			{
				while (str[i + j] == ' ')
					j++;
				if (str[i + j] == ':' && (i == 0 || str[i - 1] == '\n'))
					return (i);
			}
			j = 0;
		}
	return (-1);
}

int		calc_size(long nb)
{
	int	size;

	size = 1;
	while (nb / 10)
	{
		size++;
		nb /= 10;
	}
	return (size + 1);
}

char	*ft_itoa(int nb)
{
	char	*str;
	int		i;
	long	div;

	if (!(str = (char *)malloc(calc_size(nb) * sizeof(char))))
		return (NULL);
	div = 1;
	while (nb / div > 9)
		div *= 10;
	i = 0;
	while (div)
	{
		str[i] = nb / div + '0';
		nb = nb % div;
		div = div / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		valid_nb(char *str_nb)
{
	int len;

	len = 0;
	while (str_nb[len])
	{
		if (str_nb[0] == '0' && str_nb[1])
			return (0);
		else if (!(str_nb[len] >= '0' && str_nb[len] <= '9'))
			return (0);
		len++;
	}
	if (len > 39)
		return (0);
	return (len);
}
