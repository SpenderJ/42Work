# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebossue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/28 15:53:25 by jebossue          #+#    #+#              #
#    Updated: 2018/08/20 11:40:28 by sgauguet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCDIR		= printf
LIBDIR		= .

OBJDIR		= objs
OBJLIBDIR	= objs

INCDIR		= includes

INCNAM = ft_printf.h libft.h get_next_line.h
INC = $(INCNAM:%=$(INCDIR)/%)

SRCNAM	= ft_printf.c ft_check_params.c ft_check_specifier.c ft_digit_len.c\
		  ft_size_ln.c ft_write_on_buff.c ft_write_numbers.c\
		  ft_write_dec_flags.c ft_handle_width_pre.c ft_write_letters.c\
		  ft_handle_str_width_pre.c ft_utf8.c ft_free_printf.c\
		  ft_set_param.c\

SRC		= $(SRCNAM:%=$(SRCDIR)/%)
SRC_LIB = $(LIBFTNAM:%=$(LIBDIR)/%)

OBJ		= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJ_LIB = $(SRC_LIB:$(LIBDIR)/%.c=$(OBJLIBDIR)/%.o)


CC		= clang
CFLAGS	= -Wall -Wextra -Werror -I$(INCDIR)

LIBFTNAM	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_putchar.c ft_putstr.c ft_strlen.c ft_memchr.c ft_memcmp.c ft_strdup.c \
	  ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
	  ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c \
	  ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	  ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c \
	  ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_isascii.c\
	  ft_isprint.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c\
	  ft_strsub.c ft_strndup.c ft_strjoin.c ft_strtrim.c ft_strsplit.c\
	  ft_itoa.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
	  ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c\
	  ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strtab.c\
	  ft_bzerocustom.c ft_setcustomtab.c ft_memadd.c ft_base_digitlen.c\
	  ft_utf8_len.c ft_uitoa.c ft_abs.c ft_itoa_base.c ft_print_bit.c\
	  ft_nbrwords.c ft_isnbr.c ft_atoi_long.c ft_isint.c ft_isdoublon.c\
	  get_next_line.c ft_memchrint.c ft_strarraycmp.c ft_gnlmemcpy.c\
	  ft_str_isdigit.c ft_lst_push_back.c ft_nrealloc.c

GIT	= README.md

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIB)
	@echo "Compilation \033[36mOf Libft\033[0m: [\033[32mcompleted\033[0m]"
	@ar rc $@ $^
	@ranlib $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $< $(CFLAGS)

$(OBJLIBDIR)/%.o: $(LIBDIR)/%.c $(INC)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all git no printf check clean fclean re $(LIBFT)

git:
	git add $(SRC) $(INC) $(GIT)

no:
	@echo "Passage de la norminette :"
	@norminette $(SRC) $(INC)

printf:
	@echo "Detection des printf :\033[1;31m"
	@grep printf -r $(SRCDIR) $(INCDIR) | cat
	@printf "\033[0m"

check: no printf

clean:
	@rm -rf $(OBJDIR) $(OBJLIBDIR)

fclean: clean
	@rm -rf $(NAME)

# $(MAKE) needed so that the cleaning is done before starting to create again \
	# 	# cf make -j 
re: fclean
	$(MAKE) all
