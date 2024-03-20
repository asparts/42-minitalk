NAME = minitalk

CFLAGS =	-Wall -Wextra -Werror

LIBFT = libft.a

LIBFTDIR = ./libft

FTPRINTF = libftprintf.a

FTPRINTFDIR = ./ftprintf

CLIENT = client

SERVER = server

all: $(NAME)

$(SERVER): $(LIBFT)
	@cc $(CFLAGS) -o $(SERVER) $(SERVER).c $(LIBFT) $(FTPRINTF)

$(CLIENT): $(LIBFT)
	@cc $(CFLAGS) -o $(CLIENT) $(CLIENT).c $(LIBFT) $(FTPRINTF)

$(LIBFT): $(FTPRINTF)
	@make -s -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFT) .

$(FTPRINTF):
	@make -s -C $(FTPRINTFDIR)
	@cp $(FTPRINTFDIR)/$(FTPRINTF) .

$(NAME): $(SERVER) $(CLIENT)

clean:
	@rm -rf $(LIBFT)
	@make -s fclean -C $(LIBFTDIR)
	@rm -rf $(FTPRINTF)
	@make -s fclean -C $(FTPRINTFDIR)
	@rm client
	@rm server

fclean: clean

re:	fclean all

.PHONY: all clean fclean re
