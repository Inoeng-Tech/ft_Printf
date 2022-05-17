# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afridasufi <afridasufi@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 17:33:25 by afridasufi        #+#    #+#              #
#    Updated: 2022/04/26 12:10:38 by afridasufi       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I./libft
SRCS	=	ft_printf.c convert.c
OBJS	=	${SRCS:.c=.o}
RM 		=	rm -rf
OPTION 	= 	-c

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(OPTION) $(SRCS)
	ar -rc $(NAME) $(OBJS)

clean:
	${RM} ${OBJS} $(BONUS_OBJS)
	${RM} */*.o

fclean: clean
	${RM} $(NAME)
	${RM} Libft/libft.a

re: fclean all

.PHONY:	all clean fclean re
