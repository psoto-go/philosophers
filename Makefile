# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 16:57:12 by psoto-go          #+#    #+#              #
#    Updated: 2023/01/24 19:32:54 by psoto-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			:=	srcs/philosophers.c srcs/parser.c srcs/ft_errors.c \
					utils/ft_isdigit.c utils/ft_atol.c utils/ft_atoi.c \
					srcs/philos.c

OBJS			:= $(SRCS:.c=.o)

BONUS			:=	

BONUS_OBJS		:= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
CFLAGSANI		= -Wall -Wextra -Werror -fsanitize=address -g3
NAME			= philo

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

sani:			$(OBJS)
				$(CC) $(CFLAGSANI) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus: 			$(BONUS_OBJS)
				@$(MAKE) OBJS="$(BONUS_OBJS)" all

sanibonus:		$(BONUS_OBJS)
				$(CC) $(CFLAGSANI) $(BONUS_OBJS) -o $(NAME)

.PHONY:			all clean fclean re bonus