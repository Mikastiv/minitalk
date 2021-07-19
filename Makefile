# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 11:52:24 by mleblanc          #+#    #+#              #
#    Updated: 2021/07/19 12:54:02 by mleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		=	client
SERVER		=	server

SRC			=	src
INC			=	include
OBJ			=	obj

HFILES		=	utils.h
HEADERS		=	$(addprefix $(INC)/, $(HFILES))

CFILES_C	=	client.c utils.c
OFILES_C	=	$(CFILES_C:.c=.o)
OBJS_C		=	$(addprefix $(OBJ)/, $(OFILES_C))

CFILES_S	=	server.c utils.c
OFILES_S	=	$(CFILES_S:.c=.o)
OBJS_S		=	$(addprefix $(OBJ)/, $(OFILES_S))

SRCS		=	$(addprefix $(SRC)/, $(CFILES_C))
SRCS		+=	$(addprefix $(SRC)/, $(CFILES_S))

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

$(OBJ)/%.o:	$(SRC)/%.c
			$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(CLIENT):	$(OBJ) $(OBJS_C)
			$(CC) $(OBJS_C) -o $(CLIENT)

$(SERVER):	$(OBJ) $(OBJS_S)
			$(CC) $(OBJS_S) -o $(SERVER)

$(OBJ):
			@mkdir -p $(OBJ)

all:		$(CLIENT) $(SERVER)

clean:
			@$(RM) $(OBJS_C) $(OBJS_S)

fclean:		clean
			@$(RM) $(CLIENT) $(SERVER)

re:			fclean all

bonus:		all

norme:
			norminette $(SRCS) $(HEADERS)

.PHONY:		all clean fclean re norme bonus
