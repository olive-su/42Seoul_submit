/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseonghee <jinseonghee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:44:17 by jinseonghee       #+#    #+#             */
/*   Updated: 2021/03/14 22:33:12 by jinseonghee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		get_value_size(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] >= 32 && str[i] <= 126)
	{
		i++;
		j++;
		if (str[i] == ' ')
			j++;
		while (str[i] == ' ')
			i++;
	}
	return (j + 1);
}

char	*get_value(char *str)
{
	int		i;
	int		j;
	char	*value;

	if (!(value = (char *)malloc(get_value_size(str) * sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
	{
		value[j] = str[i];
		i++;
		j++;
		if (str[i] == ' ')
			value[j++] = str[i];
		while (str[i] == ' ')
			i++;
	}
	value[j] = '\0';
	return (value);
}

char	*find_value(char *key, char *file)
{
	int		i;
	char	*value;

	while ((i = ft_strstr(file, key)) < 0)
		return (NULL);
	while (file[i] != ':')
		i++;
	i++;
	while (file[i] == ' ')
		i++;
	if (file[i] < 33 || file[i] > 126)
		return (NULL);
	value = get_value(file + i);
	return (value);
}

char	**big_num(char **dic, int index, char *file)
{
	char	*key;
	int		digit;
	int		i;

	digit = 4;
	while (index < 41)
	{
		i = 0;
		if (!(key = (char *)malloc(sizeof(char *) * (digit + 1))))
			return (free_dic(dic, index - 1));
		key[i++] = '1';
		while (i < digit)
			key[i++] = '0';
		key[i] = '\0';
		if (!(dic[index] = find_value(key, file)))
		{
			free(key);
			return (free_dic(dic, index - 1));
		}
		free(key);
		digit += 3;
		index++;
	}
	return (dic);
}

char	**parse_file(char *file)
{
	char	*key;
	char	**dic;
	int		i;
	int		index;

	if (!(dic = (char **)malloc(42 * sizeof(char *))))
		return (NULL);
	i = 0;
	index = 0;
	while (i <= 100)
	{
		key = ft_itoa(i);
		dic[index] = find_value(key, file);
		free(key);
		if (!(dic[index]))
			return (free_dic(dic, index - 1));
		index++;
		i = (i < 20) ? i + 1 : i + 10;
	}
	if (!big_num(dic, index, file))
		return (NULL);
	dic[41] = NULL;
	return (dic);
}
