# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 00:27:12 by ide-dieg          #+#    #+#              #
#    Updated: 2025/05/25 16:46:18 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror# -fsanitize=address -g3

SRC =	main.c \
		ft_atol.c \
		ft_isdigit.c \
		ft_check_arguments.c \
		ft_strlen.c \
		ft_printerror.c \
		ft_calloc.c \
		ft_clean_table.c \
		ft_create_processes.c \
		ft_get_time.c \
		ft_kill_pids.c \
		ft_loading.c \
		ft_philo.c \
		ft_print_status.c \
		ft_wait_processes.c \
		ft_itoa.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		

OBJ = $(SRC:%.c=%.o)

$(NAME): ide-dieg philosopher_title $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(VERDE)$(NAME) compiled$(NC)"

clean:
	@rm -f $(OBJ)
	@echo "$(ROJO)$(NAME) objects removed$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(ROJO)$(NAME) removed$(NC)"

re: fclean $(NAME)

ROJO = \033[0;31m
NC = \033[0m
NARANJA = \033[0;33m
AZUL = \033[0;34m
VERDE = \033[0;32m

ide-dieg:
	@echo "$(ROJO)██╗██████╗ ███████╗    ██████╗ ██╗███████╗ ██████╗ $(AZUL)         ██╗  ██╗██████╗ "
	@echo "$(ROJO)██║██╔══██╗██╔════╝    ██╔══██╗██║██╔════╝██╔════╝ $(AZUL)         ██║  ██║╚════██╗"
	@echo "$(ROJO)██║██║  ██║█████╗█████╗██║  ██║██║█████╗  ██║  ███╗$(AZUL)         ███████║ █████╔╝"
	@echo "$(ROJO)██║██║  ██║██╔══╝╚════╝██║  ██║██║██╔══╝  ██║   ██║$(AZUL)         ╚════██║██╔═══╝ "
	@echo "$(ROJO)██║██████╔╝███████╗    ██████╔╝██║███████╗╚██████╔╝$(AZUL)              ██║███████╗"
	@echo "$(ROJO)╚═╝╚═════╝ ╚══════╝    ╚═════╝ ╚═╝╚══════╝ ╚═════╝ $(AZUL)              ╚═╝╚══════╝"
	@echo "$(NARANJA)██╗  ██╗ ██████╗ ██████╗ ███╗   ███╗██╗██████╗ ███████╗██╗   ██╗$(VERDE)       ██╗  "
	@echo "$(NARANJA)██║  ██║██╔═══██╗██╔══██╗████╗ ████║██║██╔══██╗██╔════╝██║   ██║$(VERDE)   ██╗ ╚═██╗"
	@echo "$(NARANJA)███████║██║   ██║██████╔╝██╔████╔██║██║██║  ██║█████╗  ██║   ██║$(VERDE)   ╚═╝   ██║"
	@echo "$(NARANJA)██╔══██║██║   ██║██╔══██╗██║╚██╔╝██║██║██║  ██║██╔══╝  ╚██╗ ██╔╝$(VERDE)   ██╗   ██║"
	@echo "$(NARANJA)██║  ██║╚██████╔╝██║  ██║██║ ╚═╝ ██║██║██████╔╝███████╗ ╚████╔╝ $(VERDE)   ╚═╝ ██╔═╝ "
	@echo "$(NARANJA)╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝╚═════╝ ╚══════╝  ╚═══╝  $(VERDE)       ╚═╝  $(NC)"

philosopher_title:
	@echo " ____  _  _  __  __     __   ____   __  ____  _  _  ____  ____  ____ "
	@echo "(  _ \/ )( \(  )(  )   /  \ / ___) /  \(  _ \/ )( \(  __)(  _ \/ ___)"
	@echo " ) __/) __ ( )( / (_/\(  O )\___ \(  O )) __/) __ ( ) _)  )   /\\___ \\"
	@echo "(__)  \_)(_/(__)\____/ \__/ (____/ \__/(__)  \_)(_/(____)(__\_)(____/"
