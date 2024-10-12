# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 13:06:17 by vseppane          #+#    #+#              #
#    Updated: 2024/10/12 12:31:26 by vseppane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#  v a r i a b l e s

CLNAME 		:=	client
SRNAME 		:=	server
CC 			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
LFT			:=  libft/libft.a
LIB			:=  -L ./libft -lft

#  s o u r c e s

CLSOURCES =	client.c \
			client_utils.c

SRSOURCES =	server.c \
			server_utils.c

CLOBJECTS = $(CLSOURCES:.c=.o)
SROBJECTS = $(SRSOURCES:.c=.o)

#  t a r g e t s

%.o: %.c
			$(CC) -c $(CFLAGS) $< -o $@

all: 		$(LFT) $(CLNAME) $(SRNAME)

$(LFT):
			make -C libft bonus

$(CLNAME):	$(CLOBJECTS)
			$(CC) $(CFLAGS) $(CLOBJECTS) $(LIB) -o $(CLNAME)

$(SRNAME):	$(SROBJECTS)
			$(CC) $(CFLAGS) $(SROBJECTS) $(LIB) -o $(SRNAME)

clean:		
			make $@ -C libft
			rm -f $(CLOBJECTS)
			rm -f $(SROBJECTS)

fclean:		clean
			make $@ -C libft
			rm -f $(CLNAME)
			rm -f $(SRNAME)

re:			fclean all

.PHONY: 	all clean fclean re
