/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:10:15 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/02/21 23:45:39 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_substr(char const *str, unsigned int start, size_t len);

int		ft_find(char c, char *str);
char	*ft_fill_stash(int fd, char *stash, int *new_line);
char	*ft_extract_line(char *stash, int new_line);
char	*ft_stash_plus(char *stash, int new_line);

char	*get_next_line(int fd);

#endif