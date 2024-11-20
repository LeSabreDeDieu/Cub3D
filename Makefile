# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aditer <aditer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 16:28:59 by sgabsi            #+#    #+#              #
#    Updated: 2024/11/20 16:26:21 by aditer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#-------------Common Part-------------#
# Directories
LIBDIR						=	./libs
OBJDIR						=	obj

#-------------Mandatory-------------#
# Directories
SRC_SUBDIR					=	game_engine image init parsing player raycasting utils
SRCDIR						=	./mandatory/src
INCDIR						=	./mandatory/include
OBJDIR_MANDATORY			=	./mandatory/$(OBJDIR)

# Sources
#GAME_ENGINE
SRC_GAME_ENGINE_DIR			=	game_engine
SRC_GAME_ENGINE_LIST		=	free_engine.c				\
								game_engine.c				\
								key_gestion.c				\
								update.c
SRC_GAME_ENGINE				=	$(addprefix $(SRC_GAME_ENGINE_DIR)/, $(SRC_GAME_ENGINE_LIST))

#IMAGE
SRC_IMAGE_DIR				=	image
SRC_IMAGE_LIST				=	create_image.c				\
								get_textures.c				\
								put_pixel.c
SRC_IMAGE					=	$(addprefix $(SRC_IMAGE_DIR)/, $(SRC_IMAGE_LIST))

# INIT
SRC_INIT_DIR				=	init
SRC_INIT_LIST				=	init.c						\
								windows.c
SRC_INIT					=	$(addprefix $(SRC_INIT_DIR)/, $(SRC_INIT_LIST))

# PARSING
SRC_PARSING_DIR				=	parsing
SRC_PARSING_LIST			=	check_texture.c				\
								get_map_utils.c				\
								get_map.c					\
								get_player_pos.c			\
								get_texture.c				\
								set_color.c					\
								utils.c
SRC_PARSING					=	$(addprefix $(SRC_PARSING_DIR)/, $(SRC_PARSING_LIST))

#PLAYER
SRC_PLAYER_DIR				=	player
SRC_PLAYER_LIST				=	camera_rot.c				\
								check_collision.c			\
								player_move.c
SRC_PLAYER					=	$(addprefix $(SRC_PLAYER_DIR)/, $(SRC_PLAYER_LIST))

# RAYCASTING
SRC_RAYCASTING_DIR			=	raycasting
SRC_RAYCASTING_LIST			=	angle.c						\
								checkers.c					\
								draw_line.c					\
								getters.c					\
								render.c
SRC_RAYCASTING				=	$(addprefix $(SRC_RAYCASTING_DIR)/, $(SRC_RAYCASTING_LIST))

# UTILS
SRC_UTILS_DIR				=	utils
SRC_UTILS_LIST				=	create_color.c				\
								error.c						\
								free_exit.c
SRC_UTILS					=	$(addprefix $(SRC_UTILS_DIR)/, $(SRC_UTILS_LIST))

SRC_LIST					=	$(SRC_GAME_ENGINE)			\
								$(SRC_IMAGE)				\
								$(SRC_INIT)					\
								$(SRC_PARSING)				\
								$(SRC_PLAYER)				\
								$(SRC_RAYCASTING)			\
								$(SRC_UTILS)				\
								cub3d.c
SRC							=	$(addprefix $(SRCDIR)/, $(SRC_LIST))

#-------------Bonus-------------#
# Directories
SRC_BONUS_SUBDIR			=	game_engine image init parsing player raycasting utils
SRCDIR_BONUS				=	./bonus/src
INCDIR_BONUS				=	./bonus/include
OBJDIR_BONUS				=	./bonus/$(OBJDIR)

# Sources
#GAME_ENGINE
SRC_GAME_ENGINE_BONUS_DIR	=	game_engine
SRC_GAME_ENGINE_BONUS_LIST	=	free_engine.c				\
								game_engine.c				\
								key_gestion.c				\
								update.c
SRC_GAME_ENGINE_BONUS		=	$(addprefix $(SRC_GAME_ENGINE_BONUS_DIR)/, $(SRC_GAME_ENGINE_BONUS_LIST))

#IMAGE
SRC_IMAGE_BONUS_DIR			=	image
SRC_IMAGE_BONUS_LIST		=	create_image.c				\
								get_textures.c				\
								put_pixel.c
SRC_IMAGE_BONUS				=	$(addprefix $(SRC_IMAGE_BONUS_DIR)/, $(SRC_IMAGE_BONUS_LIST))

