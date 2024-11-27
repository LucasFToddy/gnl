/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:19:16 by lucas-do          #+#    #+#             */
/*   Updated: 2024/11/23 14:54:53 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_strchar(char *s, int c)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_return_static(char **temp_static, char **remaining,
		char **line, int index_enter)
{
	if (index_enter != -1)
	{
		if (!*remaining || !**remaining)
		{
			free(*remaining);
			*remaining = NULL;
		}
		free(*temp_static);
		if (!ft_strlen(*line))
		{
			free(*line);
			return (NULL);
		}
		return (*line);
	}
	if (!ft_strlen(*remaining))
	{
		free(*remaining);
		*remaining = NULL;
		return (NULL);
	}
	*temp_static = ft_strdup(*remaining);
	free(*remaining);
	*remaining = NULL;
	return (*temp_static);
}

static char	*ft_sub(char **remaining)
{
	char	*temp_static;
	char	*line;
	int		index_enter;

	index_enter = ft_strchar(*remaining, '\n');
	if (index_enter != -1)
	{
		line = (char *)malloc(sizeof(char) * (index_enter + 2));
		if (!line)
			return (NULL);
		ft_bzero(line, (index_enter + 2));
		ft_strlcat(line, *remaining, (index_enter + 2));
		temp_static = *remaining;
		*remaining = ft_strdup(&(*remaining)[index_enter + 1]);
	}
	return (ft_return_static(&temp_static, remaining, &line, index_enter));
}

static char	*ft_cpy_line(int fd, char **tmp, char **remaining)
{
	int	btys_read;

	btys_read = 1;
	while (btys_read > 0)
	{
		*remaining = ft_strjoin(*remaining, *tmp);
		if (ft_strchar(*remaining, '\n') != -1)
			break ;
		btys_read = read(fd, *tmp, BUFFER_SIZE);
		if (btys_read < 0)
		{
			free(*tmp);
			*tmp = NULL;
			return (NULL);
		}
		if (btys_read == 0)
		{
			free(*tmp);
			*tmp = NULL;
		}
		else
			(*tmp)[btys_read] = '\0';
	}
	return (ft_sub(remaining));
}

char	*get_next_line(int fd)
{
	static char	*remaining[FD_MAX];
	char		*tmp;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FD_MAX)
		return (NULL);
	tmp = (char *) malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	line = ft_cpy_line(fd, &tmp, &remaining[fd]);
	if (!line)
		return (NULL);
	free(tmp);
	return (line);
}
