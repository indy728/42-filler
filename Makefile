.PHONY: all, $(NAME), test, clean, fclean, re

NAME= fdf

CC= cc

GRAPHICS_FLAGS+= -framework OpenGL -framework AppKit

SRC_PATH= src/
INC_PATH= includes/
OBJ_PATH= obj/
LIBFT_PATH= includes/libft/
MLX_PATH= includes/minilibx/

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
INC_MLX = $(addprefix -I, $(MLX_PATH))
INC_LFT = $(addprefix -I, $(addprefix $(LIBFT_PATH), $(INC_PATH)))

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_NAME = main.c getx.c gety.c wf_draw_line.c

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	$(CC) -o $(NAME) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx $(GRAPHICS_FLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(INC) $(INC_MLX) $(INC_LFT) -o $@ -c $< 

test: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx $(GRAPHICS_FLAGS)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
	
re: fclean all
