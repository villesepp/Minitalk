# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#   By: vseppane <vseppane@student.hive.fi>        +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 13:06:17 by vseppane          #+#    #+#              #
#    Updated: 2024/10/10 13:54:45 by vseppane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#                    .__      ___.   .__
# ___  ______ _______|__|____ \_ |__ |  |   ____   ______
# \  \/ |__  \\_  __ \  \__  \ | __ \|  | _/ __ \ /  ___/
#  \   / / __ \|  | \/  |/ __ \| \_\ \  |_\  ___/ \___ \
#   \_/ (____  /__|  |__(____  /___  /____/\___  >____  >
#            \/              \/    \/          \/     \/

CLNAME 		:=	client
SRNAME 		:=	server
CC 			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
LFT			:=  libft/libft.a
LIB			:=  -L ./libft -lft


#   __________  __ _________  ____  ____   ______
#  /  ___/  _ \|  |  \_  __ \/ ___\/ __ \ /  ___/
#  \___ (  <_> )  |  /|  | \|  \__\  ___/ \___ \
# /____  >____/|____/ |__|   \___  >___  >____  >
#      \/                        \/    \/     \/

CLSOURCES =	client.c \ client_utils.c
SRSOURCES =	server.c \ server_utils.c

CLOBJECTS = $(CLSOURCES:.c=.o)
SROBJECTS = $(SRSOURCES:.c=.o)

#   __                              __          
# _/  |______ _______  ____   _____/  |_  ______
# \   __\__  \\_  __ \/ ___\_/ __ \   __\/  ___/
#  |  |  / __ \|  | \/ /_/  >  ___/|  |  \___ \ 
#  |__| (____  /__|  \___  / \___  >__| /____  >
#            \/     /_____/      \/          \/ 

%.o: %.c
			$(CC) -c $(CFLAGS) $?

all: 		$(LFT) $(CLNAME) $(SRNAME)

$(LFT):
			make -C libft bonus

$(CLNAME):	$(CLOBJECTS)
			cc -o $@ $^ $(LIB)


$(SRNAME):	$(SROBJECTS)
			cc -o $@ $^ $(LIB)

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
