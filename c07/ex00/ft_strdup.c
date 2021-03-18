/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:21:06 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/17 00:34:56 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*result;
	int		len;

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
