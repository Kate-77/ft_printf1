# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 14:04:13 by kmoutaou          #+#    #+#              #
#    Updated: 2021/11/28 18:16:10 by kmoutaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= libftprintf.a

CC			= cc

FLAGS		= -Wall -Wextra -Werror

SRCS		= ft_printf.c \
			  ft_printfunc0.c \
			  ft_printfunc1.c \

OBJS		= $(SRCS:.c=.o)

HEADERS		= .

all: 		$(NAME)

$(NAME):	$(OBJS)

%.o: %.c
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I $(HEADERS)
			ar rcs $(NAME) ${<:.c=.o}

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

.PHONY: 	all re clean fclean
