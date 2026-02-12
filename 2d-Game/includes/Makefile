NAME = so_long
FLAGS = -Wall -Wextra -Werror
MLXFLAGS =	-lmlx -framework OpenGL -framework AppKit
SRC = ../source_file/so_long.c ../source_file/map.c ../source_file/validmap_tools.c ../source_file/window.c ../source_file/twii.c get_next_line.c utils.c  utils2.c itoa.c ../source_file/player_moves.c ../source_file/exit_anime.c


OBJ = *.o

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) $(MLXFLAGS) -o $(NAME)

$(OBJ): $(SRC)
	cc	$(FLAGS) -c $(SRC)

clean: $(OBJ)
	@rm -rf $(OBJ)
fclean:	clean
	@rm -rf $(NAME)

re: fclean all

.FHONY: all clean fclean re