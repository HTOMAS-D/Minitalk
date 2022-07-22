# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 14:20:13 by htomas-d          #+#    #+#              #
#    Updated: 2022/07/22 14:17:33 by htomas-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRCS		=	srcs/server.c 

CLIENT_SRCS		=	srcs/client.c  

LIBFT		= -Llibft -lft

LIBFTA		= ./libft/libftprintf.a

LIBFT_PATH	= ./libft

SERVER_OBJS   =  $(addprefix objs/,$(SERVER_SRCS:.c=.o))

CLIENT_OBJS   =  $(addprefix objs/,$(CLIENT_SRCS:.c=.o))

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

SERVER		= server

CLIENT		= client

objs/%.o: srcs/%.c
			@mkdir -p objs/
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(SERVER) $(CLIENT)
			@echo "$(GREEN)Ricky $(YELLOW)Makefiles$(DEFAULT)"

$(SERVER):	$(LIBFTA)
			$(CC) $(CFLAGS) $(SERVER_SRCS) $(LIBFTA) -o $(SERVER)
			@echo "\033[106m                       \033[0m"
			@echo "$(GREEN)Successfully Built Server$(DEFAULT)"
			@echo "\033[106m                       \033[0m"

$(CLIENT):	$(LIBFTA)
			$(CC) $(CFLAGS) $(CLIENT_SRCS) $(LIBFTA) -o $(CLIENT)
			@echo "\033[106m                       \033[0m"
			@echo "$(GREEN)Successfully Built Client$(DEFAULT)"
			@echo "\033[106m                       \033[0m"

clean:
			@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean:		clean
			@$(RM) $(SERVER) $(CLIENT)
			@echo "$(RED)Files Removed$(DEFAULT)"
			make -C libft fclean

re:			fclean all

$(LIBFTA): $(shell make -C $(LIBFT_PATH) -q libftprintf.a)
	make -C	$(LIBFT_PATH)

.PHONY:		all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
