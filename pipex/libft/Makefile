# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 15:33:44 by sbartoul          #+#    #+#              #
#    Updated: 2024/03/25 08:52:51 by sbartoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

SRCS = ft_bzero.c					\
		ft_atoi.c					\
		ft_calloc.c					\
		ft_isalnum.c				\
		ft_isalpha.c				\
		ft_isascii.c				\
		ft_isdigit.c				\
		ft_isprint.c				\
		ft_itoa.c					\
		ft_memchr.c					\
		ft_memcmp.c					\
		ft_memcpy.c					\
		ft_memmove.c				\
		ft_memset.c					\
		ft_putchar_fd.c				\
		ft_putendl_fd.c				\
		ft_putnbr_fd.c				\
		ft_putstr_fd.c				\
		ft_split.c					\
		ft_strchr.c					\
		ft_strdup.c					\
		ft_striteri.c				\
		ft_strjoin.c				\
		ft_strlcat.c				\
		ft_strlcpy.c				\
		ft_strlen.c					\
		ft_strmapi.c				\
		ft_strncmp.c				\
		ft_strnstr.c				\
		ft_strrchr.c				\
		ft_strtrim.c				\
		ft_substr.c					\
		ft_strcmp.c				\
		ft_tolower.c				\
		ft_toupper.c				\

SRCSBONUS = ft_lstnew.c					\
			ft_lstadd_front.c			\
			ft_lstsize.c				\
			ft_lstlast.c				\
			ft_lstadd_back.c			\
			ft_lstdelone.c				\
			ft_lstclear.c				\
			ft_lstiter.c				\
			ft_lstmap.c					\


OBJECTS = ${SRCS:.c=.o}
OBJECTSBONUS = ${SRCSBONUS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@printf $(UP)$(CUT)
	@echo $(Y)Compiling [$<]...$(X)
${NAME}: ${OBJECTS}
		@printf $(UP)$(CUT)
		@echo $(Y)Compiling [$(NAME)]...$(X)
		@ar -rcs $(NAME) $(OBJECTS)
		@ranlib $(NAME)
		@echo $(R)Finished [$(NAME)]$(X)
		@echo
bonus: ${NAME} ${OBJECTSBONUS}
		@printf $(UP)$(CUT)
		@echo $(Y)Compiling [$(NAME)]...$(X)
		@ar -rcs $(NAME) $(OBJECTSBONUS)
		@ranlib $(NAME)
		@echo $(R)Finished [$(NAME)]$(X)

all: ${NAME}
clean:
		@rm -f $(OBJECTS) $(OBJECTSBONUS)
		@echo $(R)Removed [$(OBJECTS)$(X)] [$(OBJECTSBONUS)$(X)]
fclean: clean
		@rm -f $(NAME)
		@echo $(R)Removed [$(NAME)]$(X)
re : fclean all

.PHONY: all clean fclean re
