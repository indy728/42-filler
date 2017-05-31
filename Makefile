# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmurray <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/30 22:47:55 by kmurray           #+#    #+#              #
#    Updated: 2017/05/31 00:50:08 by kmurray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), test, clean, fclean, re

NAME= filler

CC= gcc

CFLAGS+= -Wall -Wextra -Werror

SRC_PATH= src/
INC_PATH= includes/
OBJ_PATH= obj/
LIBFT_PATH= includes/libft/

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
INC_LFT = $(addprefix -I, $(addprefix $(LIBFT_PATH), $(INC_PATH)))

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_NAME = main.c parse_input.c place_piece.c build_heat_map.c\
		   print_heat_map.c get_priorities.c clean_structs.c choke.c\
		   print_map.c

all: $(PLAYER_PATH)$(NAME)

$(PLAYER_PATH)$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFT_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(INC) $(INC_LFT) -o $@ -c $< 

test: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L$(LIBFT_PATH) -lft

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
	
re: fclean all
