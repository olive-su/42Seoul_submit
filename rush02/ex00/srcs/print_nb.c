/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseonghee <jinseonghee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:44:23 by jinseonghee       #+#    #+#             */
/*   Updated: 2021/03/14 22:32:52 by jinseonghee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	print_deci(char *nb, char **dic, int *i)
{
	int key;

	if (nb[0] == '1')
	{
		if (*i)
			write(1, " ", 1);
		(*i)++;
		write(1, dic[10 + nb[1] - '0'], ft_strlen(dic[10 + nb[1] - '0']));
	}
	else
	{
		if (nb[0] != '0')
		{
			if (*i)
				write(1, " ", 1);
			(*i)++;
			key = 20 + nb[0] - '2';
			write(1, dic[key], ft_strlen(dic[key]));
		}
		nb++;
		print_unity(nb, dic, i);
	}
}

void	print_hundr(char *nb, char **dic, int *i)
{
	if (nb[0] != '0')
	{
		print_unity(nb, dic, i);
		if (*i)
			write(1, " ", 1);
		(*i)++;
		write(1, dic[28], ft_strlen(dic[28]));
	}
	nb++;
	print_deci(nb, dic, i);
}

void	print_z_count(int nb_z_count, char **dic, int *i)
{
	if (nb_z_count > 0)
	{
		if (*i)
			write(1, " ", 1);
		(*i)++;
		write(1, dic[28 + nb_z_count], ft_strlen(dic[28 + nb_z_count]));
	}
}

void	print_alot(char *nb, char **dic, int *i)
{
	int z_count;
	int len_nb;
	int oth;

	len_nb = ft_strlen(nb);
	z_count = ((ft_strlen(nb) - 1) / 3);
	while (len_nb > 0)
	{
		oth = len_nb % 3;
		if (oth == 0)
			print_hundr(nb, dic, i);
		else if (oth == 1)
			print_unity(nb, dic, i);
		else if (oth == 2)
			print_deci(nb, dic, i);
		if (oth == 0)
			oth += 3;
		nb += oth;
		if (!(*(nb - 1) == '0' && *(nb - 2) == '0' && *(nb - 3) == '0'))
			print_z_count(z_count, dic, i);
		z_count--;
		len_nb = len_nb - oth;
	}
}

void	print_nb(char *nb, char **dic)
{
	int len_nb;
	int	i;

	i = 0;
	len_nb = ft_strlen(nb);
	if (len_nb == 1)
	{
		if (nb[0] == '0')
			write(1, dic[0], ft_strlen(dic[0]));
		else
			print_unity(nb, dic, &i);
	}
	if (len_nb == 2)
		print_deci(nb, dic, &i);
	if (len_nb == 3)
		print_hundr(nb, dic, &i);
	if (len_nb > 3)
	{
		print_alot(nb, dic, &i);
	}
	write(1, "\n", 1);
}
