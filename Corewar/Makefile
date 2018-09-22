# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebossue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/09 17:54:20 by jebossue          #+#    #+#              #
#    Updated: 2018/08/20 18:48:08 by aserguie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN =		\033[1;32m

RED =		\033[1;31m

RES =		\033[0m

#------------------------------------------------------------------------------#

NAME_ASM =		asm

NAME_VMA =		corewar

SRCS_ASM =		utils.c \
				errors.c \
				ins.c \
				ins2.c \
				ins3.c \
				ins4.c \
				ins5.c \
				ins6.c \
				ins7.c \
				ins8.c \
				ft_opdir.c \
				ft_label.c \
				ft_label2.c \
				write.c \
				check_head.c \
				check_ins.c \
				check_ins2.c \
				check_filedots.c \
				check_code.c \
				main.c \
				put.c \
				malloc_tabtab.c \
				loop.c

SRCS_VMA =		vm_main.c \
				vm_initialization.c \
				vm_options.c \
				vm_options_2.c \
				vm_create_players.c \
				vm_check_players.c \
				vm_load_players.c \
				vm_create_process.c \
				vm_exec_process.c \
				vm_destroy_process.c \
				vm_instructions_size.c \
				vm_exec_instructions.c \
				vm_exec_functions.c \
				vm_exec_functions_2.c \
				vm_display_messages.c \
				vm_display_options.c \
				vm_display_arena.c \
				vm_visu_0.c \
				vm_visu_1.c \
				vm_display_errors.c \
				vm_debug.c \
				exec_live.c \
				exec_st.c \
				exec_ld.c \
				exec_lld.c \
				exec_ldi.c \
				exec_lldi.c \
				exec_and.c \
				exec_zjmp.c \
				exec_sti.c \
				exec_fork.c \
				exec_lfork.c \
				exec_aff.c \
				exec_or.c \
				exec_xor.c \
				exec_add.c \
				exec_sub.c


SRCDIR_ASM =	./srcs_asm

SRCDIR_VMA =	./srcs_vma

OBJ_ASM =		$(SRCS_ASM:%.c=$(OBJDIR_ASM)/%.o)

OBJ_VMA =		$(SRCS_VMA:%.c=$(OBJDIR_VMA)/%.o)

OBJDIR_ASM =	./objs_asm

OBJDIR_VMA =	./objs_vma

HEADER =	$(INCDIR)/corewar.h	\
			$(INCDIR)/op.h		\

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

asm_compil:
	@$(MAKE) -C ./libft all
	@$(MAKE) $(NAME_ASM)

vma_compil:
	@$(MAKE) -C ./libft all
	@$(MAKE) $(NAME_VMA)
	
libft:
	@$(MAKE) -C ./libft all
	@$(MAKE) $(NAME_ASM) $(NAME_VMA)

$(NAME_ASM): $(OBJ_ASM)
	@echo "[$(GREEN)Ok$(RES)] Compiling : "$@
	@$(CC) -g $(FLAGS) $(OBJ_ASM) -o $@ $(LFLAGS)
	@echo "Compilation done !"

$(OBJDIR_ASM)/%.o: $(SRCDIR_ASM)/%.c $(HEADER)
	@mkdir -p $(OBJDIR_ASM)
	@echo "[$(GREEN)Ok$(RES)] Compiling : "$@
	@$(CC) -g $(FLAGS) -o $@ -c $<

$(NAME_VMA): $(OBJ_VMA)
	@echo "[$(GREEN)Ok$(RES)] Compiling : "$@
	@$(CC) -g $(FLAGS) $(OBJ_VMA) -o $@ $(LFLAGS)
	@echo "Compilation done !"

$(OBJDIR_VMA)/%.o: $(SRCDIR_VMA)/%.c $(HEADER)
	@mkdir -p $(OBJDIR_VMA)
	@echo "[$(GREEN)Ok$(RES)] Compiling : "$@
	@$(CC) -g $(FLAGS) -o $@ -c $<

clean:
	@echo "Cleaning"
	@rm -rf $(OBJDIR_ASM)
	@rm -rf $(OBJDIR_VMA)
	@$(MAKE) -C ./libft clean

fclean: clean
	@rm -rf $(NAME_VMA)
	@rm -rf $(NAME_ASM)
	@$(MAKE) -C ./libft fclean

re: fclean
	@$(MAKE) all

#------------------------------------------------------------------------------#

norm:
	@echo "Passage de la norminette : $(RED)"
	@norminette $(SRCDIR) $(INCDIRS) $(LIBDIR) | grep -B1 Error | cat

git:
	@git add Makefile $(SRCDIR) $(INCDIR) auteur libft

.PHONY: all clean re fclean git no printf check libft asm_compil vma_compil
