# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lade-kon <lade-kon@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/02/23 17:43:35 by lade-kon      #+#    #+#                  #
#    Updated: 2024/04/17 19:19:48 by lade-kon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		:=	so_long

CC			:=	cc -Ofast -g
CFLAGS		:=	-Wall -Werror -Wextra -g -fsanitize=address

LIBFT_DIR	:=	lib/libft
LIBFT_A		:=	$(LIBFT_DIR)/libft.a
MLX_DIR		:=	lib/MLX42
MLX42_A		:=	$(MLX_DIR)/build/libmlx42.a
MLX_FLAGS	:=	-ldl -lglfw -pthread -lm

INCLS_SO_LONG:=	incl
INCLS_LIBFT	:=	$(LIBFT_DIR)/incl
INCLS_MLX42	:=	$(MLX_DIR)/include/MLX42
INCLUDES	:=	-I $(INCLS_SO_LONG) -I $(INCLS_LIBFT) -I $(INCLS_MLX42)

SRC_DIR		:=	src
SRC_FILES	:=	so_long.c \
				check_file.c \
				check_map.c \
				error.c \
				map_utils.c \
				initialize_data.c \
				flood_fill.c \
				images.c \
				render_map.c \
				movement.c \
				utils.c \
				hooks.c
SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR		:=	obj
OBJ_FILES	:=	$(SRC_FILES:.c=.o)
OBJ			:=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

.PHONY : all clean fclean re

all: $(NAME)

$(MLX42_A):
	@git submodule update --init --recursive --remote
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build > /dev/null
	@make -C $(MLX_DIR)/build -j4 > /dev/null

$(LIBFT_A):
	@git submodule update --init --recursive --remote
	@make -C $(LIBFT_DIR) > /dev/null

$(NAME) : $(OBJ) $(MLX42_A) $(LIBFT_A)
	@$(CC) $(OBJ) $(CFLAGS) $(INCLUDES) $(MLX42_A) $(LIBFT_A) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

norminette:
	@echo "${CYAN}🧐 Checking the Norm...${RESET}"
	@norminette -R CheckForbiddenSourceHeader
	@echo "${GREEN} Norm-i-netting complete. Files are NORM PROOF!${RESET}" 

update:
	@git submodule update --init --recursive --remote
	
clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean > /dev/null

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean > /dev/null

re: fclean all

## Colours ##
RESET	:= \033[0m
RED		:= \033[1;91m
GREEN	:= \033[1;92m
YELLOW	:= \033[1;93m
BLUE	:= \033[1;94m
PURPLE	:= \033[1;95m
CYAN	:= \033[1;96m
WHITE	:= \033[1;97m
BLACK	:= \033[1;90m