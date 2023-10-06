NAME = libftprintf.a
LIBFT = ./libft/libft.a
CC = cc
SRC = ./objs/ft_printf.c ./objs/print_functions.c ./objs/print_ptr.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
DIR = ./objs
HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) 
	ar rcs $(NAME) $(OBJ) $(LIBFT)
	@echo "\033[32m$(NAME) created !\033[0m"

$(DIR)/%.o: %.c | $(DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(DIR):
	mkdir -p $(DIR)

$(OBJ): $(HEADER)

$(LIBFT):
	make -C ./libft/

clean:
	rm -rf $(DIR)
	rm -f $(OBJ_BONUS)
	@echo "\033[31mObjects deleted !\033[0m" 

fclean: clean
	rm -f $(NAME)
	make -C ./libft/ fclean
	@echo "\033[33m$(NAME) deleted !\033[0m"

re: fclean all