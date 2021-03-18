/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 23:41:13 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/17 02:51:39 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int				len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char				*ft_strdup(char *src)
{
	char			*dest;
	char			*result;
	int				len;

	len = ft_strlen(src);
	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	result = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	dest = 0;
	return (result);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	t_stock_str		*result;

	if (!(result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (0);
	i = 0;
	while (i < ac)
	{
		result[i].size = ft_strlen(av[i]);
		result[i].str = av[i];
		result[i].copy = ft_strdup(av[i]);
		i++;
	}
	result[i].size = 0;
	result[i].str = 0;
	result[i].copy = 0;
	return (result);
}
