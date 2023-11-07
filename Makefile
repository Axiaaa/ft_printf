NAME = libftprintf.a
LIBFT = ./libft/libft.a
CC = cc
SRC_PRINTF = ./objs/ft_printf.c ./objs/print_functions.c ./objs/print_ptr.c
SRC_LIBFT = ./libft/ft_atoi.c ./libft/ft_bzero.c ./libft/ft_isalnum.c ./libft/ft_isalpha.c ./libft/ft_isascii.c ./libft/ft_isdigit.c \
		./libft/ft_isprint.c ./libft/ft_itoa.c ./libft/ft_memset.c ./libft/ft_putchar_fd.c \
		./libft/ft_putendl_fd.c ./libft/ft_putnbr_fd.c ./libft/ft_strchr.c ./libft/ft_striteri.c \
		./libft/ft_putstr_fd.c ./libft/ft_strdup.c ./libft/ft_strjoin.c ./libft/ft_strlcat.c ./libft/ft_strlcpy.c ./libft/ft_strlen.c \
		./libft/ft_strmapi.c ./libft/ft_strncmp.c ./libft/ft_strnstr.c ./libft/ft_strrchr.c ./libft/ft_strtrim.c ./libft/ft_substr.c \
		./libft/ft_tolower.c ./libft/ft_toupper.c ./libft/ft_calloc.c ./libft/ft_memchr.c ./libft/ft_memcmp.c \
		./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_split.c \
		./libft/ft_lstadd_back.c ./libft/ft_lstadd_front.c ./libft/ft_lstclear.c ./libft/ft_lstdelone.c \
		./libft/ft_lstiter.c ./libft/ft_lstlast.c ./libft/ft_lstmap.c ./libft/ft_lstnew.c ./libft/ft_lstsize.c
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)
FLAGS = -Wall -Wextra
DIR = ./objs
HEADER = ft_printf.h
HEADER_LIBFT = ./libft/libft.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_PRINTF)
	ar rcs $(NAME) $(OBJ_PRINTF) $(LIBFT)
	@echo "\033[33m[FT_PRINTF]\033[0m \033[32m$(NAME) created !\033[0m"

$(DIR)/%.o: %.c | $(DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT): $(SRC_LIBFT)
	make -C ./libft/

$(DIR):
	mkdir -p $(DIR)

$(OBJ_PRINTF): $(HEADER)
$(LIBFT): $(HEADER_LIBFT)

clean:
	rm -rf $(DIR)
	@echo "\033[33m[FT_PRINTF]\033[0m \033[31mObjects deleted !\033[0m"
	make -C ./libft/ clean

fclean: clean
	rm -f $(NAME)
	@echo "\033[33m[FT_PRINTF]\033[0m \033[31mlibftprintf.a deleted !\033[0m"
	make -C ./libft/ fclean

re: fclean all

.PHONY : all clean fclean re