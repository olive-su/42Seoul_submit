/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:56:45 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/18 19:56:47 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		is_valid_base(char *base);
int		ft_strlen(char *base);
int		ft_atoi_base(char *str, char *base);
void	ft_putnbr(int nbr, char *base, int base_len, char *res);

void	ft_revstr(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	if (str[i] == '-')
		i++;
	while (i < j)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i++;
		j--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		tmp;
	int		cnt;
	int		n;
	char	*res;

	cnt = 0;
	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (0);
	n = ft_atoi_base(nbr, base_from);
	tmp = n;
	if (n <= 0)
		cnt++;
	while (tmp)
	{
		cnt++;
		tmp /= ft_strlen(base_to);
	}
	res = (char *)malloc(cnt + 1);
	if (!res)
		return (0);
	res[cnt] = '\0';
	ft_putnbr(n, base_to, ft_strlen(base_to), res);
	ft_revstr(res);
	return (res);
}
