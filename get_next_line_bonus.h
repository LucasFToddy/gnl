/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:08:32 by lucas-do          #+#    #+#             */
/*   Updated: 2024/11/25 18:08:34 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

# ifndef FD_MAX

#  define FD_MAX 1024

# endif

# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strdup(char *s);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(char *s);
size_t	ft_strlcat(char *dst, char *src, size_t size);
#endif
