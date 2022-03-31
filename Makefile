NAME = fractol
CC = gcc
FLAGS = -Wall -Werror -Wextra 
# -lmlx -framework OpenGL -framework AppKit
#LIBFT = ./libft
LIB = ./libft/libft.a
MLX = ./minilibx-linux/libmlx.a
LIBRARIES = -L/usr/X11R6/lib  -lmlx -lX11 -lXext -framework OpenGL -framework AppKit -L ./libft/ -L ./minilibx-linux/
#LIBRARIES = -lmlx -framework OpenGL -framework AppKit $(LIB) $(MLX)
#LIBRARIES = -lmlx -framework OpenGL -framework AppKit -L ./libft/ -L ./minilibx-linux/
#LIBRARIES = -Lmlx -lmlx -framework OpenGL -framework AppKit -L ./libft/ -L ./minilibx-linux/ 
#MLX_HEADERS = ./minilibx-linux
SRC = ./srcs/main.c 
#			./srcs/fractol.c \
			./srcs/init.c \
			./srcs/draw.c \
			./srcs/mandelbrot.c \
			./srcs/julia.c \
			./srcs/burning_ship.c \
			./srcs/color.c \
			./srcs/keyboard.c \
			./srcs/mouse.c \
			./srcs/utils.c
BONUS_SRC = ./srcs/main.c
#OBJ_D = objs/
#OBJ_LIST = $(patsubst %.c, %.o, $(SRC))
#OBJ	= $(addprefix $(OBJ_D), $(OBJ_LIST))
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
HEAD = -I ./includes
RM = rm -f
ifdef BONUS_ON
#NAME = $(BONUS_NAME)
SRC = $(BONUS_SRC)
OBJ = $(BONUS_OBJ)
endif

all : $(NAME)

$(NAME) : $(LIB) $(MLX) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBRARIES) -o $(NAME)
	@echo "$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

#$(NAME) : $(OBJ) $(LIB)
#	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME) -g

.c.o :
#	$(CC) $(FLAGS) -lmlx -c $< -o $(<:.c=.o) $(HEAD) -g
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) $(HEAD)

$(LIB) : 
	@echo "$(NAME): $(GREEN)Creating $(LIB)...$(RESET)"
	$(MAKE) -sC ./libft

$(MLX) :
	@echo "$(NAME): $(GREEN)Creating $(MLX)...$(RESET)"
	$(MAKE) -sC ./minilibx-linux 2>/dev/null

clean :
	$(MAKE) clean -sC ./libft
	$(RM) $(OBJ) $(BONUS_OBJ)
#	@rm -rf $(OBJ_DIRECTORY)
#	@echo "$(NAME): $(RED)$(OBJ_D) was deleted$(RESET)"
	@echo "$(NAME): $(GREEN)object files were deleted$(RESET)"

fclean : clean
	$(MAKE) fclean -sC ./libft
#	@echo "$(NAME): $(RED)$(LIB) was deleted$(RESET)"
	$(MAKE) clean -sC ./minilibx-linux
#	@echo "$(NAME): $(RED)$(MLX) was deleted$(RESET)"
	$(RM) $(NAME) $(BONUS_NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was deleted$(RESET)"

re : fclean all

bonus :
	$(MAKE) BONUS_ON=1

.PHONY: all clean fclean re bonus
