/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 03:43:53 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/18 12:20:26 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "map.h"
#include "tools.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 10000000

int		ft_strcat_to_int(char **dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while ((*dest)[i])
		i++;
	j = 0;
	while (src[j])
		(*dest)[i++] = src[j++];
	(*dest)[i] = '\0';
	return (j);
}

char	*ft_read_standard(void)
{
	int		size;
	int		size_temp;
	char	*buf;
	char	*str;

	buf = malloc(sizeof(char) * BUF_SIZE + 1);
	str = malloc(sizeof(char) * BUF_SIZE + 1);
	buf[0] = '\0';
	size_temp = read(0, str, BUF_SIZE);
	size = 0;
	while (size_temp > 0)
	{
		str[size_temp] = '\0';
		size = size + ft_strcat_to_int(&buf, str);
		size_temp = read(0, str, BUF_SIZE);
	}
	free(str);
	if (size == 0)
	{
		free(buf);
		return (NULL);
	}
	buf[size] = '\0';
	return (buf);
}

void	ft_standard_in(void)
{
	int		size_buff;
	char	*buff;
	int		fd;

	buff = ft_read_standard();
	fd = open("./standard_in.txt",
				O_RDWR | O_TRUNC | O_CREAT,
				S_IRWXU | S_IRWXG | S_IRWXO);
	size_buff = ft_strlen(buff);
	write(fd, buff, size_buff);
	close(fd);
}

void	matching_result(int i, char **av)
{
	int				fd;
	int				**map;
	char			*grid;
	t_map_params	params;

	av[0] = "./standard_in.txt";
	fd = open(av[i], O_RDONLY);
	if (!(fd == -1) && (grid = ft_read_file(fd, &params)) &&
		(map = ft_map_sorting(grid, &params)))
		ft_map_print(ft_optimal_locate(map, params), &params);
	else
		ft_map_error();
}

int		main(int ac, char **av)
{
	int	i;

	if (ac == 1)
	{
		ft_standard_in();
		matching_result(0, av);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			matching_result(i, av);
			i++;
		}
	}
	return (0);
}
