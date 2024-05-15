NAME := push_swap
BONUS_NAME := checker
OBJECT_DIR := obj
LIBFT_DIR := libft
INCLUDE_DIR := includes
SRC_DIR := srcs
BONUS_DIR := bonus
ARGS := -43 2 -51 233 444
FILES := main.c \
		 push_swap.c \
		 stack.c \
		 utils.c \
		 operations.c \
		 calculate_prices.c \
		 utils_algo.c \
		 move_algo_seperate.c \
		 move_rr_rrr.c \
		 ft_atoi_push_swap.c \
		 operations_rr_rrr.c
SRCS := $(addprefix $(SRC_DIR)/, $(FILES))
BONUS_FILES := checker_bonus.c
CFLAGS := -Wall -Wextra -Werror -g
IFLAGS := -I$(LIBFT_DIR) -I$(INCLUDE_DIR)
LFLAGS := -L$(LIBFT_DIR) -lft
OBJECTS := $(addprefix $(OBJECT_DIR)/,$(FILES:.c=.o))
OBJS_WITHOUT_MAIN := $(filter-out $(OBJECT_DIR)/main.o, $(OBJECTS))
BONUS_OBJ :=  $(addprefix $(BONUS_DIR)/,$(BONUS_FILES:.c=.o))
CC := gcc
ifeq ($(UNAME),Darwin)
	LEAK_TOOL := leaks -atExit --
else
	LEAK_TOOL := valgrind --leak-check=full
endif
END := "\033[0m"
WHITE := "\033[1;37m"
NC := \033[0m
PINK := "\033[1;35m"
GREEN := "\033[32m"
BOLD := "\033[1m"
L_PURPLE :="\033[38;5;55m"

.PHONY: all
all: $(NAME) display_ascii

$(NAME): $(OBJECTS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJECTS) $(LFLAGS) -o $(NAME)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(OBJECT_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJECT_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@


.PHONY: bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(NAME)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(OBJS_WITHOUT_MAIN) $(LFLAGS) -o $(BONUS_NAME)

.PHONY: re
re: fclean all

.PHONY: clean
clean:
	rm -rf $(OBJECT_DIR)
	rm -f $(BONUS_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

.PHONY: fclean
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: display_ascii
display_ascii:
	@echo $(BOLD)$(PINK); cat libft/ascii_art.txt; echo $(END)
	@echo $(BOLD)$(L_PURPLE) ✨Push_Swap✨ $(GREEN)is ready 🎉 $(END)


.PHONY: leak
leak: $(NAME)
	$(LEAK_TOOL) ./$(NAME) $(ARGS)
