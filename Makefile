NAME = fractol
CC = gcc
FLAGS = -Wall -Werror -Wextra 
LIB = ./libft/libft.a
MLX = ./minilibx-linux/libmlx.a
MLX_PATH := ./minilibx-linux
#for Mac
#LIBRARIES = -lmlx -lX11 -lXext -framework OpenGL -framework AppKit -L ./minilibx-linux/
LIBRARIES = -L/usr/X11R6/lib -lm -lmlx -lX11 -lXext -framework OpenGL -framework AppKit -L ./minilibx-linux/
#for xubuntu
#LIBRARIES = -lm -lmlx -lX11 -lXext -L ./minilibx-linux/
#LIBRARIES = -L/usr/X11R6/lib -lm -lmlx -lX11 -lXext -L ./minilibx-linux/
#-L ./libft/ -L ./minilibx-linux/
SRC = ./srcs/main.c \
			./srcs/ft_init_data.c \
			./srcs/ft_draw_mandelbrot.c \
			./srcs/ft_draw_julia.c \
			./srcs/ft_key_down_hook.c \
			./srcs/ft_mouse_hook.c \
			./srcs/ft_rgb_to_hex.c \
			./srcs/ft_destroy.c

BONUS_SRC = ./srcs/main_bonus.c \
			./srcs/ft_init_data.c \
			./srcs/ft_draw_mandelbrot.c \
			./srcs/ft_draw_julia.c \
			./srcs/ft_key_down_hook.c \
			./srcs/ft_mouse_hook.c \
			./srcs/ft_rgb_to_hex.c \
			./srcs/ft_destroy.c \
			./srcs/ft_draw_burningship_bonus.c 

GREEN = \033[0;32m
RESET = \033[0m
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
HEAD = -I ./includes/
RM = rm -f

ifdef BONUS_ON
SRC = $(BONUS_SRC)
OBJ = $(BONUS_OBJ)
endif

all : $(NAME)

$(NAME) : $(LIB) $(MLX_PATH) $(MLX) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBRARIES) $(LIB) $(MLX) -o $(NAME)
	@echo "$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(MLX_PATH) :
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_PATH)
	make -C $(MLX_PATH)

.c.o :
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
	@echo "$(NAME): $(GREEN)object files were deleted$(RESET)"

fclean : clean
	$(MAKE) fclean -sC ./libft
	$(MAKE) clean -sC ./minilibx-linux
	$(RM) $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was deleted$(RESET)"

re : fclean all

bonus :
#	$(RM) $(NAME)
	$(MAKE) BONUS_ON=1

.PHONY: all clean fclean re bonus
