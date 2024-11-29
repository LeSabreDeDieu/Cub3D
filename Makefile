# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 16:28:59 by sgabsi            #+#    #+#              #
#    Updated: 2024/11/22 08:24:34 by sgabsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

# Directories
BONUS_DIR			=	bonus
Mandatory_DIR		=	mandatory

#################
##  TARGETS    ##
#################

all: 
	@make -sC $(Mandatory_DIR)
bonus: 
	@make -sC $(BONUS_DIR)

clean:
	@make -sC $(Mandatory_DIR) clean

fclean:
	@make -sC $(Mandatory_DIR) fclean

clean_bonus:
	@make -sC $(BONUS_DIR) clean

fclean_bonus: clean_bonus
	@make -sC $(BONUS_DIR) fclean

re:
	@make -sC $(Mandatory_DIR) re

re_bonus:
	@make -sC $(BONUS_DIR) re

.PHONY: all bonus clean fclean clean_bonus fclean_bonus re re_bonus