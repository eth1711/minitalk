CLIENT = client
SERVER = server
SRC_CLIENT	= client.c
SRC_SERVER	= server.c
OBJS_CLIENT	= $(SRC_CLIENT:.c=.o)
OBJS_SERVER	= $(SRC_SERVER:.c=.o)
INCS	= -Ilibft -L./libft -lft
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

$(CLIENT) : $(OBJS_CLIENT) $(SERVER)
		@$(CC) $(CCFLAGS) $(INCS) $(OBJS_CLIENT) -o $@

$(SERVER) : $(OBJS_SERVER)
		@make -C ./libft
		@$(CC) $(CCFLAGS) $(INCS) $(OBJS_SERVER) -o $@ 

%.o : %.c
		@$(CC) $(CCFLAGS) -c -o $@ $<

all : $(CLIENT)

clean : 
	@make clean -C ./libft
	@$(RM) *.o

fclean : clean
	@make fclean -C ./libft
	@$(RM) $(CLIENT) $(SERVER)

re : fclean 
		make

.PHONY: all clean fclean re