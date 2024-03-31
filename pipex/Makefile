NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = pipex.c\
       utils.c\
       libft/libft.a\

$(NAME) :
	make all -C libft
	cc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

