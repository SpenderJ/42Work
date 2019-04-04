# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juspende <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:29:44 by juspende          #+#    #+#              #
#    Updated: 2019/04/03 20:39:15 by juspende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN =		\033[1;32m

RED =		\033[1;31m

RES =		\033[0m

#------------------------------------------------------------------------------#

NAME	 =		ft_ssl

SRCS	 =		ft_ssl.c		\
				get_next_line.c	\

SRCDIR	 =	./srcs

OBJ		 =		$(SRCS:%.c=$(OBJDIR)/%.o)

OBJDIR 	=	./objs

HEADER =	$(INCDIR)/ft_ssl.h	\

#------------------------------------------------------------------------------#

INCDIR =	./includes

LIBINCDIR =	./libft/includes

LIBDIR =	./libft

#------------------------------------------------------------------------------#

CC =		gcc

CFLAGS =	-Wall \
			-Wextra \
			-Werror \
			#-fsanitize=address

INCFLAGS =	-I $(INCDIR)	\
			-I $(LIBINCDIR)

LFLAGS =	-L $(LIBDIR) -lft -lncurses

FLAGS =		$(CFLAGS)		\
		$(INCFLAGS)

#------------------------------------------------------------------------------#

all: libft

compil:
	@$(MAKE) -C ./libft all
	@$(MAKE) -C ./free_all/
	@$(MAKE) $(NAME)

libft:
	@$(MAKE) -C ./libft all
	@$(MAKE) -C ./free_all/
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	@echo "[$(GREEN)Ok$(RES)] Compiling : "$@
	@$(CC) -g $(FLAGS) $(OBJ) -o $@ $(LFLAGS) ./free_all/libfree.a
	@echo "Compilation done !"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@mkdir -p $(OBJDIR)
	@echo "[$(GREEN)Ok$(RES)] Compiling : "$@
	@$(CC) -g $(FLAGS) -o $@ -c $<

clean:
	@echo "Cleaning"
	@rm -rf $(OBJDIR)
	@$(MAKE) -C ./libft clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C ./libft fclean

re: fclean
	@$(MAKE) all

#------------------------------------------------------------------------------#

norm:
	@echo "Passage de la norminette : $(RED)"
	@norminette $(SRCDIR) $(INCDIRS) $(LIBDIR) | grep -B1 Error | cat

git:
	@git add Makefile $(SRCDIR) $(INCDIR) auteur libft

.PHONY: all clean re fclean git no printf check libft
