/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 01:35:38 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/16 12:11:49 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_argv(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < argc)
	{
		j = 2;
		while (j < argc - i)
		{
			if (ft_strcmp(argv[j - 1], argv[j]) > 0)
			{
				tmp = argv[j - 1];
				argv[j - 1] = argv[j];
				argv[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1;
	ft_sort_argv(argc, argv);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
	return (0);
}
