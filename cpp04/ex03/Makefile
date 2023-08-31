# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trobert <trobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 22:23:07 by trobert           #+#    #+#              #
#    Updated: 2022/12/27 17:16:07 by trobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	a.out

SRCS_FILES =	AMateria.cpp \
				Character.cpp \
				Cure.cpp \
				Ice.cpp \
				main.cpp \
				MateriaSource.cpp

INC_FILES	=	AMateria.hpp \
				Character.hpp \
				Cure.hpp \
				Ice.hpp \
				ICharacter.hpp \
				IMateriaSource.hpp \
				MateriaSource.hpp

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