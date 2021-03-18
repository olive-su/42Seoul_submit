/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseonghee <jinseonghee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:43:45 by jinseonghee       #+#    #+#             */
/*   Updated: 2021/03/14 22:38:01 by jinseonghee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		av_check(int *fd, char *path, char *str_nb)
{
	*fd = open(path, O_RDONLY);
	if (*fd < 0)
		return (!write(1, "Dict Error\n", 11));
	if (!(valid_nb(str_nb)))
		return (!write(1, "Error\n", 6));
	return (1);
}

int		main(int ac, char *av[])
{
	int		fd;
	char	**dic;

	fd = 0;
	if (ac == 2)
	{
		if (!av_check(&fd, "numbers.dict", av[1]))
			return (1);
	}
	else if (ac == 3)
	{
		if (!av_check(&fd, av[1], av[2]))
			return (1);
	}
	else
		return (write(1, "Error\n", 6));
	dic = get_dic(fd);
	if (!dic)
		return (!write(1, "Dict Error\n", 11));
	ac == 2 ? print_nb(av[1], dic) : print_nb(av[2], dic);
	free_dic(dic, 40);
	close(fd);
	return (0);
}
