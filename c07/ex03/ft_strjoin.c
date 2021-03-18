/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:56:17 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/18 20:05:35 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	char *tmp;

	tmp = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (tmp);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_len;
	char	*buff;

	i = -1;
	total_len = 0;
	if (size == 0)
	{
		buff = (char *)malloc(1);
		return (buff);
	}
	while (++i < size)
		total_len += ft_strlen(strs[i]);
	buff = (char *)malloc(total_len + 1 + ft_strlen(sep) * (size - 1));
	if (!buff)
		return (0);
	i = -1;
	*buff = '\0';
	while (++i < size)
	{
		buff = ft_strcat(buff, strs[i]);
		if (i != (size - 1))
			buff = ft_strcat(buff, sep);
	}
	return (buff);
}
