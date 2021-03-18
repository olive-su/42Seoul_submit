/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseonghee <jinseonghee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:44:05 by jinseonghee       #+#    #+#             */
/*   Updated: 2021/03/14 10:52:47 by jinseonghee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	*free_dic(char **dic, int j)
{
	while (j >= 0)
	{
		free(dic[j]);
		j--;
	}
	free(dic);
	return (NULL);
}
