# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtanner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 13:11:13 by jtanner           #+#    #+#              #
#    Updated: 2022/09/13 14:25:05 by jtanner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -f
LINKS = -I./includes -L./printf/includes -framework OpenGL \
	   	-framework Appkit

SRCS_DIR = srcs/

FILES = Main \
	ps \
	rot \
	sort3 \
	utils \
	sort5 \
	shortestroute \
	utils2 \
	sortutils \
	utils3 \
	sortplus \
	ft_split \

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) re -C ./printf
	$(CC) $(FLAGS) $(OBJS) printf/libftprintf.a -o $(NAME) $(LINKS)

$(OBJS): %.o : %.c
	gcc $(FLAGS) -c -o $@ $< 
	
clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C ./printf

fclean:	clean
	rm -f $(NAME)
	@$(MAKE) fclean -C ./printf

re: fclean all

.PHONY: re fclean clean

