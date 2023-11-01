OPEN_MAP = check_path.c check_path_helpers.c check_validity.c compute_map.c \
	linked_list.c print_error.c helpers.c is_ber_file.c

OPEN_WINDOW = load_window.c load_images.c collect_coins.c make_move.c \
utils.c put_images.c

SRCS = ${OPEN_WINDOW}\
${OPEN_MAP}\
main.c

OBJS = ${SRCS:%.c=${OBJS_DIR}/%.o}
NAME = so_long
VPATH = ./open_window ./parse_map

INCLUDE = -I./includes
CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJS_DIR = ./objs

LIB = ${MAKE_LIB} ./build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
RM = rm -f

MAKE_LIB = ${MAKE_DIR}/libftprintf.a
MAKE_DIR = ./ft_printf
MLX42_DIR = ./mlx
MLX42 = ./build/libmlx42.a

all:	${NAME}

${NAME}: ${MLX42} ${MAKE_LIB} ${OBJS_DIR} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}

${MLX42}:
	cmake ${MLX42_DIR} -B build
	cmake --build build

${MAKE_LIB}:
	make -C ${MAKE_DIR} all

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

${OBJS_DIR}/%.o:	%.c
	${CC} ${CFLAGS} -c $< -o $@ ${INCLUDE}

clean:	
	make -C ${MAKE_DIR} clean
	${RM} -r ${OBJS_DIR}

fclean: clean
	${RM} ${NAME}
	make -C ${MAKE_DIR} fclean
	rm -rf ./build
	rm -rf ${OBJS_DIR}

re: fclean all

.PHONY: all clean re clean fclean
