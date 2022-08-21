SRC = solong.c src/map_checker.c src/ft_split.c  src/str_utils.c src/printf/libftprintf.a src/sprites.c src/events.c src/put_map.c
CC = gcc
NAME = solong
FLAGS = -Wextra -Werror -Wall -lmlx -framework OpenGL -framework AppKit
HEADER = "\033[0;35m   █▀▀ █▀▀█ █░░ █▀▀█ █▀▀▄ █▀▀▀ \n   ▀▀█ █░░█ █░░ █░░█ █░░█ █░▀█ \n   ▀▀▀ ▀▀▀▀ ▀▀▀ ▀▀▀▀ ▀░░▀ ▀▀▀▀\033[0;0m"
FOOTER = "\033[0;35m➔\033[0;0m type \033[0;34m./solong\033[0;0m to run the game."

all: $(NAME) | footer

header :
	@echo
	@echo $(HEADER)
	@echo

footer :
	@echo $(FOOTER)

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
	@echo "\033[0;0m"
	@echo "\033[0;35m\033[1m────── fclean printf ──────\033[0;0m"
	@printf "\033[2m"
	@$(MAKE) fclean -C src/printf/
	@echo "\033[0;0m"

re: fclean all

bonus: | header
	@echo "\033[0;35m\033[1m────── making printf ──────\033[0;0m"
	@printf "\033[2m"
	@$(MAKE) -C src/printf/
	@echo "\033[0;0m"
	@echo "\033[0;35m\033[1m────── making solong ──────\033[0;0m"
	@printf "\033[2m"
	$(CC) $(FLAGS) -o $(NAME) $(SRC)
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
