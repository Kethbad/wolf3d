NAME = wolf3d

SRC_FILES = main.c			\
			opencl_init.c

SRC_FOLDER = src
OBJ_FOLDER = obj
INC_FOLDER = inc

SDL2_INSTALL_FOLDER = SDL2_install
SDL2_FOLDER = SDL2

GCC_FLAGS = -Wall -Wextra -Werror
SDL_INC = -I SDL2-2.0.7/SDL2/include/SDL2/
SDL_LIB = -L./SDL2-2.0.7/SDL2/lib/ -lSDL2

# ### ##### ################################ ##### ### #
# ### #####    DO NOT EDIT ANYTHING BELOW    ##### ### #
# ### ##### ################################ ##### ### #

# ###    BUILDING SDL2    ### #
build_SDL2:
	@mkdir -p ${SDL_INSTALL_FOLDER}
	cd ${SDL_INSTALL_FOLDER}
	../SDL2-2.0.7/configure --prefix=$(PWD)/SDL2/
	make
	make install
	cd ..


# ###    BUILDING OBJECTS    ### #
OBJ = $(addprefix ${OBJ_FOLDER}/,$(SRC_FILES:.c=.o))
${OBJ_FOLDER}/%.o: ${SRC_FOLDER}/%.c
	@mkdir -p ${OBJ_FOLDER}
	gcc -c -o $@ $< $(CFLAGS) -I ${INC_FOLDER} ${SDL_INC}


# ###    MAIN RULES    ### #
all: ${OBJ}
	# cd SDL2-2.0.7 ; ./configure --prefix=$(PWD)/SDL2/ ; make ; make install
	gcc ${GCC_FLAGS} ${SDL_LIB} ${OBJ} -o ${NAME}

clean:
	@rm -rf ${OBJ_FOLDER}
	@rm -rf ${SDL2_INSTALL_FOLDER}
	@rm -rf ${SDL2_FOLDER}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
