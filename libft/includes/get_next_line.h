/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:07:10 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 19:59:12 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 42
# include <stdio.h>
# include "libft.h"

char	*get_next_line(int fd);
char	*remtrim(char *remnant);
char	*remstr(char *str, char *remnant);
int		is_newline(char *str);

#endif