# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 13:40:37 by irodrigo          #+#    #+#              #
#    Updated: 2021/10/30 14:42:41 by irodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OS DISCLAIMER #
.DELETE_ON_ERROR:

INCLUDES = -I/usr/include -I. -Iincludes/

NAMECHK		= checker
NAMEPUSH	= push_swap
NAMEBONUS	= push_swap

# SOURCES #
SRCINIPUSH 		= ft_stack_aux ft_utils ft_merge_sort ft_merge_sort_utils \
				ft_action_push ft_action_rot ft_action_rot_rev ft_action_swap \
				ft_lst_oper ft_gnl ft_seg_utils ft_push_swap ft_srt_three ft_split_back \
				ft_split_stack ft_com_utils ft_main

SRC			=	ft_push_swp ft_action_rotate ft_action_swap ft_action_push ft_action_rev_rotate ft_check_error ft_gnl ft_common_stack ft_common_aux ft_list_operations ft_sort_algrthm ft_sort_algrthm_stkops ft_p_swp_func ft_push_swp_aux ft_push_stk_func ft_push_stk_aux ft_push_primary
SRCBONUS 	=
HLIBS		=	ft_primary.h
LIBFT 		= 	libft/libft.a

SRCCHK 		= $(addsuffix .c, $(SRC))
SRCPUSH		= $(addsuffix .c, $(SRCINIPUSH))
SRCFINBONUS = $(addsuffix .c, $(SRCBONUS))
OBJSCHK		= $(SRCCHK:.c=.o)
OBJSPUSH	= $(SRCPUSH:.c=.o)
OBJSBONUS 	= $(SRCFINBONUS:.c=.o)

# COMPILER #
THRFLAG		= -pthread
CDEBUGF		= -fsanitize=address -g3
CDEBTHR		= -fsanitize=threads -g3
OPTFLAGS	= -O3
CFLAGS		= -Wall -Wextra -Werror $(OPTFLAGS) #$(CDEBUGF)
CC			= gcc $(CFLAGS)

# COLOUR DEFINITION #
BLUE = \033[0;34m
GREEN = \033[1;32m
RESET = \033[0m

# CLEANING INSTRUCTION #
RM = rm -rf

all: $(NAMEPUSH) #$(NAMECHK)

$(NAMEPUSH): $(OBJSPUSH)
	@echo "$(BLUE)==========CREATING LIBFT==========$(RESET)"
	@cd libft && make re
	@echo "$(BLUE)==========CREATING $(NAMEPUSH)==========$(RESET)"
	@$(CC) $(INCLUDES) ${OBJSPUSH} $(LIBFT) ${LIBS} -o ${NAMEPUSH}
	@echo "Done"
	@echo "$(GREEN)SUCCESS$(RESET) creating $(NAMEPUSH) file"

bonus:  $(OBJSBONUS)
	@echo "$(BLUE)==========CREATING LIBFT==========$(RESET)"
	@cd libft && make re
	@echo "$(BLUE)==========CREATING $(NAMEBONUS)==========$(RESET)"
	@$(CC) $(INCLUDES) ${OBJSBONUS} $(LIBFT) ${LIBS} -o ${NAMEBONUS}
	@echo "Done"
	@echo "$(GREEN)==========WELLDONE==========$(RESET)"
	@echo "Success creating $(NAMEBONUS) file"

normi: fclean
	norminette $(SRCPUSH) $(HLIBS)

clean:
	@$(RM) $(OBJSCHK)
	@$(RM) $(OBJSPUSH)
	@$(RM) $(OBJSBONUS)
	@echo "$(GREEN)==========REMOVED==========$(RESET)"
	@echo "Success normal cleaning"

fclean: clean
	@$(RM) ${NAME}
	@$(RM) ${NAMEPUSH}
	@echo "$(GREEN)==========TOTALLY REMOVED==========$(RESET)"
	@echo "Success deepest cleaning"

re : fclean all

.PHONY: all clean fclean re addsuffix normi
