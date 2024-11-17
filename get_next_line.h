/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:19:21 by lucas-do          #+#    #+#             */
/*   Updated: 2024/10/30 17:19:23 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 42

#endif

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int     ft_strchar(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char    *get_next_line(int fd);
size_t   ft_strlen(char *s);
char	*ft_strdup(char *s);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcat(char *dst, char *src, size_t size);

#endif