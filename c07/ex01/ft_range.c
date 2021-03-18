/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:09:05 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/18 22:09:07 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	size;
	int	*arr;
	int i;

	i = 0;
	size = max - min;
	if (size <= 0)
		return (0);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
