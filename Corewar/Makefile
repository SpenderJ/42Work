FLAG = -Wall -Wextra -Werror

SRCS_GEN = LIBFT/ft_atoi.c \
		   LIBFT/ft_strndup.c \
		   LIBFT/ft_strdup.c \
		   LIBFT/ft_strdel.c \
		   LIBFT/get_next_line.c \
		   LIBFT/ft_strcmp.c \
		   LIBFT/malloc_tabtab.c \
		   LIBFT/ft_memdel.c \
		   LIBFT/ft_memmove.c \
		   LIBFT/ft_strncmp.c \
		   LIBFT/ft_strlen.c \
		   LIBFT/ft_strsub.c \
		   LIBFT/ft_strjoin.c \
		   LIBFT/ft_strchr.c \
		   LIBFT/ft_put.c \
		   LIBFT/ft_strsplit.c \
		   LIBFT/ft_itoa_base.c

OBJ_GEN =	$(SRCS_GEN:.c=.o)	

NAME_ASM = 	asm

SRCS_ASM  = SRCS_ASM/utils.c \
			SRCS_ASM/errors.c \
			SRCS_ASM/ins.c \
			SRCS_ASM/ins2.c \
			SRCS_ASM/ins3.c \
			SRCS_ASM/ins4.c \
			SRCS_ASM/ins5.c \
			SRCS_ASM/ins6.c \
			SRCS_ASM/ins7.c \
			SRCS_ASM/ins8.c \
			SRCS_ASM/ft_opdir.c \
			SRCS_ASM/ft_label.c \
			SRCS_ASM/ft_label2.c \
			SRCS_ASM/write.c \
			SRCS_ASM/check_head.c \
			SRCS_ASM/check_ins.c \
			SRCS_ASM/check_ins2.c \
			SRCS_ASM/check_filedots.c \
			SRCS_ASM/check_code.c \
			SRCS_ASM/main.c \
			$(SRCS_GEN)

OBJ_ASM = $(SRCS_ASM:.c=.o)

all: $(NAME_ASM) $(NAME_VMA)

WORK:	$(OBJ_GEN)
	@ echo "🚧  \033[33mWORK IN PROGRESS\033[0m 🚧"

$(NAME_ASM): WORK $(OBJ_ASM)
	@gcc $(FLAG) -o $(NAME_ASM) $(OBJ_ASM)
	@ echo "Compilation \033[36mASM\033[0m: [\033[32mcompleted\033[0m]"

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $^

clean:
	@rm -f $(OBJ_ASM)

fclean: clean
	@rm -f $(NAME_ASM)

re : fclean all

norme :
	/usr/bin/norminette LIBFT/*.[ch] SRCS_ASM/*.[ch] includes/*.[h]

.PHONY: all, clean, fclean, re, WORK, norme
