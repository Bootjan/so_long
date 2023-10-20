SRCS = check_path.c check_path_helpers.c check_validity.c compute_map.c \
	get_next_line.c get_next_line_utils.c linked_list.c print_error.c \
	helpers.c

MAP_DIR = ./parse_map
SRCS_DIR = ${SRCS:%=${MAP_DIR}/%}

MAIN = main.c
NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIB = -L. -lft
RM = rm -f

all:	${NAME}

${NAME}:
	${CC} ${CFLAGS} ${SRCS_DIR} ${MAIN} -o ${NAME} ${LIB}

clean:
	${RM} ${NAME}

re: clean all

.PHONY: all clean re