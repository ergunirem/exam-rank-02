/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 17:33:06 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/01/11 22:28:45 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define BUFFER_SIZE 20

int		get_next_line(char **line);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *s);
char	*update_container(char *container);
char	*get_line(char *container);

#endif
