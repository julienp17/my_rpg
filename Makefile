##
## EPITECH PROJECT, 2019
## my_rpg
## File description:
## Project root Makefile
##

CC 			= 	gcc

MAIN		=	$(addprefix $(SRC_D), $(MAIN_F))
OBJ_M		=	$(MAIN:.c=.o)
MAIN_F		=	main.c

SRC			= 	$(addprefix $(SRC_D), $(SRC_F))
OBJ 		= 	$(SRC:.c=.o)
SRC_D 		= 	src/
SRC_F 		=	my_rpg.c \
				utilities/get_offset_by_key.c \
				file_reading/get_nb_files_in_dir.c \
				file_reading/get_filenames_in_dir.c \
				file_reading/get_file_lines.c \
				file_reading/get_file_buffer.c \
				file_reading/get_file_size.c \
				file_reading/get_pretty_filename.c \
				structures/map/map_create.c \
				structures/map/map_destroy.c \
				structures/map/map_load.c \
				structures/map/map_draw.c \
				structures/map/map_collided.c \
				structures/map/vertices_load.c \
				structures/map/tiles_load.c \
				structures/game/game_create.c \
				structures/game/game_destroy.c \
				structures/game/game_load.c \
				structures/game/game_draw.c \
				structures/game/game_poll_events.c \
				structures/game/window_create.c \
				structures/player/player_create.c \
				structures/player/player_destroy.c \
				structures/player/player_load.c \
				structures/player/player_draw.c \
				structures/player/player_can_move.c \
				structures/player/player_move.c \
				structures/assets/assets_create.c \
				structures/assets/assets_destroy.c \
				structures/assets/assets_load.c \
				structures/assets/assets_load_fonts.c \
				structures/assets/assets_load_music.c \
				structures/assets/assets_load_tilesets.c \
				structures/assets/get_font.c \
				structures/assets/get_music.c \
				structures/assets/get_tileset.c \

SRC_UT   	=	$(addprefix $(SRC_UT_D), $(SRC_UT_F))
OBJ_UT 	 	=	$(SRC_UT:.c=.o)
SRC_UT_D 	= 	tests/
SRC_UT_F 	=	test_get_pretty_filename.c \

INC			= 	-I./include/ -I./include/structures/

CFLAGS		= 	-W -Wall -Wextra -Werror $(INC) $(LDFLAGS) $(DBFLAGS)

DBFLAGS		=	-g -g3 -ggdb

LDFLAGS 	=	-L./lib -ldict -lmy -lm $(CSFML_FLAGS)

CSFML_FLAGS =	-lcsfml-graphics -lcsfml-system -lcsfml-audio

LDFLAGS_UT	= 	-lcriterion -lgcov --coverage

NAME 		= 	my_rpg

NAME_UT 	= 	unit_tests

all: $(NAME)

$(NAME):	makelib $(OBJ) $(OBJ_M)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_M) $(CFLAGS)

makelib:
	make -C ./lib/my/ all
	make -C ./lib/dict/ all

tests_run: clean $(OBJ) $(OBJ_UT)
	echo -e "\e[1;32mCompiling $(NAME_UT) binary... \e[0m"
	$(CC) -o $(NAME_UT) $(SRC) $(SRC_UT) $(CFLAGS) $(LDFLAGS_UT)
	./$(NAME_UT)
	@rm -f $(SRC_UT_F:.c=.gcda)
	@rm -f $(SRC_UT_F:.c=.gcno)

clean:
	rm -f $(OBJ)
	rm -f *.gc*
	make -C ./lib/my clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_UT)
	make -C ./lib/my clean

re: fclean all