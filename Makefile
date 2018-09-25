NAME = wolf3d
COMP = gcc
FLAGS = -Wall -Werror -Wextra -std=c99 -ggdb3
LIB_G = -lm -L libft/ -lft
FUNCS = main \
		map_read \
		calculations \
		ray_cast \
		keys \
		movement \
		colours \
		error \
		
SRCC = $(addsuffix .c, $(FUNCS))
SRCO = $(addsuffix .o, $(FUNCS))

HF = libft/libft.h
LIB = ./libft/libft.a
INCLUDES = -I./libft

all: $(NAME)
$(NAME):	$(SRCO)
	@make -C libft
	@$(COMP) $(FLAGS) -I $(LIB) -c $(SRCC)
	@$(COMP) -o $(NAME) $(SRCO) $(LIB_G) -lSDL2 -I ~/.brew/include -L ~/.brew/lib
clean:
	@make -C libft/ clean
	rm -f $(SRCO)

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
