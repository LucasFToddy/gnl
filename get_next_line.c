/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:19:16 by lucas-do          #+#    #+#             */
/*   Updated: 2024/10/30 17:19:18 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"


void    ft_sub(char *s, char *src)
{
        size_t  i;
        size_t  len;
        size_t  count;
        size_t  d;

        len = ft_strlen(s);
        i = 0;
        while(s[i] != '\n' && s[i] != '\0')
                i++;
        if (s[i] == '\n')
        {
                i++;
                d = i;
        }
        count = 0;
        while (s[i] != '\0')
        {
                src[count] = s[i];
                count++;
                i++;
        }
        if (!src)
                src = ft_strdup("");
        src[count] = '\0';
        s[d] = '\0';
}

void    *ft_cpy_line(char *s, char **line)
{
        int     i;
        int     count;
        int     d;

        i = ft_strchar(s, '\n');
        *line = (char *) malloc(sizeof(char) * (i + 2));
        if (!*line)
        {
                free(s);
                return (NULL);
        }
        count = 0;
        while (count <= i)
        {
                (*line)[count] = s[count];
                count++;
        }
        (*line)[i + 1] = '\0';
        return (0);
}

char    *get_next_line(int fd)
{
        char    *tmp;
        char    *line;
        static char *remaining = NULL;
        int  btys_read;

        tmp = (char *) malloc(BUFFER_SIZE + 1);
        if (!tmp)
                return (NULL);
        line = "";
        if (BUFFER_SIZE > 0)
        {
                btys_read = read(fd, tmp, BUFFER_SIZE);
                tmp[btys_read] = '\0';
                if (btys_read == 0)
                {
                        if (ft_strlen(remaining) == 0)
                        {
                                free(tmp);
                                free(remaining);
                                remaining = NULL;
                                return (NULL);
                        }
                        line = ft_strjoin(line, tmp);
                        //ft_cpy_line(remaining, &line);
                        free(tmp);
                        ft_sub(line, remaining);
                        return (line);
                }
                if (ft_strchar(tmp, '\n') != -1)
                {
                        line = ft_strjoin(line, tmp);
                        //ft_cpy_line(remaining, &line);
                        free(tmp);
                        ft_sub(line, remaining);
                        return (line);
                }
                else
                {
                        while(btys_read > 0)
                        {
                                if (remaining)
                                        line = ft_strjoin(remaining, line);
                                line = ft_strjoin(line, tmp);
                                if (ft_strchar(line, '\n') != -1)
                                        break;
                                btys_read = read(fd, tmp, BUFFER_SIZE);
                        }
                        //ft_cpy_line(remaining, &line);
                        ft_sub(line,remaining);
                        free(tmp);
                        return (line);
                }
        }
        //ft_cpy_line(remaining, &line);
        //printf("%s", remaining);
        //ft_sub(remaining);
        //printf("%s", line);
        //free(tmp);
        return (0);
}

int     main()
{
        int     fd;
        //char    *line;
        char    *tmp;
        int     c;

        fd = open("teste.txt", O_RDONLY);
        c = 0;
        while (c < 3)
        {
                printf("%d\n",c);
                tmp = get_next_line(fd);
                printf("%s",tmp);
                free(tmp);
                c++;
        }
        close(fd);
}