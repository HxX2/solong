SRC = solong.c src/map_checker.c src/ft_split.c  src/str_utils.c src/printf/libftprintf.a src/sprites.c src/events.c src/put_map.c src/collision.c src/controls.c src/mem_utils.c
BSRC = solong_bonus.c src/bonus/map_checker_bonus.c src/bonus/ft_split_bonus.c  src/bonus/str_utils_bonus.c src/printf/libftprintf.a src/bonus/sprites_bonus.c src/bonus/events_bonus.c src/bonus/put_map_bonus.c src/bonus/collision_bonus.c src/bonus/controls_bonus.c src/bonus/mem_utils_bonus.c src/bonus/econtrols_bonus.c src/bonus/bevent_bonus.c
CC = gcc
NAME = solong
BNAME = solong_bonus
FLAGS = -Wextra -Werror -Wall -lmlx -framework OpenGL -framework AppKit
HEADER = "\033[0;35m   █▀▀ █▀▀█ █░░ █▀▀█ █▀▀▄ █▀▀▀ \n   ▀▀█ █░░█ █░░ █░░█ █░░█ █░▀█ \n   ▀▀▀ ▀▀▀▀ ▀▀▀ ▀▀▀▀ ▀░░▀ ▀▀▀▀\033[0;0m"
FOOTER = "\033[0;35m➔\033[0;0m type \033[0;34m./solong\033[0;0m to run the game."
BFOOTER = "\033[0;35m➔\033[0;0m type \033[0;34m./solong_bonus\033[0;0m to run the game."

all: $(NAME) | footer

bonus: $(BNAME) | bfooter

header :
	@echo
	@echo $(HEADER)
	@echo

footer :
	@echo $(FOOTER)

bfooter :
	@echo $(BFOOTER)

$(NAME): | header
	@echo "\033[0;35m\033[1m────── making printf ──────\033[0;0m"
	@printf "\033[2m"
	@$(MAKE) -C src/printf/
	@echo "\033[0;0m"
	@echo "\033[0;35m\033[1m────── making solong ──────\033[0;0m"
	@printf "\033[2m"
	$(CC) $(FLAGS) -o $(NAME) $(SRC)
	@echo "\033[0;0m"

clean: | header
	@echo "\033[0;35m\033[1m────── clean printf ──────\033[0;0m"
	@printf "\033[2m"
	@$(MAKE) clean -C src/printf/
	@echo "\033[0;0m"

fclean: clean | header
	@echo "\033[0;35m\033[1m────── fclean solong ──────\033[0;0m"
	@printf "\033[2m"
	rm -rf $(NAME)
	rm -rf $(BNAME)
	@echo "\033[0;0m"
	@echo "\033[0;35m\033[1m────── fclean printf ──────\033[0;0m"
	@printf "\033[2m"
	@$(MAKE) fclean -C src/printf/
	@echo "\033[0;0m"

re: fclean all

$(BNAME): | header
	@echo "\033[0;35m\033[1m────── making printf ──────\033[0;0m"
	@printf "\033[2m"
	@$(MAKE) -C src/printf/
	@echo "\033[0;0m"
	@echo "\033[0;35m\033[1m────── making solong ──────\033[0;0m"
	@printf "\033[2m"
	$(CC) $(FLAGS) -o $(BNAME) $(BSRC)
	@echo


san: | header
	@echo "\033[0;35m\033[1m────── making printf ──────\033[0;0m"
	@printf "\033[2m"
	@$(MAKE) -C src/printf/
	@echo "\033[0;0m"
	@echo "\033[0;35m\033[1m────── making solong ──────\033[0;0m"
	@printf "\033[2m"
	$(CC) $(FLAGS) -o $(NAME) $(SRC) -fsanitize=address -g
	@echo
	@echo "\033[0;39m\033[1m(fsanitize build)\033[0;0m"

sre: fclean san

.PHONY: all clean fclean re san sre
