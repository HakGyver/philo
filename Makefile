# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteste <jteste@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 11:42:35 by jteste            #+#    #+#              #
#    Updated: 2024/04/16 14:32:17 by jteste           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME		:= philo
CFLAGS		:= -Wextra -Wall -Werror
SRCS		:= philo.c \

OBJS		:= $(SRCS:.c=.o)
CC 			= gcc $(CFLAGS)

all: $(NAME)

CLR_RMV		:= \033[0m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
CYAN 		:= \033[1;36m
GREY		:= \033[0;37m

RM			:= rm -f

$(NAME): $(SRCS) $(OBJS)
	@echo "$(GREY)    █  ██  █    "
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
	@echo "$(GREY)      ████      "
	@echo "$(GREY)      ████      "
	@echo "$(GREY)     ██████     "
	@echo "$(GREY)     ██████     "
	@$(CC) $(OBJS) -o $(NAME)
	@echo "\n $(YELLOW)$(NAME) $(GREEN)Created successfully \n$(CLR_RMV)"

clean:
	$(RM) $(OBJS)
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean: clean
	$(RM) $(NAME)
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re: fclean all

.PHONY: all, clean, fclean, re