# INIT
SRC_INIT_BONUS_DIR			=	init
SRC_INIT_BONUS_LIST			=	init.c						\
								windows.c
SRC_INIT_BONUS				=	$(addprefix $(SRC_INIT_BONUS_DIR)/, $(SRC_INIT_BONUS_LIST))

# PARSING
SRC_PARSING_BONUS_DIR		=	parsing
SRC_PARSING_BONUS_LIST		=	check_texture.c				\
								get_map.c					\
								get_player_pos.c			\
								get_texture.c				\
								set_color.c					\
								utils.c
SRC_PARSING_BONUS			=	$(addprefix $(SRC_PARSING_BONUS_DIR)/, $(SRC_PARSING_BONUS_LIST))

#PLAYER
SRC_PLAYER_BONUS_DIR		=	player
SRC_PLAYER_BONUS_LIST		=	camera_rot.c				\
								check_collision.c			\
								player_move.c
SRC_PLAYER_BONUS			=	$(addprefix $(SRC_PLAYER_BONUS_DIR)/, $(SRC_PLAYER_BONUS_LIST))

# RAYCASTING
SRC_RAYCASTING_BONUS_DIR	=	raycasting
SRC_RAYCASTING_BONUS_LIST	=	angle.c						\
								checkers.c					\
								draw_line.c					\
								getters.c					\
								render.c
SRC_RAYCASTING_BONUS		=	$(addprefix $(SRC_RAYCASTING_BONUS_DIR)/, $(SRC_RAYCASTING_BONUS_LIST))

# UTILS
SRC_UTILS_BONUS_DIR			=	utils
SRC_UTILS_BONUS_LIST		=	create_color.c				\
								error.c						\
								free_exit.c
SRC_UTILS_BONUS				=	$(addprefix $(SRC_UTILS_BONUS_DIR)/, $(SRC_UTILS_BONUS_LIST))

SRC_LIST_BONUS				=	$(SRC_GAME_ENGINE_BONUS)	\
								$(SRC_IMAGE_BONUS)			\
								$(SRC_INIT_BONUS)			\
								$(SRC_PARSING_BONUS)		\
								$(SRC_PLAYER_BONUS)			\
								$(SRC_RAYCASTING_BONUS)		\
								$(SRC_UTILS_BONUS)			\
								cub3d_bonus.c
SRC_BONUS					=	$(addprefix $(SRCDIR_BONUS)/, $(SRC_LIST_BONUS))

# Objects
# Mandatory
OBJ_SUBDIRS					=	$(SRC_SUBDIR:%=$(OBJDIR_MANDATORY)/%)
OBJ							=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR_MANDATORY)/%.o)
DEP							=	$(OBJ:.o=.d)

#Bonus
OBJ_SUBDIRS_BONUS			=	$(SRC_BONUS_SUBDIR:%=$(OBJDIR_BONUS)/%)
OBJ_BONUS					=	$(SRC_BONUS:$(SRCDIR_BONUS)/%.c=$(OBJDIR_BONUS)/%.o)
DEP_BONUS					=	$(OBJ_BONUS:.o=.d)

# Libraries
LIBFT_DIR 					=	$(LIBDIR)/libft
LIBFT 						=	$(LIBFT_DIR)/libft.a
MLX_DIR						=	$(LIBDIR)/minilibx
MLX							=	$(MLX_DIR)/libmlx_Linux.a

# Output
NAME						=	cub3D
NAME_BONUS					=	cub3D_bonus

# Compiler
CC							=	cc
CFLAGS						=	-Wall -Werror -Wextra -MMD -g3
OPTIONS						=	-I $(INCDIR) -I $(LIBFT_DIR)/includes -I $(MLX_DIR)
OPTIONS_BONUS				=	-I $(INCDIR_BONUS) -I $(LIBFT_DIR)/includes -I $(MLX_DIR)
LFLAGS						=	-L $(LIBFT_DIR) -L $(MLX_DIR) -lft -lmlx -lX11 -lXext -lm

# Progress bar
COUNT						=	1
TOTAL_FILES					=	$(shell find $(SRCDIR) -type f -name "*.c" | wc -l)
TOTAL_FILES_BONUS			=	$(shell find $(SRCDIR_BONUS) -type f -name "*.c" | wc -l)

