PURP = \e[35m
GREEN = \e[32m
GREEN2 = \033[32m
RED = \e[31m
WHITE = \e[39m
YELLOW = \033[33m
HIDDEN = \e[8m
RESET = \e[0
BLUE = \033[34m
CYAN = \033[36m

NAME = Cub3D

SRCS_DIR = srcs/
SRCS =	srcs/cub3d.c\
		srcs/error.c\
		srcs/free.c\
		srcs/draw.c\
		srcs/player.c\
		srcs/player_movement.c\
		srcs/init.c\
		srcs/display_map.c\
		srcs/in_keys_hook.c\
		srcs/test.c\
		srcs/parse.c\
		srcs/checker_map.c\
		srcs/map_utils.c\
		srcs/ray.c\
		srcs/ray_casting.c\
		srcs/display_minimap.c\
		srcs/math_utils.c\
		srcs/map_utils2.c\

OBJS 	= ${SRCS:.c=.o}
MAIN	= srcs/cub3d.c

HEADER	= -Iinclude

LIB = utils/libft/libft.a utils/ft_printf/libftprintf.a utils/mlx/libmlx.a utils/get_next_line/libgnl.a
LBFT_PATH = ./utils/libft/
PRINTF_PATH = ./utils/ft_printf/
GNL_PATH = ./utils/get_next_line/
MLX_PATH = ./utils/mlx/

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -Imlx #-g -fsanitize=address

MLXFLAGS = -framework OpenGL -framework AppKit

AR = ar rc
RM = rm -f

.c.o:		%.o : %.c
					@gcc ${CFLAGS} -I ${HEADER} -Imlx -c $< -o $(<:.c=.o)

all: 		${NAME}

${NAME}:	${OBJS}
					@echo "$(CYAN)---- Compiling library ----"
					@sleep 0.2
					@echo "$(GREEN2)ð Link paths"
					@$(MAKE) -C $(LBFT_PATH)
					@$(MAKE) -C $(MLX_PATH)
					@$(MAKE) -C $(PRINTF_PATH)
					@$(MAKE) -C $(GNL_PATH)
					@$(CC) $(CFLAGS) ${OBJS} -o $(NAME) $(LIB) $(MLXFLAGS)
					@printf "$(BLUE)ðµ Creating $(NAME)$(RESET)\n"
					@sleep 0.2
					@echo "$(CYAN)Cub3D Compiled ! \033[39m(\033[31mà¹\033[39mâ¹â¡â¹\033[31mà¹\033[39m)"
					@sleep 0.2
					@echo ""

clean:
					@${RM} ${OBJS}
					@echo ""
					@echo "$(YELLOW)---- Cleaning library ----"
					@sleep 0.2
					@printf "$(BLUE)ð§½ Cleaning $(NAME)$(RESET)\n"
					@$(MAKE) -C $(LBFT_PATH) clean
#					@$(MAKE) -C $(MLX_PATH) clean
					@$(MAKE) -C $(PRINTF_PATH) clean
#					@$(MAKE) -C $(GNL_PATH) fclean
					@echo "$(GREEN2)ð Cleaning paths"
					@sleep 0.2
					@echo "$(YELLOW)Cub3D is all clean ! $(ORANGE)(ï¾âã®â)ï¾$(YELLOW)*:ï½¥ï¾â§"
					@sleep 0.2
					@echo ""

fclean: 	clean
					@${RM} $(NAME)
					@$(MAKE) -C $(LBFT_PATH) fclean
					@$(MAKE) -C $(PRINTF_PATH) fclean
#					@$(MAKE) -C $(MLX_PATH) fclean
					@$(MAKE) -C $(GNL_PATH) fclean
					@printf "\r$(PURP)----- Deleting library ----\n"
					@echo ð "\033[31mEverything is deleting now !"
					@sleep 0.2
					@printf "\r$(PURP)$(NAME) have been removed $(WHITE)Â¯\_$(PURP)(ã)$(WHITE)_/Â¯$(RESET)\n"
					@sleep 0.2
					@echo ""

re:			fclean all

leak: 		all
					leaks -atExit -- ./$(NAME) map/map.cub

.PHONY: all clean fclean re party
