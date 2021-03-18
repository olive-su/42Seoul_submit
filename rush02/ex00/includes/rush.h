/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseonghee <jinseonghee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:38:41 by alpeliss          #+#    #+#             */
/*   Updated: 2021/03/14 22:28:34 by jinseonghee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"

char		**get_dic(int fd);
int			ft_strlen(char *str);
int			ft_strstr(char *str, char *to_find);
char		**parse_file(char *file);
char		*ft_itoa(int nbr);
int			valid_nb(char *str_nb);
void		print_nb(char *nb, char **dic);
void		*free_dic(char **dic, int j);
void		print_unity(char *nb, char **dic, int *i);
int			valid_file(char *file);
int			num_offset(char *file);
int			space_offset(char *file);
int			printable_offset(char *file);

#endif
