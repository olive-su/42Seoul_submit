/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:49:40 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/18 02:51:42 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "map.h"

char	*ft_read_file(int fd, t_map_params *params);
int		**ft_map_sorting(char *grid, t_map_params *params);
int		**ft_optimal_locate(int **map, t_map_params map_params);
void	ft_map_print(int **map, t_map_params *params);

#endif
