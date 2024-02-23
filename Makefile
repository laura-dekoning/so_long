# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lade-kon <lade-kon@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/02/23 17:43:35 by lade-kon      #+#    #+#                  #
#    Updated: 2024/02/23 17:46:14 by lade-kon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC			:=	cc
CFLAGS		:=	-Wall -Werror -Wextra

INCL		:=	so_long.h

SRC_FILES	:=	

OBJ_DIR		:=	obj
OBJ_FILES	:=	$(addprefix obj/, $(SRC_FILES:.c=.o))

NAME		:=	libft.a

.PHONY : all clean fclean re

all: $(NAME)

$(NAME) : $(OBJ_FILES) $(INCL)
	ar -rcs $(NAME) $?

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(addprefix $(OBJ_DIR)/, $(DIRS))
	@mkdir -p $(addprefix $(OBJ_DIR)/$(LIBFT_DIR)/, $(SRC_DIRS))
	$(CC) $(CFLAGS) -I $(INCL_DIR) -c $< -o $@ 

norminette:
	@echo "${CYAN}🧐 Checking the Norm...${RESET}"
	@norminette -R CheckForbiddenSourceHeader
	@echo "${GREEN} Norm-i-netting complete. Files are NORM PROOF!${RESET}" 

clean:
	rm -rf $(OBJ_FILES)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

## Colours ##
RESET		:= \033[0m
RED			:= \033[1;91m
GREEN		:= \033[1;92m
YELLOW		:= \033[1;93m
BLUE		:= \033[1;94m
PURPLE		:= \033[1;95m
CYAN		:= \033[1;96m
WHITE		:= \033[1;97m
BLACK		:= \033[1;90m