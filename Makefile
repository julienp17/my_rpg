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
SRC_F 		=	utilities/get_dir_by_key.c \
				file_control/get_file_buffer.c \
				file_control/get_file_lines.c \
				file_control/get_file_size.c \
				file_control/get_filenames_ext.c \
				file_control/get_filenames_in_dir.c \
				file_control/get_nb_files_in_dir.c \
				file_control/get_pretty_filename.c \
				file_control/write_to_file.c \
				structures/animation/animation_can_update.c \
				structures/animation/animation_create.c \
				structures/animation/animation_destroy.c \
				structures/animation/animation_update.c \
				structures/assets/assets_create.c \
				structures/assets/assets_destroy.c \
				structures/assets/assets_load_fonts.c \
				structures/assets/assets_load_music.c \
				structures/assets/assets_load.c \
				structures/assets/get_font.c \
				structures/assets/get_music.c \
				structures/button/button_create.c \
				structures/button/button_load.c \
				structures/button/button_destroy.c \
				structures/button/button_draw.c \
				structures/button/button_update.c \
				structures/game/window_create.c \
				structures/game/game_create.c \
				structures/game/game_load.c \
				structures/game/game_destroy.c \
				structures/game/game_run.c \
				structures/game/ingame/ingame_run.c \
				structures/game/ingame/ingame_draw.c \
				structures/game/ingame/ingame_handle_warps.c \
				structures/game/ingame/ingame_poll_events.c \
				structures/game/ingame/ingame_update_view.c \
				structures/game/ingame/ingame_update.c \
				structures/game/ingame/ingame_loop.c \
				structures/map/map_collided.c \
				structures/map/map_create.c \
				structures/map/map_destroy.c \
				structures/map/map_draw_layer.c \
				structures/map/map_draw_npcs.c \
				structures/map/map_get_npc_from_grid.c \
				structures/map/map_load_npcs.c \
				structures/map/map_load_warps.c \
				structures/map/map_load.c \
				structures/map/map_update_npcs.c \
				structures/map/map_update.c \
				structures/map/tiles_load.c \
				structures/map/vertices_load.c \
				structures/npc/npc_create.c \
				structures/npc/npc_destroy.c \
				structures/npc/npc_draw_text.c \
				structures/npc/npc_draw.c \
				structures/npc/npc_load.c \
				structures/npc/npc_update_animation.c \
				structures/npc/npc_update.c \
				structures/pause_menu/pause_menu_create.c \
				structures/pause_menu/pause_menu_load.c \
				structures/pause_menu/pause_menu_destroy.c \
				structures/pause_menu/pause_menu_run.c \
				structures/pause_menu/pause_menu_loop.c \
				structures/pause_menu/pause_menu_draw.c \
				structures/pause_menu/pause_menu_draw_stats.c \
				structures/pause_menu/pause_menu_draw_stats_value.c \
				structures/pause_menu/pause_menu_draw_stats_sprites.c \
				structures/pause_menu/pause_menu_poll_events.c \
				structures/pause_menu/pause_menu_update.c \
				structures/player/player_can_interact.c \
				structures/player/player_can_move.c \
				structures/player/player_create.c \
				structures/player/player_destroy.c \
				structures/player/player_draw.c \
				structures/player/player_get_facing_tile.c \
				structures/player/player_get_move_offset.c \
				structures/player/player_is_moving.c \
				structures/player/player_load.c \
				structures/player/player_move.c \
				structures/player/player_update_animation.c \
				structures/player/player_update.c \
				structures/start_menu/start_menu_create.c \
				structures/start_menu/start_menu_load.c \
				structures/start_menu/start_menu_destroy.c \
				structures/start_menu/start_menu_run.c \
				structures/start_menu/start_menu_loop.c \
				structures/start_menu/start_menu_draw.c \
				structures/start_menu/start_menu_poll_events.c \
				structures/start_menu/start_menu_update.c \
				structures/stats/stats_create.c \
				structures/stats/stats_destroy.c \
				structures/warp/warp_create.c \
				structures/warp/warp_destroy.c \
				structures/warp/warp_load.c \
				utilities/frect_from_str.c \
				utilities/frect_multiply.c \
				utilities/irect_from_str.c \
				utilities/sprite_flip.c \
				utilities/sprite_get_center.c \
				utilities/v2f_add.c \
				utilities/v2f_from_str.c \
				utilities/v2f_multiply.c \
				utilities/v2f_to_grid.c \
				utilities/v2i_add.c \
				utilities/v2i_eq.c \
				utilities/color_eq.c \
				utilities/get_random.c \
				utilities/get_default_rect.c \
				utilities/get_default_text.c \

SRC_UT   	=	$(addprefix $(SRC_UT_D), $(SRC_UT_F))
OBJ_UT 	 	=	$(SRC_UT:.c=.o)
SRC_UT_D 	= 	tests/
SRC_UT_F 	=	test_v2f_multiply.c \
				test_v2f_add.c \
				test_v2f_from_str.c \
				test_v2f_to_grid.c

INC			= 	-I./include/ -I./include/structures/

CFLAGS		= 	-W -Wall -Wextra -Werror $(INC) $(LDFLAGS)

DBFLAGS		=	-g -g3 -ggdb

LDFLAGS 	=	-L./lib -ldict -lmy -lm $(CSFML_FLAGS)

CSFML_FLAGS =	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

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