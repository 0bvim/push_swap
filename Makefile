# program name #
NAME = push_swap

# shell #
SHELL := /bin/bash

# misc #
COUNT := 0
SLEEP := sleep 0.2

# colors #
BLACK  		 = \033[0;30m
RED    		 = \033[0;31m
GREEN  		 = \033[0;32m
YELLOW 		 = \033[0;33m
BLUE   		 = \033[0;34m
MAGENTA		 = \033[0;35m
CYAN   		 = \033[0;36m
WHITE  		 = \033[0;37m
RESET  		 = \033[0m

# messages #
MANDATORY = Program compiled
LBONUS = Bonus Program compiled
CLEAN = Objects delete
FCLEAN = Program delete
LIBNAME = push_swap
BLIBNAME = push_swap_bonus
COMP = Compiling

# debug and normal flags #
DFLAGS = -Wall -Wextra -Werror -g3 # TO DEBBUG
CFLAGS = -Wall -Werror -Wextra -g3 -Ofast -flto -MD -MP -fsanitize=address # TO IMPROVE PERFORMANCE
LFLAGS = -march=native # TO OPTIMIZE FOR SPECIFIC ARCHITECTURE

# paths #
SRC = src
BONUS = src/bonus
INC = includes
OBJ = obj

# files path #
VALIDATIONS = $(SRC)/validations
MOVIMENTATION = $(SRC)/movimentation
NODES = $(SRC)/nodes
SORT = $(SRC)/sorting
ENTRANCE = $(SRC)/entrance

# libs #
INCLUDES = -I$(INC)/ -Ilib/libft/includes/
LINCLUDES = -L$(LIBFT_PATH) -lft

LIBFT = lib/libft/libft.a
LIBFT_PATH = lib/libft

# files #
CFILES = $(addprefix $(ENTRANCE)/, main.c stack_init.c)
CFILES += $(addprefix $(VALIDATIONS)/, validations.c)
CFILES += $(addprefix $(MOVIMENTATION)/, push.c rev_rotate.c rotate.c swap.c)
CFILES += $(addprefix $(NODES)/, nodes.c)
CFILES += $(addprefix $(SORT)/, tiny_sort.c is_sorted.c find_highest.c)

BFILES = $(addprefix $(BONUS)/, main_bonus.c)

VAL_TXT = valgrind-out.txt

# obj dir #
OBJECT =  $(CFILES:%.c=$(OBJ)/%.o)

# define bonus #
ifdef WITH_BONUS
	NAME = $(BLIBNAME)
	CFILES = $(BFILES)
	SRC = $(BONUS)
	MANDATORY = $(LBONUS)
	MAGENTA = $(YELLOW)
	LIBNAME = $(BLIBNAME)
endif

# define debbug #
ifdef WITH_DEBBUG
	CFLAGS = $(DFLAGS)
endif

# functions #
define create_objects_dir
	@mkdir -p $(dir $@)
endef

define compile
	@$(CC) -o $(NAME) $(CFLAGS) $(LFLAGS) $(INCLUDES) $(LINCLUDES) $(OBJECT) $(LIBFT)
	@$(SLEEP)
	@printf "\n$(MAGENTA)$(MANDATORY)\n$(RESET)"
endef

define compile_source
	@$(eval COUNT=$(shell expr $(COUNT) + 1))
	@$(MAKE) -sC $(LIBFT_PATH)
	@$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<
	@printf "$(GREEN)$(LIBNAME) $(COMP) %d%%\r$(RESET)" $$(echo $$(($(COUNT) * 100 / $(words $(CFILES)))))
endef

define clean
	@$(MAKE) fclean -sC $(LIBFT_PATH)
	@$(RM) -rf $(OBJ)/ && $(RM) -rf $(VAL_TXT)
	@$(SLEEP)
	@printf "$(RED)$(CLEAN)$(RESET)\n"
endef

define fclean
	$(call eraseBins)
	@$(SLEEP)
	@printf "$(RED)$(FCLEAN)$(RESET)\n"
endef

define bonus
	@make WITH_BONUS=TRUE -s
endef

define debug
	$(call clean)
	$(call fclean)
	@$(MAKE) WITH_DEBBUG=TRUE -s
endef

define eraseBins
	$(if $(NAME),@$(RM) $(NAME))
	$(if $(BLIBNAME),@$(RM) $(BLIBNAME))
endef

define help
	@echo -e "$(GREEN)Available targets:$(RESET)"
	@echo -e "$(CYAN)all:$(RESET) $(YELLOW)Build the program$(RESET)"
	@echo -e "$(CYAN)clean:$(RESET) $(RED)Remove the object files$(RESET)"
	@echo -e "$(CYAN)fclean:$(RESET) $(RED)Remove the program and the object files$(RESET)"
	@echo -e "$(CYAN)re:$(RESET) $(YELLOW)Rebuild the program$(RESET)"
	@echo -e "$(CYAN)bonus:$(RESET) $(MAGENTA)Build the bonus program$(RESET)"
	@echo -e "$(CYAN)debug:$(RESET) $(WHITE)Build the program with debugging information$(RESET)"
endef

# rules #
all: $(NAME)

$(NAME): $(OBJECT)
	$(call create_objects_dir)
	$(call compile)

$(OBJ)/%.o: %.c
	$(call create_objects_dir)
	$(call compile_source)

-include $(OBJECT:.o=.d)

clean:
	$(call clean)

fclean: clean
	$(call fclean)

re: fclean all

bonus:
	$(call bonus)

debug:
	$(call debug)

help:
	$(call help)

.PHONY: all bonus clean fclean re debug help Makefile
.DEFAULT_GOAL := all
