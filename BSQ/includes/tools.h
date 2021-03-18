/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sugkim <sugkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:50:10 by sugkim            #+#    #+#             */
/*   Updated: 2021/03/15 22:50:14 by sugkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

char	*ft_strcat(char *dest, char *src);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
char	*ft_strncat(char *dest, char *src, int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_map_error();

#endif
