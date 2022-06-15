# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 14:20:13 by htomas-d          #+#    #+#              #
#    Updated: 2022/06/15 13:26:42 by htomas-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRCS		=	server.c 

CLIENT_SRCS		=	client.c  

LIBFT_SRCS   =  ft_printf.c ft_bzero.c ft_calloc.c ft_itoa.c ft_memset.c ft_putchar.c \
				ft_putex.c ft_putexup.c ft_putptr.c ft_putsigned.c ft_putstr.c ft_uitoa.c \
				ft_putunsigned.c ft_strlen.c

SERVER_OBJS   =  $(addprefix objs/,$(SERVER_SRCS:.c=.o))

CLIENT_OBJS   =  $(addprefix objs/,$(CLIENT_SRCS:.c=.o))

LIBFT_OBJS   =  $(addprefix objs/,$(LIBFT_SRCS:.c=.o))

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

SERVER		= server

CLIENT		= client

objs/%.o: srcs/%.c
			@mkdir -p objs/
			$(CC) $(CFLAGS) -c $< -o $@

objs/%.o: libft_srcs/%.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(SERVER) $(CLIENT)
			@echo "$(GREEN)Ricky $(YELLOW)Makefiles$(DEFAULT)"

$(SERVER):	$(SERVER_OBJS) $(LIBFT_OBJS)
			$(CC) -o $(SERVER) $(SERVER_OBJS) $(LIBFT_OBJS)
			@echo "\033[106m                       \033[0m"
			@echo "$(GREEN)Successfully Built Server$(DEFAULT)"
			@echo "\033[106m                       \033[0m"

$(CLIENT):	$(CLIENT_OBJS) $(LIBFT_OBJS)
			$(CC) -o $(CLIENT) $(CLIENT_OBJS) $(LIBFT_OBJS)
			@echo "\033[106m                       \033[0m"
			@echo "$(GREEN)Successfully Built Client$(DEFAULT)"
			@echo "\033[106m                       \033[0m"

clean:
			@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(LIBFT_OBJS)

fclean:		clean
			@$(RM) $(SERVER) $(CLIENT)
			@echo "$(RED)Files Removed$(DEFAULT)"

re:			fclean all

.PHONY:		all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
