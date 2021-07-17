# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 11:52:24 by mleblanc          #+#    #+#              #
#    Updated: 2021/07/17 12:16:41 by mleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		=	client
SERVER		=	server

LIBFT		=	ft
LIBFTDIR	=	libft
MAKELIBFT	=	@$(MAKE) -C $(LIBFTDIR)

SRC			=	src
INC			=	include
OBJ			=	obj

HFILES		=	
HEADERS		=	$(addprefix $(INC)/, $(HFILES))

CFILES_C	=	client.c
OFILES_C	=	$(CFILES_C:.c=.o)
OBJS_C		=	$(addprefix $(OBJ)/, $(OFILES_C))

CFILES_S	=	server.c
OFILES_S	=	$(CFILES_S:.c=.o)
OBJS_S		=	$(addprefix $(OBJ)/, $(OFILES_S))

SRCS		=	$(addprefix $(SRC)/, $(CFILES_C))
SRCS		+=	$(addprefix $(SRC)/, $(CFILES_S))

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -rf

$(OBJ)/%.o:	$(SRC)/%.c
			$(CC) $(CFLAGS) -I$(LIBFTDIR) -I$(INC) -c $< -o $@

$(CLIENT):	$(OBJ) $(OBJS_C)
			$(MAKELIBFT)
			$(CC) $(OBJS_C) -L$(LIBFTDIR) -l$(LIBFT) -o $(CLIENT)

$(SERVER):	$(OBJ) $(OBJS_S)
			$(MAKELIBFT)
			$(CC) $(OBJS_S) -L$(LIBFTDIR) -l$(LIBFT) -o $(SERVER)

$(OBJ):
			@mkdir -p $(OBJ)

all:		$(CLIENT) $(SERVER)

clean:
			$(MAKELIBFT) fclean
			@$(RM) $(OBJS_C) $(OBJS_S)

fclean:		clean
			@$(RM) $(CLIENT) $(SERVER)

re:			fclean all

norme:
			$(MAKELIBFT) norme
			norminette $(SRCS) $(HEADERS)

.PHONY:		all clean fclean re norme
