# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 16:20:34 by aelbouaz          #+#    #+#              #
#    Updated: 2025/12/23 15:43:23 by aelbouaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g

PUSH_SWAP_SRCS = operations.c helper_funcs_1.c helper_funcs_2.c \
	push_swap.c list_funcs.c error_handle.c ft_split_push.c

PUSH_SWAP_OBJ = $(PUSH_SWAP_SRCS:.c=.o)

NAME = push_swap
LIBFT_DIR = ft_printf/libft/
LIBFT = $(LIBFT_DIR)libft.a
PRINTF_DIR = ft_printf/
PRINTF = $(PRINTF_DIR)libftprintf.a

HEADERS = $(PRINTF_DIR)ft_printf.h $(LIBFT_DIR)libft.h
INCLUDES = -I$(PRINTF_DIR) -I$(LIBFT_DIR)

CC = cc
MAKE = make

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME) DONE_MSG

DONE_MSG:
	@printf "$(RED)\nDONE$(RESET)"
MSG:
	@printf "$(GREEN)Compiling Push_swap$(RESET)"

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) --no-print-directory -C $(PRINTF_DIR)

$(NAME): $(LIBFT) $(PRINTF) MSG $(PUSH_SWAP_OBJ)
	@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) \
		-L$(PRINTF_DIR) -lftprintf \
		-L$(LIBFT_DIR) -lft \
		-o $(NAME)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(GREEN).$(RESET)"

clean:
	@$(MAKE) --no-print-directory -C $(PRINTF_DIR) clean
	@rm -f $(PUSH_SWAP_OBJ)
	@printf "$(BLUE)Cleaned Up Libft objects$(RESET)\n"
	@printf "$(BLUE)Cleaned Up ft_printf objects$(RESET)\n"
	@printf "$(BLUE)Cleaned Up Push_swap$(RESET)\n"

fclean: clean
	@$(MAKE) --no-print-directory -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re MSG
