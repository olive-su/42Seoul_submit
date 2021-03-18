/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 21:32:00 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/06 14:17:01 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int tmp;
	int rev;
	int i;

	i = 0;
	rev = size - 1;
	while (i < (size / 2))
	{
		tmp = tab[i];
		tab[i] = tab[rev];
		tab[rev] = tmp;
		i++;
		rev--;
	}
}
