NAME = wolf3d

SRC_FILES = main.c			\
				opencl_init.c     \
					parser_map.c      \
					w3d_sdl_init.c 		\
					image_calculation.c
SRC_FOLDER = src
OBJ_FOLDER = obj
INC_FOLDER = inc

SDL2_INSTALL_FOLDER = SDL2_install
SDL2_FOLDER = SDL2

GCC_FLAGS = 
OPENCL_FLAG = -framework OpenCL
SDL_INC = -I SDL2/include/SDL2/
SDL_LIB = -L./SDL2/lib/ -lSDL2

# ### ##### ################################ ##### ### #
# ### #####    DO NOT EDIT ANYTHING BELOW    ##### ### #
# ### ##### ################################ ##### ### #

# ###    BUILDING OBJECTS    ### #
OBJ = $(addprefix ${OBJ_FOLDER}/,$(SRC_FILES:.c=.o))
${OBJ_FOLDER}/%.o: ${SRC_FOLDER}/%.c
	@mkdir -p ${OBJ_FOLDER}
	gcc -c -o $@ $< $(GCC_FLAGS) -I ${INC_FOLDER} ${SDL_INC}


# ###    MAIN RULES    ### #
all: build_SDL2 ${OBJ}
	gcc ${GCC_FLAGS} ${OPENCL_FLAG} ${SDL_LIB} ${OBJ} -o ${NAME}

clean:
	@rm -rf ${OBJ_FOLDER}
	@rm -rf ${SDL2_INSTALL_FOLDER}
	@rm -rf ${SDL2_FOLDER}

fclean: clean
	@rm -f ${NAME}

re: fclean all

# ###    BUILDING SDL2    ### #
build_SDL2:
	@echo "Checking SDL2 Installation."
	@if [ ! -d "${SDL2_INSTALL_FOLDER}" ]; then 										\
		echo "Building SDL2 Install files."; 											\
		mkdir -p ${SDL2_INSTALL_FOLDER};												\
		cd ${SDL2_INSTALL_FOLDER};														\
		../SDL2-2.0.7/configure --prefix=$(PWD)/SDL2/;									\
		make;																			\
		rm -f ../${SDL2_FOLDER};														\
	else																				\
		echo "SDL2 Install files are already generated."; 								\
	fi
	@if [ ! -d "${SDL2_FOLDER}" ]; then													\
 		echo "Installing SDL2.";														\
		cd ${SDL2_INSTALL_FOLDER};														\
		make install;																	\
	else																				\
		echo "SDL2 is already installed."; 												\
	fi


.PHONY: all clean fclean re
