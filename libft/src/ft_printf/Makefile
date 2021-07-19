# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 16:37:00 by mleblanc          #+#    #+#              #
#    Updated: 2021/07/14 18:07:41 by mleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC		=	../../
OBJ		=	../../obj
HFILES	=	convert.h do_printf.h flags.h utils.h
OFILES	=	$(CFILES:.c=.o)
HEADERS	=	$(addprefix include/, $(HFILES))
OBJS	=	$(addprefix $(OBJ)/, $(OFILES))

$(OBJ)/%.o:	%.c
			$(CC) $(CFLAGS) -I$(INC) -Iinclude -c $< -o $@

all:		$(OBJS)
			@echo > /dev/null

clean:
			@$(RM) $(OBJS)

re:			clean all

norme:
			$(NM) $(CFILES)

.PHONY:	all clean re norme