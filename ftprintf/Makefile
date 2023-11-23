CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libftprintf.a
SRCS	=	ft_printf.c ft_putchr.c ft_putstr.c ft_print_args.c ft_strcpy.c ft_print_int.c ft_print_hex.c ft_print_unsigned.c ft_print_ptr.c ft_memcpy.c ft_strlen.c ft_hex_len.c

OBJS	=	${SRCS:.c=.o}

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)
clean:
		$(RM) $(OBJS)
fclean:		clean
		$(RM) $(NAME)
re:		fclean $(NAME)

.PHONY:		all clean fclean re
