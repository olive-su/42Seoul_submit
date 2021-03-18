/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseonghee <jinseonghee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 22:10:33 by jinseonghee       #+#    #+#             */
/*   Updated: 2021/03/14 22:33:28 by jinseonghee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*add_letter(char *str, char c)
{
	int		i;
	char	*new;

	if (!(new = (char *)malloc((ft_strlen(str) + 2) * sizeof(char))))
	{
		if (str)
			free(str);
		return (NULL);
	}
	i = 0;
	if (str)
	{
		while (str[i])
		{
			new[i] = str[i];
			i++;
		}
	}
	if (str)
		free(str);
	new[i++] = c;
	new[i] = '\0';
	return (new);
}

char	*get_file(int fd)
{
	char	c;
	char	*file;

	c = '!';
	file = NULL;
	while (read(fd, &c, 1) > 0 && c)
		file = add_letter(file, c);
	return (file);
}

char	**get_dic(int fd)
{
	char	**dic;
	char	*file;

	dic = NULL;
	file = get_file(fd);
	if (!file)
		return (NULL);
	if (!valid_file(file))
	{
		if (file)
			free(file);
		return (NULL);
	}
	dic = parse_file(file);
	if (file)
		free(file);
	return (dic);
}