# Colors
RED							=	\033[0;31m
GREEN						=	\033[0;32m
YELLOW						=	\033[0;33m
NC							=	\033[0m
KL							=	\033[K

#################
##  TARGETS    ##
#################

all: check
bonus: check_bonus

compile: pre_comp $(LIBFT) $(MLX) $(NAME)
compile_bonus: pre_comp_bonus $(LIBFT) $(MLX) $(NAME_BONUS)

check:
	@if [ -f "$(NAME)" ] && [ -z "$(shell find $(SRCDIR) -type f -name "*.c" -newer $(NAME) 2>/dev/null)" ] && [ -z "$(shell find $(SRCDIR) -type f -name "*.h" -newer $(NAME) 2>/dev/null)" ]; then \
		echo "$(YELLOW)********* Rien à faire - Tout est à jour *********$(NC)"; \
	else \
		make -s compile; \
	fi

check_bonus:
	@if [ -f "$(NAME_BONUS)" ] && [ -z "$(shell find $(SRCDIR_BONUS) -type f -name "*.c" -newer $(NAME_BONUS) 2>/dev/null)" ] && [ -z "$(shell find $(SRCDIR_BONUS) -type f -name "*.h" -newer $(NAME_BONUS) 2>/dev/null)" ]; then \
		echo "$(YELLOW)********* Rien à faire - Tout est à jour *********$(NC)"; \
	else \
		make -s compile_bonus; \
	fi

pre_comp:
	@echo "$(YELLOW)********* Début de la compilation du programme $(NAME) *********$(NC)"

pre_comp_bonus:
	@echo "$(YELLOW)********* Début de la compilation du programme $(NAME_BONUS) *********$(NC)"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(OPTIONS) $(LFLAGS) -o $@
	@echo -e "\r$(GREEN)********* Compilation terminée avec succès! *********$(NC)$(KL)"
	@echo "$(GREEN)********* L'executable $(NAME) a été créée. *********$(NC)"

$(OBJDIR_MANDATORY)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OPTIONS) -c $< -o $@
	@printf "$(NC)\rCompiling files: [%-50s] %3d%% (%d/%d) %s$(KL)" \
		"$(shell printf '=%.0s' $$(seq 1 $$(($(COUNT) * 50 / $(TOTAL_FILES)))))" \
		$$(($(COUNT) * 100 / $(TOTAL_FILES))) \
		$(COUNT) \
		$(TOTAL_FILES) \
		$<
	$(eval COUNT=$(shell echo $$(($(COUNT)+1))))

$(NAME_BONUS): $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(OPTIONS_BONUS) $(LFLAGS) -o $@
	@echo -e "\r$(GREEN)********* Compilation terminée avec succès! *********$(NC)$(KL)"
	@echo "$(GREEN)********* L'executable $(NAME_BONUS) a été créée. *********$(NC)"

$(OBJDIR_BONUS)/%.o: $(SRCDIR_BONUS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OPTIONS_BONUS) -c $< -o $@
	@printf "$(NC)\rCompiling files: [%-50s] %3d%% (%d/%d) %s$(KL)" \
		"$(shell printf '=%.0s' $$(seq 1 $$(($(COUNT) * 50 / $(TOTAL_FILES_BONUS)))))" \
		$$(($(COUNT) * 100 / $(TOTAL_FILES_BONUS))) \
		$(COUNT) \
		$(TOTAL_FILES_BONUS) \
		$<
	$(eval COUNT=$(shell echo $$(($(COUNT)+1))))


$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(MLX):
	@make -sC $(MLX_DIR)

clean:
	@rm -rf $(OBJDIR_MANDATORY)
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(MLX_DIR) clean
	@echo "$(YELLOW)********* Suppression des fichiers objets *********$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBFT_DIR) fclean
	@echo "$(RED)********* Suppression de l'executable $(NAME) *********$(NC)"

clean_bonus:
	@rm -rf $(OBJDIR_BONUS)
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(MLX_DIR) clean
	@echo "$(YELLOW)********* Suppression des fichiers objets *********$(NC)"

fclean_bonus: clean_bonus
	@rm -f $(NAME_BONUS)
	@make -sC $(LIBFT_DIR) fclean
	@echo "$(RED)********* Suppression de l'executable $(NAME) *********$(NC)"

re: fclean compile

norminette:
	@echo "$(YELLOW)********* Exécution de norminette *********$(NC)"
	@norminette src/ include/ lib/libft | grep -B 1 -e "Error" || echo "Tous les fichiers ont passé le check norminette !"

.PHONY: check compile all clean fclean re norminette
-include $(DEP)