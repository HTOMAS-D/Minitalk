# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 11:52:24 by htomas-d          #+#    #+#              #
#    Updated: 2022/04/08 10:08:23 by htomas-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_putchar.c ft_itoa.c ft_putsigned.c ft_putstr.c \
				ft_strlen.c ft_putunsigned.c ft_utoa.c ft_printf.c \
				ft_putptr.c ft_calloc.c ft_bzero.c ft_memset.c \
				ft_putex.c ft_putexup.c \

OBJS		= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.

NAME		= libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re
