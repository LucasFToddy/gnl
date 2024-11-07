/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:41:27 by lucas-do          #+#    #+#             */
/*   Updated: 2024/10/30 16:41:29 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

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