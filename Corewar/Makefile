# FLAG = -Wall -Wextra -Werror -g3 -fsanitize=address

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
		   LIBFT/ft_itoa_base.c \
		   LIBFT/ft_atoi_base.c \
		   LIBFT/ft_printf/ft_printf.c \
		   LIBFT/ft_printf/ft_format.c \
		   LIBFT/ft_printf/ft_create_params.c \
		   LIBFT/ft_printf/ft_set_params.c \
		   LIBFT/ft_printf/ft_override_params.c \
		   LIBFT/ft_printf/ft_override_length.c \
		   LIBFT/ft_printf/ft_prop_cast.c \
		   LIBFT/ft_printf/ft_is_s.c \
		   LIBFT/ft_printf/ft_is_d.c \
		   LIBFT/ft_printf/ft_is_c.c \
		   LIBFT/ft_printf/ft_is_u.c \
		   LIBFT/ft_printf/ft_is_o.c \
		   LIBFT/ft_printf/ft_is_p.c \
		   LIBFT/ft_printf/ft_is_x.c \
		   LIBFT/ft_printf/ft_is_cap_s.c \
		   LIBFT/ft_printf/ft_is_s_perc.c \
		   LIBFT/ft_printf/ft_unicode.c \
		   LIBFT/ft_printf/ft_precision.c \
		   LIBFT/ft_printf/ft_width.c \
		   LIBFT/ft_printf/ft_prepend_or_append.c \
		   LIBFT/ft_printf/ft_left_or_right.c \
		   LIBFT/ft_printf/ft_print_buffer.c \
		   LIBFT/ft_printf/src_printf_a.c \
		   LIBFT/ft_printf/src_printf_b.c \
		   LIBFT/ft_printf/src_printf_c.c \
		   LIBFT/ft_printf/src_printf_d.c


OBJ_GEN =	$(SRCS_GEN:.c=.o)	

NAME_VM = 	corewar

SRCS_VM  = 	SRCS_VM/main.c \
			SRCS_VM/utils.c \
			SRCS_VM/inner_parser.c \
			SRCS_VM/outer_parser.c \
			SRCS_VM/player_builder.c \
			SRCS_VM/player_builder_set_number.c \
			$(SRCS_GEN)

OBJ_VM = $(SRCS_VM:.c=.o)

all: $(NAME_VM) $(NAME_VMA)

WORK:	$(OBJ_GEN)
	@ echo "🚧  \033[33mWORK IN PROGRESS\033[0m 🚧"

$(NAME_VM): WORK $(OBJ_VM)
	@gcc $(FLAG) -o $(NAME_VM) $(OBJ_VM)
	@ echo "Compilation \033[36mVM\033[0m: [\033[32mcompleted\033[0m]"

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $^

clean:
	@rm -f $(OBJ_VM)

fclean: clean
	@rm -f $(NAME_VM)

re : fclean all

norme :
	/usr/bin/norminette LIBFT/*.[ch] SRCS_VM/*.[ch] includes/*.[h]

.PHONY: all, clean, fclean, re, WORK, norme
