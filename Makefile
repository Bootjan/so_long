OPEN_MAP = check_path.c check_path_helpers.c check_validity.c compute_map.c \
	get_next_line.c get_next_line_utils.c linked_list.c print_error.c \
	helpers.c

MAP_DIR = ./parse_map
OPEN_MAP_DIR = ${OPEN_MAP:%=${MAP_DIR}/%}

OPEN_WINDOW = load_window.c put_element.c
WINDOW_DIR = ./open_window
OPEN_WINDOW_DIR = ${OPEN_WINDOW:%=${WINDOW_DIR}/%}

MAIN = main.c
NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIB = libft.a libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
RM = rm -f

all:	${NAME}

${NAME}:
	${CC} ${OPEN_MAP_DIR} ${OPEN_WINDOW_DIR} ${MAIN} -o ${NAME} ${LIB}

clean:
	${RM} ${NAME}

re: clean all

.PHONY: all clean re