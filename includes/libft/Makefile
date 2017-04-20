NAME= libft.a

CC= gcc
CFLAGS+= -Wall -Werror -Wextra

SRCS_PATH= ./libft_src/
PF_PATH= ./pf_src/

SRC_NAME+= ft_itoa.c ft_memdup.c ft_strcmp.c ft_strncpy.c ft_lltoa_base.c\
		   ft_memmove.c ft_strcpy.c ft_strnequ.c ft_atoi.c ft_lstadd.c ft_memset.c\
		   ft_strdel.c ft_strnew.c ft_base_char.c ft_lstdel.c ft_putchar.c\
		   ft_strdup.c ft_strnstr.c ft_bzero.c ft_lstdelone.c ft_putchar_fd.c\
		   ft_strequ.c ft_strrchr.c ft_count_base.c ft_lstiter.c ft_putendl.c\
		   ft_striter.c ft_strsplit.c ft_endspaces.c ft_lstmap.c ft_putendl_fd.c\
		   ft_striteri.c ft_strstr.c ft_count_words.c ft_lstnew.c ft_putnbr.c\
		   ft_strjoin.c ft_strsub.c ft_isalnum.c ft_memalloc.c ft_putnbr_fd.c\
		   ft_strlcat.c ft_strtrim.c ft_isalpha.c ft_memccpy.c ft_putstr.c\
		   ft_strlen.c ft_tolower.c ft_isascii.c ft_memchr.c ft_putstr_fd.c\
		   ft_strmap.c ft_toupper.c ft_isdigit.c ft_memcmp.c ft_strcat.c\
		   ft_strmapi.c ft_wordlen.c ft_isprime.c ft_memcpy.c ft_strchr.c\
		   ft_strncat.c ft_isprint.c ft_memdel.c ft_strclr.c ft_strncmp.c\
		   ft_power_of.c ft_max.c ft_min.c ft_iswhitespace.c ft_strmove.c\
		   ft_strlchr.c ft_freezero.c ft_lstpop.c ft_lstcat.c ft_putlchar.c\
		   ft_putlstr.c ft_putlnbr.c ft_putlnbr_fd.c ft_abs.c\
		   ft_maxtoa_base.c ft_umaxtoa_base.c ft_countu_base.c\
		   ft_toupperstr.c ft_lstadd_back.c\
		   get_next_line.c

PF_SRC_NAME= ft_printf.c char_at_x.c parse_flags.c\
				parse_fw.c parse_precision.c parse_specifier.c print_mods.c\
				parse_length.c validate_mods.c validate_flags.c\
				get_udecimal.c make_decimalstr.c make_stringstr.c make_pointerstr.c\
				make_octalstr.c make_hexstr.c\
				add_precision.c add_padding.c

SRC = $(addprefix $(SRCS_PATH),$(SRC_NAME))

OBJ_PATH = ./obj/

OBJ_NAME = $(SRC_NAME:.c=.o)\
	$(PF_SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC_PATH = ./includes/
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c 
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH)%.o: $(PF_PATH)%.c 
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	@ar -rc $(NAME) $?
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
