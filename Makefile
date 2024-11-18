# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 16:28:59 by sgabsi            #+#    #+#              #
#    Updated: 2024/11/18 14:15:05 by sgabsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

# Directories
SRC_SUBDIR				=	game_engine image init parsing player raycasting utils
SRCDIR					=	./src
INCDIR					=	./include
LIBDIR					=	./libs
OBJDIR					=	obj

# Sources
#GAME_ENGINE
SRC_GAME_ENGINE_DIR		=	game_engine
SRC_GAME_ENGINE_LIST	=	free_engine.c		\
							game_engine.c		\
							key_gestion.c		\
							update.c
SRC_GAME_ENGINE			=	$(addprefix $(SRC_GAME_ENGINE_DIR)/, $(SRC_GAME_ENGINE_LIST))

#IMAGE
SRC_IMAGE_DIR			=	image
SRC_IMAGE_LIST			=	create_image.c		\
							get_textures.c		\
							put_pixel.c
SRC_IMAGE				=	$(addprefix $(SRC_IMAGE_DIR)/, $(SRC_IMAGE_LIST))

# INIT
SRC_INIT_DIR			=	init
SRC_INIT_LIST			=	init.c				\
							windows.c
SRC_INIT				=	$(addprefix $(SRC_INIT_DIR)/, $(SRC_INIT_LIST))

# PARSING
SRC_PARSING_DIR			=	parsing
SRC_PARSING_LIST		=	check_texture.c		\
							get_map.c			\
							get_player_pos.c	\
							get_texture.c		\
							set_color.c			\
							utils.c
SRC_PARSING				=	$(addprefix $(SRC_PARSING_DIR)/, $(SRC_PARSING_LIST))

#PLAYER
SRC_PLAYER_DIR			=	player
SRC_PLAYER_LIST			=	camera_rot.c		\
							player_move.c
SRC_PLAYER				=	$(addprefix $(SRC_PLAYER_DIR)/, $(SRC_PLAYER_LIST))

# RAYCASTING
SRC_RAYCASTING_DIR		=	raycasting
SRC_RAYCASTING_LIST		=	angle.c				\
							checkers.c			\
							draw_line.c			\
							getters.c			\
							render.c
SRC_RAYCASTING			=	$(addprefix $(SRC_RAYCASTING_DIR)/, $(SRC_RAYCASTING_LIST))

# UTILS
SRC_UTILS_DIR			=	utils
SRC_UTILS_LIST			=	create_color.c		\
							error.c				\
							free_exit.c
SRC_UTILS				=	$(addprefix $(SRC_UTILS_DIR)/, $(SRC_UTILS_LIST))

SRC_LIST				=	$(SRC_GAME_ENGINE)	\
							$(SRC_IMAGE)		\
							$(SRC_INIT)			\
							$(SRC_PARSING)		\
							$(SRC_PLAYER)		\
							$(SRC_RAYCASTING)	\
							$(SRC_UTILS)		\
							cub3d.c
SRC						=	$(addprefix $(SRCDIR)/, $(SRC_LIST))

# Objects
OBJ_SUBDIRS				=	$(SRC_SUBDIR:%=$(OBJDIR)/%)
OBJ						=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEP						=	$(OBJ:.o=.d)

# Libraries
LIBFT_DIR 				=	$(LIBDIR)/libft
LIBFT 					=	$(LIBFT_DIR)/libft.a
MLX_DIR					=	$(LIBDIR)/minilibx
MLX						=	$(MLX_DIR)/libmlx_Linux.a

# Output
NAME					=	cub3D
NAME_BONUS				=	cub3D_bonus

# Compiler
CC						=	cc
CFLAGS					=	-Wall -Werror -Wextra -MMD -g3
OPTIONS					=	-I $(INCDIR) -I $(LIBFT_DIR)/includes -I $(MLX_DIR)
LFLAGS					=	-L $(LIBFT_DIR) -L $(MLX_DIR) -lft -lmlx -lX11 -lXext -lm

# Progress bar
COUNT					=	1
TOTAL_FILES				=	$(shell find $(SRCDIR) -type f -name "*.c" | wc -l)

# Colors
RED						=	\033[0;31m
GREEN					=	\033[0;32m
YELLOW					=	\033[0;33m
NC						=	\033[0m
KL						=	\033[K

#################
##  TARGETS    ##
#################

all: check

compile: pre_comp $(LIBFT) $(MLX) $(NAME)

check:
	@if [ -f "$(NAME)" ] && [ -z "$(shell find $(SRCDIR) -type f -name "*.c" -newer $(NAME) 2>/dev/null)" ] && [ -z "$(shell find $(SRCDIR) -type f -name "*.h" -newer $(NAME) 2>/dev/null)" ]; then \
		echo "$(YELLOW)********* Rien à faire - Tout est à jour *********$(NC)"; \
	else \
		make -s compile; \
	fi

pre_comp:
	@echo "$(YELLOW)********* Début de la compilation du programme $(NAME) *********$(NC)"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(OPTIONS) $(LFLAGS) -o $@
	@echo -e "\r$(GREEN)********* Compilation terminée avec succès! *********$(NC)$(KL)"
	@echo "$(GREEN)********* L'executable $(NAME) a été créée. *********$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OPTIONS) -c $< -o $@
	@printf "$(NC)\rCompiling files: [%-50s] %3d%% (%d/%d) %s$(KL)" \
		"$(shell printf '=%.0s' $$(seq 1 $$(($(COUNT) * 50 / $(TOTAL_FILES)))))" \
		$$(($(COUNT) * 100 / $(TOTAL_FILES))) \
		$(COUNT) \
		$(TOTAL_FILES) \
		$<
	$(eval COUNT=$(shell echo $$(($(COUNT)+1))))

$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(MLX):
	@make -sC $(MLX_DIR)

clean:
	@rm -rf $(OBJDIR)
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(MLX_DIR) clean
	@echo "$(YELLOW)********* Suppression des fichiers objets *********$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBFT_DIR) fclean
	@echo "$(RED)********* Suppression de l'executable $(NAME) *********$(NC)"

re: fclean compile

norminette:
	@echo "$(YELLOW)********* Exécution de norminette *********$(NC)"
	@norminette src/ include/ lib/libft | grep -B 1 -e "Error" || echo "Tous les fichiers ont passé le check norminette !"

.PHONY: check compile all clean fclean re norminette
-include $(DEP)