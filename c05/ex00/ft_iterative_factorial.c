/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:47:03 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/15 02:52:27 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int result;

	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else if (nb <= 2)
		return (nb);
	else if (nb > 2)
	{
		result = 1;
		while (nb > 1)
		{
			result *= nb;
			nb--;
		}
		return (result);
	}
	return (0);
}
