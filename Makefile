CLIENT = client
SERVER = server
SRC_CLIENT	= client.c
SRC_SERVER	= server.c
OBJS_CLIENT	= $(SRC_CLIENT:.c=.o)
OBJS_SERVER	= $(SRC_SERVER:.c=.o)
INCS	= -Ilibft -L./libft -libft
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

%.o : %.c
		@$(CC) $(CCFLAGS) -c -o $@ $<

all : $(CLIENT)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all