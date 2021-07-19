# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 13:43:15 by mleblanc          #+#    #+#              #
#    Updated: 2021/07/14 18:05:48 by mleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ		=	obj
NAME	=	libft.a
CC		=	clang
LIBC	=	ar rcs
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -rf
NM		=	norminette

CHAR_SRC	=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c\
				ft_isprint.c ft_isspace.c ft_isupper.c ft_tolower.c ft_toupper.c
CONV_SRC	=	ft_atoi.c ft_atol.c ft_float_len.c ft_ftoa.c ft_itoa_base.c\
				ft_itoa.c ft_lltoa_base.c ft_lltoa.c ft_ltoa_base.c ft_ltoa.c\
				ft_ntoa_base.c ft_ntoa.c ft_numlen.c ft_ptoa_base.c ft_ptoa.c\
				ft_ulltoa_base.c ft_ulltoa.c ft_ultoa_base.c ft_ultoa.c\
				ft_untoa_base.c ft_untoa.c ft_unumlen.c ft_utoa_base.c ft_utoa.c
FILE_SRC	=	count_lines.c get_next_line.c
LIST_SRC	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstany.c ft_lstclear.c\
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c\
				ft_lstsize.c
MEM_SRC		=	ft_bzero.c ft_calloc.c ft_free.c ft_memccpy.c ft_memchr.c\
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c
PRINT_SRC	=	convert_char.c convert_float.c convert_int.c convert_n.c\
				convert_num_utils.c convert_percent.c convert_ptr.c convert_str.c\
				convert_uint.c convert.c do_printf.c ft_printf.c utils.c
PUT_SRC		=	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_base_fd.c ft_putnbr_fd.c\
				ft_putstr_fd.c ft_putunbr_base_fd.c ft_putwchar_fd.c\
				ft_putwstr_fd.c
STR_SRC		=	ft_split.c ft_str_any.c ft_str_count_if.c ft_str_foreach.c\
				ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnlen.c ft_strnstr.c\
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_wchar_size.c\
				ft_wstr_size.c ft_wstrlen.c ft_wstrnlen.c

OFILES	=	$(CHAR_SRC:.c=.o) $(CONV_SRC:.c=.o) $(FILE_SRC:.c=.o) $(LIST_SRC:.c=.o)\
			$(MEM_SRC:.c=.o) $(PRINT_SRC:.c=.o) $(PUT_SRC:.c=.o) $(STR_SRC:.c=.o)
OBJS	=	$(addprefix $(OBJ)/, $(OFILES))

ARGS		=	CC="$(CC)" CFLAGS="$(CFLAGS)" RM="$(RM)" NM="$(NM)"
MAKE_CHAR	=	@$(MAKE) -C src/ft_char $(ARGS) CFILES="$(CHAR_SRC)"
MAKE_CONV	=	@$(MAKE) -C src/ft_convert $(ARGS) CFILES="$(CONV_SRC)"
MAKE_FILE	=	@$(MAKE) -C src/ft_file $(ARGS) CFILES="$(FILE_SRC)"
MAKE_LIST	=	@$(MAKE) -C src/ft_list $(ARGS) CFILES="$(LIST_SRC)"
MAKE_MEM	=	@$(MAKE) -C src/ft_memory $(ARGS) CFILES="$(MEM_SRC)"
MAKE_PRINT	=	@$(MAKE) -C src/ft_printf $(ARGS) CFILES="$(PRINT_SRC)"
MAKE_PUT	=	@$(MAKE) -C src/ft_put $(ARGS) CFILES="$(PUT_SRC)"
MAKE_STR	=	@$(MAKE) -C src/ft_string $(ARGS) CFILES="$(STR_SRC)"

$(NAME):	$(OBJ)
			$(MAKE_CHAR) all
			$(MAKE_CONV) all
			$(MAKE_FILE) all
			$(MAKE_LIST) all
			$(MAKE_MEM) all
			$(MAKE_PRINT) all
			$(MAKE_PUT) all
			$(MAKE_STR) all
			$(LIBC) $(NAME) $(OBJS)


$(OBJ):
			@mkdir -p $(OBJ)

norme:
			$(MAKE_CHAR) norme
			$(MAKE_CONV) norme
			$(MAKE_FILE) norme
			$(MAKE_LIST) norme
			$(MAKE_MEM) norme
			$(MAKE_PRINT) norme
			$(MAKE_PUT) norme
			$(MAKE_STR) norme
			norminette libft.h

all:		$(NAME)

clean:
			$(MAKE_CHAR) clean
			$(MAKE_CONV) clean
			$(MAKE_FILE) clean
			$(MAKE_LIST) clean
			$(MAKE_MEM) clean
			$(MAKE_PRINT) clean
			$(MAKE_PUT) clean
			$(MAKE_STR) clean
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re norme