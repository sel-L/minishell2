# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 19:16:04 by selow             #+#    #+#              #
#    Updated: 2025/12/13 00:19:46 by wshou-xi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -Ignl
CC = gcc
AR = ar rcs
RM = rm -f
INCS = libft.h

SRC =	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isdigit.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_putchar_fd.c \
	ft_memset.c \
	ft_memcpy.c \
	ft_memcmp.c \
	ft_memchr.c \
	ft_strrchr.c \
	ft_strlcpy.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strchr.c \
	ft_strtrim.c \
	ft_isalpha.c \
	ft_isalnum.c \
	ft_strnstr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_itoa.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_isascii.c \
	ft_split.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_isprint.c \
	ft_memmove.c \
	ft_strncmp.c \
	ft_strlcat.c \
	ft_putnbr_fd.c \
	gnl/get_next_line.c \
	
BONUSES =	ft_lstsize.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstadd_front.c \
		ft_lstadd_back.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstmap.c \

OBJS = $(SRC:.c=.o)

all: $(NAME) $(BONUS)

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

OBJS_BONUS = $(BONUSES:.c=.o)

bonus: $(OBJS_BONUS)
	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean bonus all clean
