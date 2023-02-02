# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 22:54:28 by htalhaou          #+#    #+#              #
#    Updated: 2023/02/02 16:19:04 by htalhaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT    = client

NAME_CLIENT_BONUS    = client_bonus

NAME_SERVER    = server

NAME_SERVER_BONUS    = server_bonus

CC = gcc

CFLAGS   = -Wall -Wextra -Werror 
	
RM        = rm -rf

PRINTF = ft_printf/libftprintf.a

all: $(NAME_CLIENT) $(NAME_SERVER)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_CLIENT): client.c $(PRINTF)
	$(CC) $(CFLAGS) client.c $(PRINTF) -o $(NAME_CLIENT)

$(NAME_CLIENT_BONUS): client.c $(PRINTF)
	$(CC) $(CFLAGS) client.c $(PRINTF) -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER): server.c $(PRINTF)
	$(CC) $(CFLAGS) server.c $(PRINTF) -o $(NAME_SERVER)

$(NAME_SERVER_BONUS): server.c $(PRINTF)
	$(CC) $(CFLAGS) server.c $(PRINTF) -o $(NAME_SERVER_BONUS)

$(PRINTF): 
	@make -C ft_printf/

clean:
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	@make clean -C ft_printf/

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	@make fclean -C ft_printf/

re:fclean all

.PHONY:fclean all clean re