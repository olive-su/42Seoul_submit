/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:48:04 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/15 22:48:05 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	ft_putnbr(int nb)
{
	long nbr_long;

	nbr_long = nb;
	if (nbr_long < 0)
	{
		ft_putchar('-');
		nbr_long = -nbr_long;
	}
	if (nbr_long >= 10)
	{
		ft_putnbr(nbr_long / 10);
	}
	ft_putchar('0' + nbr_long % 10);
}
