/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 23:12:32 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/15 03:12:27 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long sqrt;
	long long nbr;

	sqrt = 1;
	nbr = nb;
	if (nbr <= 0)
		return (0);
	while (sqrt * sqrt <= nbr)
	{
		if (sqrt * sqrt == nbr)
			return (sqrt);
		sqrt++;
	}
	return (0);
}
