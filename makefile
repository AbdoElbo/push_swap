# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 16:20:34 by aelbouaz          #+#    #+#              #
#    Updated: 2025/10/15 15:32:46 by aelbouaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

PUSH_SWAP_SRCS = operations.c helper_funcs_1.c helper_funcs_2.c \
	push_swap.c list_funcs.c error_handle.c ft_split_push.c

PUSH_SWAP_OBJ = $(PUSH_SWAP_SRCS:.c=.o)

NAME = push_swap
LIBFT_DIR = ft_printf/libft/
LIBFT = $(LIBFT_DIR)libft.a
PRINTF_DIR = ft_printf/
PRINTF = $(PRINTF_DIR)libftprintf.a

CC = cc

HEADERS = $(PRINTF_DIR)ft_printf.h $(LIBFT_DIR)libft.h

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME): $(LIBFT) $(PRINTF) $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_OBJ) -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@

clean:
	make -C $(PRINTF_DIR) clean
	rm -f $(PUSH_SWAP_OBJ)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test
