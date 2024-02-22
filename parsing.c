/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:10:04 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/02/21 18:35:35 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_walls(char  **lines)
{
    int i;
    int j;
    int line_len;

    i = 0;
    line_len = ft_strlen(lines[i]);
    while(lines[i])
    {
        int j = 0;
        while(lines[i][j])
        {
            if (i == 0 && lines[i][j] != 1)
                return (0);
            if (j == 0 && lines[i][j] != 1)
                return (0);
            if (i == !lines[i + 1] && lines[i][j] != 1)
                return (0);
            if (j == line_len - 1 && lines[i][j] != 1)
                return (0);
        }
    }
}