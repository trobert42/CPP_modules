# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trobert <trobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 19:26:44 by trobert           #+#    #+#              #
#    Updated: 2022/12/27 17:18:39 by trobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	a.out

SRCS_FILES =	main.cpp \
				AAnimal.cpp \
				Cat.cpp \
				Dog.cpp \
				Brain.cpp

INC_FILES	=	AAnimal.hpp \
				Cat.hpp \
				Dog.hpp \
				Brain.hpp \

SRCS	=	$(addprefix srcs/, $(SRCS_FILES))

INCS	=	$(addprefix includes/, $(INC_FILES))

CC	=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3

OBJS_FILES	=	$(SRCS_FILES:%.cpp=%.o)

OBJS	=	$(addprefix objs/, $(OBJS_FILES))

DEP	=	$(OBJS:%.o=%.d)

all	:	$(NAME)

$(NAME) :	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
		rm -rf $(OBJS) $(DEP)
		rm -rf objs/

fclean : clean
		rm -rf $(NAME)

re :	fclean all

objs/%.o :	srcs/%.cpp $(INCS)
		mkdir -p objs
		$(CC) $(CFLAGS) -MMD -o $@ -c $<

.PHONY: all clean fclean re