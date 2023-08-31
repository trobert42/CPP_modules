# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trobert <trobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 15:01:38 by trobert           #+#    #+#              #
#    Updated: 2022/12/15 13:25:38 by trobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	megaphone.cpp

SRCS = ${SRC}

OBJS = ${SRCS:.cpp=.o}

INC = -I./includes

NAME = megaphone

CC = c++ -g

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${INC} -o ${NAME} 

.cpp.o:
	${CC} ${CFLAGS} ${INC} -c $< -o ${<:.cpp=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean bonus all re
