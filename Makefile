# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ihering- <ihering-@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 11:12:08 by ivan-tey       #+#    #+#                 #
#    Updated: 2019/06/06 13:24:55 by ivan-tey      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf
S = ./
H = ./
SRC = main.c valid.c values.c fdf.c draw.c slopes.c controls.c colours.c \
	menu.c
OBJ = $(SRC:%.c=%.o)
HDR = fdf.h libft/includes/libft.h
MINILIBX = -I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit
LIB = -I libft/includes -L libft -lft
FLAGS = -Wall -Werror -Wextra

LIGHTER_PINK = \033[38;5;212m
LIGHT_PINK = \033[38;5;225m
DARK_PINK = \033[38;5;205m
DARKER_PINK = \033[38;5;162m
RESET = \033[0m

all: $(NAME)

$(NAME): $(SRC)
	@make -C minilibx/
	@make -C libft/
	@echo "$(DARK_PINK)Building the IKEA cupboards for the library$(RESET)"
	@gcc $(FLAGS) -I minilibx -I libft/includes -c $(SRC)
	@gcc -o $(NAME) $(OBJ) $(LIB) $(MINILIBX)
	@echo "$(DARKER_PINK)Printing pretty pink pixels$(RESET)"

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C minilibx/
	@make clean -C libft/
	@echo "$(LIGHT_PINK)Making it all clean and tidy$(RESET)"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/
	@echo "$(LIGHTER_PINK)Making it all super clean and super tidy$(RESET)"

re: fclean all