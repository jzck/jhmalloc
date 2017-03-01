ifeq ($(HOSTTYPE),)
HOSTTYPE	:= $(shell uname -m)_$(shell uname -s)
endif

NAME		=	libft_malloc.so
ARCH_NAME	=	libft_malloc_$(HOSTTYPE).so

CC			=	gcc
W_FLAGS		=	-Wall -Wextra -Werror
V_FLAGS		=	-fvisibility=hidden
D_FLAGS		=
FLAGS		=	$(W_FLAGS) $(V_FLAGS) $(D_FLAGS)

DELTA		=	$$(echo "$$(tput cols)-47"|bc)

LIBFT_DIR	=	libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	$(LIBFT_DIR)includes/

SRC_DIR		=	src/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SRC_BASE	=	\
error_lib.c\
free.c\
get_zones.c\
malloc.c\
node_lib.c\
realloc.c\
show_alloc_mem.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

all :
	@make -j $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
	@$(CC) --shared $(FLAGS)\
		-I $(INC_DIR) \
		-I $(LIBFT_INC) \
		$(LIBS) \
		$(LIBFT_LIB) $(OBJS) \
		-o $(ARCH_NAME)
	@ln -fs $(ARCH_NAME) $(NAME)
	@strip -x $(NAME)
	@printf "\r\e[48;5;15;38;5;25m✅ MAKE $(ARCH_NAME)\e[0m\e[K\n"

$(LIBFT_LIB):
	@make -j -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval COLOR=$(shell echo $$(($(PERCENT)%35+196))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB)))))
	@printf "\r\e[38;5;11m⌛ MAKE %10.10s : %2d%% \e[48;5;%dm%*s\e[0m%*s\e[48;5;255m \e[0m \e[38;5;11m %*s\e[0m\e[K" $(NAME) $(PERCENT) $(COLOR) $(DONE) "" $(TO_DO) "" $(DELTA) "$@"
	@$(CC) $(FLAGS) -MMD -c $< -o $@\
		-I $(INC_DIR)\
		-I $(LIBFT_INC)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

clean:			cleanlib
	@rm -rf $(OBJ_DIR)
	@printf "\r\e[38;5;202m✖ clean $(NAME).\e[0m\e[K\n"

cleanlib:
	@make -C $(LIBFT_DIR) clean

fclean:			clean fcleanlib
	@rm -f $(NAME)
	@printf "\r\e[38;5;196m❌ fclean $(NAME).\e[0m\e[K\n"

fcleanlib:		cleanlib
	@make -C $(LIBFT_DIR) fclean

re:				fclean all

relib:			fcleanlib $(LIBFT_LIB)

test:
	gcc -lft_malloc -L. -Iincludes -I$(LIBFT_INC) -o myprogram main.c

.PHONY :		fclean clean re relib cleanlib fcleanlib $(LIBFT_LIB)

-include $(OBJS:.o=.d)
