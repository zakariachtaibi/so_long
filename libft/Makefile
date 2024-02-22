# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 16:25:01 by zchtaibi          #+#    #+#              #
#    Updated: 2023/11/20 20:06:51 by zchtaibi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

DEPS	= libft.h

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra -include $(DEPS)

ARCHIVE	= ar -rcs

SRCS	=    ft_bzero.c  ft_isalnum.c\
			 ft_isalpha.c ft_isascii.c\
			 ft_isdigit.c ft_isprint.c\
			 ft_memset.c  ft_strlen.c\
			 ft_memcpy.c ft_strlcpy.c\
			 ft_strlcat.c ft_toupper.c\
			 ft_tolower.c ft_strchr.c\
			 ft_strncmp.c ft_memchr.c\
			 ft_strrchr.c ft_memcmp.c\
			 ft_memmove.c ft_substr.c\
			 ft_strnstr.c ft_calloc.c\
			 ft_strdup.c ft_atoi.c\
			 ft_strjoin.c ft_putchar_fd.c\
			 ft_putstr_fd.c ft_putendl_fd.c\
			 ft_itoa.c ft_split.c\
			 ft_putnbr_fd.c ft_strmapi.c\
			 ft_striteri.c ft_strtrim.c\


OBJS	= $(SRCS:.c=.o)


B_SRCS	=	ft_lstlast.c ft_lstadd_back.c\
			ft_lstadd_front.c ft_lstnew.c\
			ft_lstsize.c ft_lstdelone.c\
			ft_lstclear.c ft_lstiter.c\
			ft_lstmap.c\


B_OBJS	= $(B_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
	$(ARCHIVE) $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS) $(B_OBJS)

fclean: clean
	rm -rf $(NAME)
	
$(B_OBJS) : ${B_SRCS}
	${CC} ${CFLAGS} -c ${B_SRCS}
	$(ARCHIVE) $(NAME) $(B_OBJS)
	
bonus: $(B_OBJS) 


rebonus: fclean bonus

re: fclean all

.PHONY: all clean fclean re
