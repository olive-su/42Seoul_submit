/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:43:02 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/07 01:10:46 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int j;

	while (1 < argc--)
	{
		j = 0;
		while (argv[argc][j])
			write(1, &argv[argc][j++], 1);
		write(1, "\n", 1);
	}
	return (0);
}
