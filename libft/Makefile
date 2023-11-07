NAME = libft.a
CC = cc
SRC =   ./objs/ft_atoi.c ./objs/ft_bzero.c ./objs/ft_isalnum.c ./objs/ft_isalpha.c ./objs/ft_isascii.c ./objs/ft_isdigit.c \
		./objs/ft_isprint.c ./objs/ft_itoa.c ./objs/ft_memset.c ./objs/ft_putchar_fd.c \
		./objs/ft_putendl_fd.c ./objs/ft_putnbr_fd.c ./objs/ft_strchr.c ./objs/ft_striteri.c \
		./objs/ft_putstr_fd.c ./objs/ft_strdup.c ./objs/ft_strjoin.c ./objs/ft_strlcat.c ./objs/ft_strlcpy.c ./objs/ft_strlen.c \
		./objs/ft_strmapi.c ./objs/ft_strncmp.c ./objs/ft_strnstr.c ./objs/ft_strrchr.c ./objs/ft_strtrim.c ./objs/ft_substr.c \
		./objs/ft_tolower.c ./objs/ft_toupper.c ./objs/ft_calloc.c ./objs/ft_memchr.c ./objs/ft_memcmp.c \
		./objs/ft_memcpy.c ./objs/ft_memmove.c ./objs/ft_split.c ./objs/ft_lstadd_back.c ./objs/ft_lstadd_front.c ./objs/ft_lstclear.c ./objs/ft_lstdelone.c \
		./objs/ft_lstiter.c ./objs/ft_lstlast.c ./objs/ft_lstmap.c ./objs/ft_lstnew.c ./objs/ft_lstsize.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
DIR = ./objs
HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ) 
	ar rcs $(NAME) $(OBJ)
	@echo "\033[34m[LIBFT]\033[0m \033[32m$(NAME) created !\033[0m"

$(DIR)/%.o: %.c | $(DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(DIR):
	mkdir -p $(DIR)

$(OBJ): $(HEADER)


clean:
	rm -rf $(DIR)
	@echo "\033[34m[LIBFT]\033[0m \033[31mObjects deleted !\033[0m" 

fclean: clean
	rm -f $(NAME)
	@echo "\033[34m[LIBFT]\033[0m \033[31m$(NAME) deleted !\033[0m"

re: fclean all

.PHONY: all clean fclean re

