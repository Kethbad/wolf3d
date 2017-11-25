NAME = wolf3d

SRC_FILES = main.c

SRC_FOLDER = src/
OBJ_FOLDER = obj/
INC_FOLDER = inc/

GCC_FLAGS = -Wall -Wextra -Werror

# ### ##### ################################ ##### ### #
# ### #####    DO NOT EDIT ANYTHING BELOW    ##### ### #
# ### ##### ################################ ##### ### #

# ###    BUILDING OBJECTS    ### #
SRC = $(addprefix ${SRC_FOLDER},${SRC_FILES})
OBJ_FILES = ${OBJ_FOLDER}$(SRC_FILES:.c=.o)

${OBJ_FOLDER}%.o: $(SRC)
	mkdir ${OBJ_FOLDER}
	gcc -c -o $@ $< $(CFLAGS)

# ###    MAIN RULES    ### #
all: ${OBJ_FILES}
	gcc ${GCC_FLAGS} ${OBJ_FILES} -o ${NAME}

clean:
	@rm -rf ${OBJ_FOLDER}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
