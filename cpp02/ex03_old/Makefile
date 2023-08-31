# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trobert <trobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 11:17:11 by trobert           #+#    #+#              #
#    Updated: 2022/12/22 15:06:20 by trobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.cpp\
		Fixed.cpp\
		Point.cpp\
		bsp.cpp\

SRCS = ${SRC}

OBJS = ${SRCS:.cpp=.o}

NAME = triangle

CC = c++

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: ${NAME} Fixed.hpp Point.hpp

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} 

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
z
re: fclean all

.PHONY: clean fclean bonus all re
