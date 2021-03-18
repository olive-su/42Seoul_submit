/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:38:19 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/16 12:36:21 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	long long	sqrt;
	int			i;

	sqrt = 1;
	i = 2;
	if (nb > 1)
	{
		while (sqrt * sqrt <= (long long)nb)
		{
			sqrt++;
		}
		while (i <= sqrt)
		{
			if (nb % i == 0)
				return (0);
			i++;
		}
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	else if (ft_is_prime(nb))
		return (nb);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
