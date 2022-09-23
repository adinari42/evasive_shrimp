/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 21:00:42 by adinari           #+#    #+#             */
/*   Updated: 2022/09/22 23:32:42 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*ft_strchr(char *string, int n);
char	*new_bufferstart(char *buffer);
char	*gener_line(char *buffer);
char	*init_buffer(int fd, char *orig_buffer);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*init_buffer(int fd, char *orig_buffer);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strlenn(const char *s);

#endif