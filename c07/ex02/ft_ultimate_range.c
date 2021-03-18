/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:02:41 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/18 20:02:45 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*array;
	int	len;

	if (min >= max)
		return (0);
	len = 0;
	array = (int*)malloc(sizeof(int) * (max - min));
	if (!array)
		return (-1);
	while (min < max)
	{
		array[len] = min;
		min++;
		len++;
	}
	*range = array;
	return (len);
}
