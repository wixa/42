# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarr <msarr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 14:52:23 by sraccah           #+#    #+#              #
#    Updated: 2014/02/24 11:55:22 by sraccah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

MAKE = make
CC = gcc
RM = /bin/rm
LDIR = libft/
SDIR = srcs/

SRC = $(SDIR)ft_addlist.c $(SDIR)ft_sortlist.c $(SDIR)ft_getdirlist.c \
		$(SDIR)ft_putattr.c $(SDIR)ft_put_s.c $(SDIR)ft_ls.c \
		$(SDIR)ft_parse.c $(SDIR)ft_putinfos.c $(SDIR)main.c\


OBJ = $(SRC:.c=.o)
INC = -I includes -I $(LDIR)includes
LIB = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[31;1m"
	@echo -n '---> Creating the Libft... <---'
	@echo "\033[0m"
	$(MAKE) re -C $(LDIR)
	@echo "\033[31;1m"
	@echo -n '---> Compilation in progress... <---'
	@echo "\033[0m"
	$(CC) $(CFLAGS) $(INC) $^ -o $(NAME) $(LIB)
	$(CC) $(CFLAGS) $(INC) $^ -o $(NAME) $(LIB) -ltermcap
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

%.o:%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo "\033[31;1m"
	@echo -n '---> Clean : <---'
	@echo "\033[0m"
	$(RM) -rf $(OBJ)
	$(MAKE) clean -C $(LDIR)
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

fclean: clean
	@echo "\033[31;1m"
	@echo -n '---> FClean : <---'
	@echo "\033[0m"
	$(RM) -rf $(NAME)
	$(MAKE) fclean -C $(LDIR)
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

re: fclean all

.PHONY: all name clean fclean re