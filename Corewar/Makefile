EXE_VM = corewar
EXE_ASM = asm
EXE_DESA = desassembleur

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iincludes -g
NFLAGS = -lncurses
LFLAGS = -Llibft -lft

OBJ_PATH = obj
SRC_PATH = src
VM_PATH = vm
ASM_PATH = asm
DESA_PATH = desa


VM_NAME = add.c\
		  aff.c\
		  and.c\
		  dump.c\
		  fork.c\
		  ft_free.c\
		  ft_init_champ.c\
		  ft_init_checkarg_2.c\
		  ft_init_flags.c\
		  ft_init_map.c\
		  ft_init_print.c\
		  ft_init_process.c\
		  ft_init_strklcmp.c\
		  ft_init_vm.c\
		  get_params.c\
		  get_values.c\
		  gui_print_map.c\
		  gui_start.c\
		  gui_stat.c\
		  gui_top.c\
		  ld.c\
		  ldi.c\
		  lfork.c\
		  live.c\
		  lld.c\
		  lldi.c\
		  main.c\
		  op.c\
		  or.c\
		  play_game.c\
		  play_game_gui.c\
		  st.c\
		  sti.c\
		  sub.c\
		  xor.c\
		  zjump.c\

ASM_NAME = add_null_terminator.c\
		   ft_init_strklcmp.c\
		   copy_section.c\
		   free_env.c\
		   init.c\
		   interpret.c\
		   interpret2.c\
		   interpret3.c\
		   labels.c\
		   main.c\
		   parse.c\
		   parse_commands.c\
		   parse_header.c\
		   reader.c\
		   utils.c\
		   verify_op.c\
		   op.c

DESA_NAME = desa.c\
			ft_add_intro.c\
			ft_autre.c\
			ft_itoa.c\
			ft_join.c\
			ft_libft.c\
			ft_param.c\
			ft_puthexa.c\
			ft_strcat.c\
			ft_strcatf.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strjoin_fs1.c\
			ft_strjoin_fs1s2.c\
			ft_strjoin_fs1s2v.c\
			ft_strsplit.c\
			ft_write.c\

HEADER_NAME = corewar.h\
			  ft_init.h\
			  gui.h\
			  instructions.h\
			  libft.h\
			  op.h\
			  play_game.h\
			  desa.h\

VM_OBJ_NAME = $(VM_NAME:.c=.o)
ASM_OBJ_NAME = $(ASM_NAME:.c=.o)
DESA_OBJ_NAME = $(DESA_NAME:.c=.o)

HEADER_SRC = $(addprefix includes/, $(HEADER_NAME))

VM_SRC = $(addprefix $(SRC_PATH)/$(VM_PATH)/, $(VM_NAME))
ASM_SRC = $(addprefix $(SRC_PATH)/$(ASM_PATH)/, $(ASM_NAME))
DESA_SRC = $(addprefix $(SRC_PATH)/$(DESA_PATH)/, $(DESA_NAME))
VM_OBJ = $(addprefix $(OBJ_PATH)/$(VM_PATH)/, $(VM_OBJ_NAME))
ASM_OBJ = $(addprefix $(OBJ_PATH)/$(ASM_PATH)/, $(ASM_OBJ_NAME))
DESA_OBJ = $(addprefix $(OBJ_PATH)/$(DESA_PATH)/, $(DESA_OBJ_NAME))

all: libft $(OBJ_PATH) $(EXE_VM) $(EXE_ASM) $(EXE_DESA)

libft:
	Make -C libft

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)/$(VM_PATH)
	@mkdir -p $(OBJ_PATH)/$(ASM_PATH)
	@mkdir -p $(OBJ_PATH)/$(DESA_PATH)
	@echo "All directories have been created"

$(EXE_VM): $(VM_OBJ)
	@$(CC) $(CFLAGS) $(LFLAGS) $(NFLAGS) $^ -o $@
	@echo "Virtual Machine has been compiled"

$(EXE_ASM): $(ASM_OBJ)
	@$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@
	@echo "Assembleur has been compiled"

$(EXE_DESA): $(DESA_OBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "Desassembleur has been compiled"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	Make -C libft clean
	@rm  -rf $(OBJ_PATH)
	@echo "All objects have been deleted"

fclean: clean
	Make -C libft fclean
	@rm -f $(EXE_VM) $(EXE_ASM) $(EXE_DESA)
	@echo "VM, Assembleur and Desassembleur have been deleted"

re: fclean all

norme:
	norminette $(VM_SRC) $(ASM_SRC) $(DESA_SRC) $(HEADER_SRC)

.PHONY: all, clean, fclean, re, norme, libft
