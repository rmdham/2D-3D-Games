SRCS = main.c \
	   parsing/parsing.c \
	   parsing/parse_info.c \
	   parsing/pars_utils.c \
	   parsing/check_file.c \
	   parsing/parse_map.c \
	   libraries/get_next_line/get_next_line.c \
	   libraries/get_next_line/get_next_line_utils.c \
	   libraries/op_libft/ft_atoi.c \
	   libraries/op_libft/ft_bzero.c \
	   libraries/op_libft/ft_isdigit.c \
	   libraries/op_libft/ft_split.c \
	   libraries/op_libft/ft_split2.c \
	   libraries/op_libft/ft_strchr.c \
	   libraries/op_libft/ft_strdup.c \
	   libraries/op_libft/ft_strjoin.c \
	   libraries/op_libft/ft_strlen.c \
	   libraries/op_libft/ft_strnstr.c \
	   libraries/op_libft/ft_strtrim.c \
	   libraries/op_libft/ft_substr.c \
	   libraries/op_libft/ft_isalnum.c \
	   core/init_render.c \
	   core/player/player.c \
	   core/raycasting.c \
	   core/draw_tools.c \
	   core/coll.c \

 
CFLAGS= -Wall -Wextra -Werror -Ofast
FLAGS = -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm
NAME = cub3D
OBJ = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(OBJ) $(CFLAGS) $(FLAGS) -o $(NAME) -no-pie

clean :
	rm -f $(OBJ)  

fclean : clean
	rm -f $(OBJ)  

re : fclean all