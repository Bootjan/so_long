OPEN_MAP = check_path.c check_path_helpers.c check_validity.c compute_map.c \
	linked_list.c print_error.c helpers.c

MAP_DIR = ./parse_map
OPEN_MAP_DIR = ${OPEN_MAP:%=${MAP_DIR}/%}

OPEN_WINDOW = load_window.c load_images.c collect_coins.c make_move.c \
utils.c put_images.c
WINDOW_DIR = ./open_window
OPEN_WINDOW_DIR = ${OPEN_WINDOW:%=${WINDOW_DIR}/%}

MAIN = main.c
NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIB = ${MAKE_LIB} ./build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -g
RM = rm -f

MAKE_LIB = ${MAKE_DIR}/libftprintf.a
MAKE_DIR = ./ft_printf
OBJS_DIR = ./objs
MLX42_DIR = ./mlx
MLX42 = libmlx42.a

all:	${NAME}

${OBJS_DIR}/%.o:	%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${MLX42} ${OBJS_DIR} ${MAKE_LIB}
	${CC} ${OPEN_MAP_DIR} ${OPEN_WINDOW_DIR} ${MAIN} -o ${NAME} ${LIB}

${MLX42}:
	cmake ${MLX42_DIR} -B build
	cmake --build build

${MAKE_LIB}:
	make -C ${MAKE_DIR} all

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

clean:	
	make -C ${MAKE_DIR} clean

fclean: clean
	${RM} ${NAME}
	make -C ${MAKE_DIR} fclean
	rm -rf ./build

re: fclean all

.PHONY: all clean re clean fclean