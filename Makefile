# program name #
NAME = push_swap

# shell #
SHELL := /bin/bash

# misc #
COUNT := 0
SLEEP := sleep 0.2

# colors #
DEFAULT=\033[39m
BLACK=\033[30m
DARK_RED=\033[31m
DARK_GREEN=\033[32m
DARK_YELLOW=\033[33m
DARK_BLUE=\033[34m
DARK_MAGENTA=\033[35m
DARK_CYAN=\033[36m
LIGHT_GRAY=\033[37m
DARK_GRAY=\033[90m
RED=\033[91m
GREEN=\033[92m
ORANGE=\033[93m
BLUE=\033[94m
MAGENTA=\033[95m
CYAN=\033[96m
WHITE=\033[97m
BG_DEFAULT=\033[49m
BG_BLACK=\033[40m
BG_DARK_RED=\033[41m
BG_DARK_GREEN=\033[42m
BG_DARK_YELLOW=\033[43m
BG_DARK_BLUE=\033[44m
BG_DARK_MAGENTA=\033[45m
BG_DARK_CYAN=\033[46m
BG_LIGHT_GRAY=\033[47m
BG_DARK_GRAY=\033[100m
BG_RED=\033[101m
BG_GREEN=\033[102m
BG_ORANGE=\033[103m
BG_BLUE=\033[104m
BG_MAGENTA=\033[105m
BG_CYAN=\033[106m
BG_WHITE=\033[107m
RESET=\033[0m

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
CFLAGS = -Wall -Werror -Wextra -g3 -Ofast -flto -MD -MP # FOR DEPENDENCIES
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
CFILES = $(addprefix $(ENTRANCE)/, main.c stack_init.c sort_select.c free_all.c)
CFILES += $(addprefix $(VALIDATIONS)/, validations.c)
CFILES += $(addprefix $(MOVIMENTATION)/, push.c rev_rotate.c rotate.c swap.c \
finish_rotation.c move_nodes.c)
CFILES += $(addprefix $(NODES)/, nodes.c size.c init_node.c find.c \
current_position.c set_cheapest.c push_price.c target_node.c return_cheapest.c)
CFILES += $(addprefix $(SORT)/, tiny_sort.c is_sorted.c push_swap.c \
jackson_sort.c)

BFILES = $(addprefix $(BONUS)/, main_bonus.c)

VAL = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt
VAL_TXT = valgrind-out.txt
BEST_CASE = "441 427 431 46 63 149 40 7 168 426 487 33 403 251 467 94 181 222 70 339 13 25 116 36 34 196 324 266 55 91 236 415 256 216 397 228 212 231 336 254 375 376 165 326 226 37 260 126 295 215 209 109 118 78 439 481 134 351 477 372 102 341 250 106 285 195 345 235 71 197 206 489 482 76 242 15 167 276 204 267 334 155 137 81 483 498 434 115 310 233 54 182 129 390 42 432 105 370 18 389 497 387 422 20 417 464 141 398 304 185 359 474 158 371 32 203 3 451 221 50 457 307 463 291 28 490 272 311 103 67 346 484 161 393 440 208 38 74 461 410 379 300 56 187 205 229 65 170 140 327 485 369 488 472 14 360 248 119 340 255 112 261 469 386 23 53 270 473 445 162 98 1 363 2 253 58 223 337 107 342 305 366 153 287 227 124 5 368 213 331 64 143 338 373 478 163 178 318 421 316 160 290 268 265 51 452 132 139 45 218 444 365 470 145 333 367 404 292 133 298 171 220 437 188 4 343 180 136 388 391 31 357 62 455 17 315 108 332 9 321 446 364 97 44 381 122 459 60 49 16 278 383 26 159 110 453 164 127 104 75 154 92 374 201 173 411 354 186 348 442 400 408 319 85 172 150 210 277 240 443 288 471 412 111 169 479 48 330 117 29 281 0 82 219 52 183 347 87 142 147 493 476 428 377 123 450 262 286 406 335 39 80 356 433 420 308 407 297 151 11 413 328 69 350 190 249 496 352 499 362 394 59 79 448 402 27 414 238 303 232 401 486 430 438 174 419 214 492 301 306 198 491 21 344 380 144 86 199 57 279 24 353 309 358 322 8 320 329 135 239 273 95 418 217 66 425 128 447 424 192 259 465 22 138 283 494 125 257 252 280 466 313 396 68 72 175 480 275 429 378 121 269 73 237 101 6 399 416 234 179 12 258 113 193 392 355 61 77 152 89 317 176 114 296 120 349 241 460 405 84 361 382 207 284 475 468 289 191 146 435 10 274 166 436 384 264 83 325 456 458 243 449 282 19 30 299 189 314 35 194 294 93 148 385 302 43 90 99 96 184 211 271 177 157 462 225 409 454 495 200 202 230 47 246 245 156 224 100 312 247 323 423 131 293 244 41 395 130 263 88"
WORST_CASE = "125 116 189 426 106 287 87 129 124 399 23 192 167 360 78 14 468 291 154 474 239 59 488 145 266 109 403 157 82 280 102 29 56 146 366 398 221 111 83 65 323 67 358 290 181 169 493 91 97 26 183 7 313 249 334 21 455 429 246 120 100 326 346 301 142 45 472 72 19 54 320 340 315 317 153 391 387 445 316 257 324 203 9 171 252 32 261 237 269 8 453 131 404 217 230 413 419 495 395 6 304 258 235 350 37 88 382 233 265 253 349 379 175 128 22 62 449 36 268 18 53 274 74 147 275 481 421 298 342 1 226 210 195 255 440 490 133 286 425 359 457 466 218 341 244 489 376 231 344 123 194 469 104 375 215 152 309 262 299 310 371 353 172 417 39 176 486 458 0 308 115 451 373 367 388 336 325 5 55 76 122 96 331 464 439 263 33 234 381 48 300 330 112 497 85 38 156 57 294 225 484 288 207 418 47 318 101 238 410 284 208 259 155 384 292 60 264 307 448 461 34 70 444 394 471 338 450 431 285 4 414 415 389 162 130 222 312 400 296 454 378 80 380 25 363 228 437 49 40 185 149 245 322 173 279 137 11 385 188 441 240 364 365 401 248 42 370 17 260 2 396 343 216 496 289 86 408 69 219 202 433 46 267 335 159 84 61 327 190 305 424 271 383 447 482 434 459 306 206 278 90 127 43 432 64 491 297 209 374 407 463 446 27 138 177 483 345 213 390 16 200 201 492 293 478 119 98 13 31 166 250 134 430 422 179 357 144 99 35 436 467 412 405 103 442 143 302 224 196 498 272 79 211 368 243 277 118 303 273 81 473 487 377 465 212 393 94 494 71 12 165 282 356 428 480 20 186 132 136 328 205 107 158 160 347 392 397 339 41 108 197 199 198 150 427 15 351 68 295 319 170 89 283 135 475 214 462 352 485 44 435 174 73 247 406 241 456 184 141 24 140 180 51 256 270 164 355 92 242 416 126 28 193 438 276 50 95 372 139 251 409 369 223 254 151 314 362 117 476 332 93 386 354 163 460 477 105 52 10 204 3 63 337 220 187 168 479 114 113 182 361 191 66 321 75 232 281 499 470 77 178 420 121 236 348 423 229 161 452 402 411 110 148 329 311 333 58 227 30 443"

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

define run_test
	$(eval ARG = $(shell seq -2500 2500 | shuf -n $(1)))
	$(VAL) ./push_swap $(ARG) > moves.txt; cat moves.txt; echo $(ARG) > nbs.txt
	@echo -n "Instructions for $(1) arguments: "; < moves.txt wc -l
	@rm moves.txt
endef

define print_sequence
	@printf "$(YELLOW)Best and worst case examples. To get average of operations\nYou need Sum results and divide by 2\n $(RESET)"
	@printf "Best Case:\n"
		@printf "$(GREEN)%s $(RESET)" $(BEST_CASE)
	@printf "\nWorst Case:\n"
		@printf "$(RED)%s $(RESET)" $(WORST_CASE)
	@printf "\n"
endef

define help
	echo -e "${BG_DARK_GREEN}${ORANGE}Available targets:${RESET}"
	echo -e "${BG_DARK_GREEN}${ORANGE}all:${RESET}${LIGHT_GRAY}Build push swap${RESET}"
	echo -e "${BG_DARK_GREEN}${ORANGE}both:${RESET}${LIGHT_GRAY}Build push swap and checker${RESET}"
	echo -e "${BG_DARK_GREEN}${ORANGE}bonus:${RESET}${LIGHT_GRAY}Build checker${RESET}"
	echo -e "${BG_DARK_GREEN}${ORANGE}re:${RESET}${LIGHT_GRAY}Rebuild the program${RESET}"
	echo -e "${BG_RED}${ORANGE}clean:${RESET}${LIGHT_GRAY}Remove the object files${RESET}"
	echo -e "${BG_RED}${ORANGE}fclean:${RESET}${LIGHT_GRAY}Remove the program and the object files${RESET}"
	echo -e "${BG_BLUE}${ORANGE}debug:${RESET}${LIGHT_GRAY}Build the program with debugging information${RESET}"
	echo -e "${BG_BLUE}${ORANGE}case:${RESET}${LIGHT_GRAY}Show numbers with best and worst case${RESET}"
	echo -e "${BG_BLUE}${ORANGE}test_nb:${RESET}${LIGHT_GRAY}Test the program with provided list length${RESET}"
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

both: all bonus

debug:
	$(call debug)

test_%: $(NAME)
	@$(call run_test,$*)

case:
	@$(call print_sequence)

help:
	$(call help)

.PHONY: all bonus clean fclean re debug help Makefile test_ case both
.DEFAULT_GOAL := all
.SILENT:
