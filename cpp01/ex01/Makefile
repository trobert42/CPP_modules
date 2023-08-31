# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trobert <trobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 17:38:12 by trobert           #+#    #+#              #
#    Updated: 2022/11/12 18:36:17 by trobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	Zombie.cpp\
		zombieHorde.cpp\
		main.cpp\

SRCS = ${SRC}

OBJS = ${SRCS:.cpp=.o}

NAME = more_brainz

CC = c++

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} 

.cpp.o:
	${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 
re: fclean all

.PHONY: clean fclean bonus all re
