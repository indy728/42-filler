.PHONY: all, $(NAME), test, clean, fclean, re

NAME= indy.filler

CC= gcc

CFLAGS+= -Wall -Wextra -Werror

SRC_PATH= src/
INC_PATH= includes/
OBJ_PATH= obj/
LIBFT_PATH= includes/libft/
PLAYER_PATH= resources/players/

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
INC_LFT = $(addprefix -I, $(addprefix $(LIBFT_PATH), $(INC_PATH)))

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_NAME = main.c parse_input.c place_piece.c build_heat_map.c\
		   debugger.c get_priorities.c

all: $(PLAYER_PATH)$(NAME)

$(PLAYER_PATH)$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFT_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(INC) $(INC_LFT) -o $@ -c $< 

test: $(OBJ)
	$(CC) -o $(PLAYER_PATH)$(NAME) $(OBJ) -L$(LIBFT_PATH) -lft

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(PLAYER_PATH)$(NAME)
	
re: fclean all
