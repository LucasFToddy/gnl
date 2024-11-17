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

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		a[i] = '\0';
		i++;
	}
}

char    *ft_sub(char **src)
{
        char    *temp_static;
        char    *s;

        if(ft_strchar(*src, '\n') != -1)
        {
                s = (char *)malloc(sizeof(char) * (ft_strchar(*src, '\n') + 2));
                if (!s)
                        return (NULL);
                s[ft_strchar(*src, '\n') + 1] = '\0';
                ft_bzero(s, (ft_strchar(*src, '\n') + 2));
                ft_strlcat(s, *src, (ft_strchar(*src, '\n') + 2));
                temp_static = *src;
                *src = ft_strdup(&(*src)[ft_strchar(*src, '\n')] + 1);
                free(temp_static);
                return (s);
        }
        else
                return(*src);

}

char    *ft_cpy_line(int fd, char **s, char **s_static)
{
        int  btys_read;
        
        btys_read = 1;
        // btys_read = read(fd, *s, BUFFER_SIZE);
        // if (btys_read < 0)
        //         return (NULL);
        // (*s)[btys_read] = '\0';
        while(btys_read > 0)
        {
                if (!*s_static)
                        *s_static = ft_strdup("");
                *s_static = ft_strjoin(*s_static, *s);
                if (ft_strchar(*s_static, '\n') != -1)
                        break;
                btys_read = read(fd, *s, BUFFER_SIZE);
                if (btys_read < 0)
                {
                        free(*s);
                        free(*s_static);
                        return (NULL);
                }
                if (btys_read == 0)
                {
                        free(*s);
                        *s = NULL;
                }
                else
                        (*s)[btys_read] = '\0';
        }
        return (ft_sub(s_static));
}

char    *get_next_line(int fd)
{
        char    *tmp;
        char    *line;
        static char *remaining = NULL;

        if (BUFFER_SIZE <= 0 || fd < 0)
                return (NULL);
        tmp = (char *) malloc(BUFFER_SIZE + 1);
        if (!tmp)
                return (NULL);
        tmp[0] = '\0';
        line = ft_cpy_line(fd, &tmp, &remaining);
        free(tmp);
        return (line);
}

// int     main()
// {
//         int     fd;
//         //char    *line;
//         char    *tmp;
//         int     c;

//         fd = open("teste.txt", O_RDONLY);
//         c = 0;
//         while (c < 4)
//         {
//                 printf("%d\n",c);
//                 tmp = get_next_line(fd);
//                 printf("%s",tmp);
//                 free(tmp);
//                 c++;
//         }
//         close(fd);
// }