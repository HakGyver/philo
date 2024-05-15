# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteste <jteste@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 11:42:35 by jteste            #+#    #+#              #
#    Updated: 2024/05/15 13:37:11 by jteste           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME		:= philo
CFLAGS		:= -Wextra -Wall -Werror -pthread -o3
SRCS		:= srcs/main.c \
				srcs/utils.c \
				srcs/inits.c \
				srcs/error_and_free.c \
				srcs/time.c \
				srcs/threads.c \
				srcs/philo_routine.c \
				srcs/overseer_routine.c

OBJ_DIR		:= srcs/tmp
OBJS		:= $(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.c=.o)))
CC 			= gcc $(CFLAGS)

all: $(NAME)

CLR_RMV		:= \033[0m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
CYAN 		:= \033[1;36m
GREY		:= \033[0;37m
RED_UL			:= \033[4;31m

RM			:= rm -f

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "\n$(GREY)    █  ██  █    "
	@echo "$(GREY)   ██  ██  ██   "
	@echo "$(GREY)   ██  ██  ██   "
	@echo "$(GREY)  ███  ██  ███  "
	@echo "$(GREY)  ███  ██  ███  "
	@echo "$(GREY)  ███  ██  ███ $(RED)	   ▄███████▄    ▄█    █▄     ▄█   ▄█        ▄██████▄ "
	@echo "$(GREY) ████ ████ ████ $(RED)   ███    ███   ███    ███   ███  ███       ███    ███"
	@echo "$(GREY) ██████████████ $(RED)   ███    ███   ███    ███   ███▌ ███       ███    ███"
	@echo "$(GREY)  ████████████ $(RED)    ███    ███  ▄███▄▄▄▄███▄▄ ███▌ ███       ███    ███"
	@echo "$(GREY)   ██████████  $(RED)  ▀█████████▀  ▀▀███▀▀▀▀███▀  ███▌ ███       ███    ███"
	@echo "$(GREY)      ████     $(RED)    ███          ███    ███   ███  ███       ███    ███"
	@echo "$(GREY)      ████     $(RED)    ███          ███    ███   ███  ███▌    ▄ ███    ███"
	@echo "$(GREY)      ████      $(RED)  ▄████▀        ███    █▀    █▀   █████▄▄██  ▀██████▀ "
	@echo "$(GREY)      ████       $(RED)                                ▀                    "
	@echo "$(GREY)      ████       ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄"
	@echo "$(GREY)      ████      	┏┓┳┓┏┓┏┓┏┳┓┏┓┳┓  ┏┓┳┳┏┓┏┓┏┓┏┓┏┓┏┓┳┳┓ ┓ ┓┏"
	@echo "$(GREY)      ████      	┃ ┣┫┣ ┣┫ ┃ ┣ ┃┃  ┗┓┃┃┃ ┃ ┣ ┗┓┗┓┣ ┃┃┃ ┃ ┗┫"
	@echo "$(GREY)     ██████     	┗┛┛┗┗┛┛┗ ┻ ┗┛┻┛  ┗┛┗┛┗┛┗┛┗┛┗┛┗┛┻ ┗┛┗┛┗┛┗┛"
	@echo "$(GREY)     ██████     "
	@echo "\n$(RED)Usage: $(GREY)./philo nb_of_philo time_to_die time_to_eat time_to_sleep [nb_of_meal]$(CLR_RMV)\n"
$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJ_DIR)
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean: clean
	$(RM) $(NAME)
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re: fclean all

.PHONY: all, clean, fclean, re