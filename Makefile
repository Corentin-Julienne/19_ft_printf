# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 14:26:33 by cjulienn          #+#    #+#              #
#    Updated: 2021/06/22 15:49:03 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ./srcs/ft_printf.c \
	   ./srcs/ft_find_format.c \
	   ./srcs/ft_eval_flags.c \
	   ./srcs/ft_conversions_1.c \
	   ./srcs/ft_conversions_2.c \
	   ./srcs/ft_conversions_utils.c 

OBJS = ${SRCS:.c=.o}

INCLUDES = ./includes/

LIBFT_PATH = ./libft/
LIBFT_NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.$(INCLUDES)

RM = rm -f
AR = ar -rcs

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	$(OBJS)
		$(MAKE) all -C $(LIBFT_PATH)
		$(AR) $(NAME) $(OBJS) $(LIBFT_PATH)$(LIBFT_NAME)
		
clean:	
	$(MAKE) clean -C ${LIBFT_PATH}
	${RM} ${OBJS}

fclean:	clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	${RM} ${NAME}
		
re:	fclean all

.PHONY:	all clean fclean re
