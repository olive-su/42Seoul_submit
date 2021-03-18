/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:50:59 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/11 10:23:41 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*result;
	unsigned int	i;

	i = 0;
	result = dest;
	while (*dest)
		dest++;
	while (*src && i < nb)
	{
		i++;
		*dest++ = *src++;
	}
	while (*dest)
	{
		*dest = 0;
		dest++;
	}
	return (result);
}
