# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wescande <wescande@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/29 21:32:58 by wescande          #+#    #+#              #
#    Updated: 2017/03/31 18:08:35 by jhalford         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME_BIS	=	libft_malloc.so
NAME		=	libft_malloc_$(HOSTTYPE).so

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -fPIC #-fsanitize=address
MAIN_FLAGS	=	-shared
OBJ_FLAGS	=

LEN_NAME	=	`printf "%s" $(NAME) |wc -c`
DELTA		=	$$(echo "$$(tput cols)-31-$(LEN_NAME)"|bc)

LIBFT_DIR	=	libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	$(LIBFT_DIR)includes/

LIBS		=

SRC_DIR		=	srcs/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SRC_BASE	=	\
error_lib.c\
free.c\
get_zone.c\
malloc.c\
node_lib.c\
realloc.c\
show_alloc_mem.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

SHELL		:=	/bin/bash

all :
	@make -C $(LIBFT_DIR)
	@make -j $(NAME)
	@make $(NAME_BIS)

$(NAME):		$(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) \
		-I $(INC_DIR) \
		-I $(LIBFT_INC) \
		$(LIBS) $(LIBFT_LIB) $(MAIN_FLAGS) $(FLAGS)
	@printf "\r\033[38;5;117m✓ MAKE $(NAME)\033[0m\033[K\n"

$(NAME_BIS):	$(NAME)
	@if [ -L $(NAME_BIS) ]; \
	then \
		rm $(NAME_BIS); \
	fi
	@ln -s $(NAME) $(NAME_BIS)
	@printf "\r\033[38;5;117m✓ LINK $(NAME_BIS)\033[0m\033[K\n"

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB) - 1))))
	@$(eval COLOR=$(shell list=(160 196 202 208 215 221 226 227 190 154 118 82 46); index=$$(($(PERCENT) * $${#list[@]} / 100)); echo "$${list[$$index]}"))
	@printf "\r\033[38;5;%dm⌛ [%s]: %2d%% `printf '█%.0s' {0..$(DONE)}`%*s❙%*.*s\033[0m\033[K" $(COLOR) $(NAME) $(PERCENT) $(TO_DO) "" $(DELTA) $(DELTA) "$(shell echo "$@" | sed 's/^.*\///')"
	@$(CC) $(FLAGS) $(OBJ_FLAG) -MMD -c $< -o $@\
		-I $(INC_DIR)\
		-I $(LIBFT_INC)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

clean:			cleanlib
	@if [ -e $(OBJ_DIR) ]; \
	then \
		rm -rf $(OBJ_DIR); \
		printf "\r\033[38;5;202m✗ clean $(NAME).\033[0m\033[K\n"; \
	fi;

cleanlib:
	@make -C $(LIBFT_DIR) clean

fclean:			clean fcleanlib
	@if [ -e $(NAME) ]; \
	then \
		rm -rf $(NAME); \
		printf "\r\033[38;5;196m✗ fclean $(NAME).\033[0m\033[K\n"; \
	fi;
	@if [ -L $(NAME_BIS) ]; \
	then \
		rm -rf $(NAME_BIS); \
		printf "\r\033[38;5;196m✗ delete link $(NAME_BIS).\033[0m\033[K\n"; \
	fi;
	@$(foreach n, $(shell echo libft_malloc_*.so), if [ -f $n ]; then rm -rf $n; printf "\r\033[38;5;196m✗ delete old lib $n.\033[0m\033[K\n"; fi;)

fcleanlib:		cleanlib
	@make -C $(LIBFT_DIR) fclean

re:				fclean all

relib:			fcleanlib $(LIBFT_LIB)

.PHONY :		fclean clean re relib cleanlib fcleanlib

-include $(OBJS:.o=.d)
