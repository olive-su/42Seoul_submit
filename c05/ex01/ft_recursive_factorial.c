/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:47:21 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/15 03:36:43 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
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
		result = nb * ft_recursive_factorial(nb - 1);
		return (result);
	}
	return (0);
}
