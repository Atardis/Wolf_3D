# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/08 06:12:57 by gahubaul          #+#    #+#              #
#    Updated: 2016/05/08 06:12:59 by gahubaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CFLAGS = -Wall -Wextra -Werror
FLAG = -lmlx -framework OpenGL -framework Appkit

GREEN = \033[33;32m
RED = \033[33;31m
YELLOW = \033[33m

LOC_SRC = srcs/

SRCS = $(addprefix $(LOC_SRC), $(SRC))

SRC =	main.c image_wolf3d.c map.c trace_wall.c  trace_line.c localisation.c

all: $(NAME)
	@printf ""

$(NAME): $(SRCS)
	@printf "$(GREEN)|$(RED) Compilation de la libft\t\t"
	@make -C libft
	@printf "$(GREEN) | OK |\n"
	@printf "$(GREEN)|$(RED) Compilation du programme Wolf3D\t"
	@gcc -o $(NAME) $(SRCS) $(FLAG) $(CFLAGS) libft/libft.a
	@printf "$(GREEN) | OK |\n"
	@printf "\n"
	@printf "$(GREEN)| The $(RED)Wolf3D $(GREEN)file is create\t\t | OK |\n"

clean:
	@printf "\$(GREEN)|$(YELLOW) Destruction des fichiers .o libft\t"
	@make -C libft clean
	@printf "$(GREEN) | OK |\n"

fclean: clean
	@printf "\$(GREEN)|$(YELLOW) Destruction du fichier   .a libft\t"
	@make -C libft fclean
	@printf "$(GREEN) | OK |\n"
	@printf "\$(GREEN)|$(YELLOW) Destruction de l'executable Wolf3D\t"
	@rm -f $(NAME)
	@printf "$(GREEN) | OK |\n"

back:
	@printf "\n"

help:
	@printf "$(GREEN)- make        	$(RED)(Compile)\n"
	@printf "$(GREEN)- make fclean 	$(RED)(Destruction files .O and Program)\n"
	@printf "$(GREEN)- make clean  	$(RED)(Destruction files .O)\n"
	@printf "$(GREEN)- make re    	$(RED)(Recompile)\n"

re: fclean back all

.PHONY: all fclean clean re
