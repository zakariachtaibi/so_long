/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:01:46 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/02/22 00:00:53 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int file_line(char *file)
{
   int  fd;
   char *str;
   int  lines_num;

   lines_num = 0;
   fd = open(file, O_RDONLY);
   str = get_next_line(fd);
   if (!str)
        return (0);
    while (str)
    {
        if (ft_strncmp(str, "/n", 2))
            lines_num++;
        free(str);
        str = get_next_line(fd);
    }
    free(str);
    close(fd);
    return (lines_num);
}