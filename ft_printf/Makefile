# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 16:20:34 by aelbouaz          #+#    #+#              #
#    Updated: 2025/12/23 15:44:58 by aelbouaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror


PRINTF_SRCS = ft_printf.c check_char.c check_intd.c check_inti.c \
	check_string.c check_pointer.c check_hexa_upper.c check_hexa_lower.c \
	check_unsign_int.c check_percent.c

PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

NAME = libftprintf.a
LIBFT_DIR  := ./libft
LIBFT  := $(LIBFT_DIR)/libft.a

INCLUDES = -I . -I $(LIBFT_DIR)

CC = cc
MAKE = make

HEADERS = ft_printf.h $(LIBFT_DIR)/libft.h

GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m

all: MSG $(NAME)

MSG:
	@printf "$(GREEN)Compiling ft_printf$(RESET)"

%.o: %.c Makefile
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(GREEN).$(RESET)"

$(NAME): $(PRINTF_OBJS) $(LIBFT)
	@ar rcs $(NAME) $(PRINTF_OBJS)
	@printf "\n"

libft:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

clean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@rm -rf $(PRINTF_OBJS)

fclean: clean
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft bonus
