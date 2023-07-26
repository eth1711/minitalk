NAME	= libft.a
SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
OBJS_DIR = objs/
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
LIBC	= ar r
CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Werror -Wextra

$(OBJS_DIR)%.o : %.c libft.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_PREFIXED)
	@$(LIBC) $(NAME) $(OBJS_PREFIXED)
	
all	: $(NAME)

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
		$(RM) $(NAME)

re : fclean all