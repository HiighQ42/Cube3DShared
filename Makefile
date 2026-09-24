NAME := cub3D

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRC := src/element_translation.c \
	src/error_message.c \
	src/flood_fill.c \
	src/free_data_funcs.c \
	src/gfx_camera_camera_plane.c \
	src/gfx_camera_player_init.c \
	src/gfx_camera_rotation.c \
	src/gfx_cleanup_cleanup.c \
	src/gfx_draw_color.c \
	src/gfx_draw_debug_map.c \
	src/gfx_draw_image_pixel.c \
	src/gfx_draw_lines.c \
	src/gfx_draw_rect.c \
	src/gfx_input_hooks.c \
	src/gfx_input_key_state.c \
	src/gfx_input_movement.c \
	src/gfx_mlx_frame_present.c \
	src/gfx_mlx_init.c \
	src/gfx_player_camera_init.c \
	src/gfx_player_spawn.c \
	src/gfx_raycast_dda.c \
	src/gfx_raycast_dda_step.c \
	src/gfx_raycast_ray_build.c \
	src/gfx_raycast_ray_distance.c \
	src/gfx_raycast_ray_setup.c \
	src/gfx_render_background.c \
	src/gfx_render_flat_wall.c \
	src/gfx_render_projection_math.c \
	src/gfx_render_render.c \
	src/gfx_render_render_loop.c \
	src/gfx_start.c \
	src/gfx_texture_texture_hit.c \
	src/gfx_texture_texture_load.c \
	src/gfx_texture_texture_select.c \
	src/gfx_texture_texture_vertical.c \
	src/list_funcs.c \
	src/main.c \
	src/map_translation.c \
	src/parce_map_char.c \
	src/parse_map.c \
	src/prep_data.c \
	src/prep_pdata.c \
	src/read_file.c \
	src/read_file_utils.c \
	src/smart_atoi.c \
	src/tab_funcs.c \
	src/translate_into_data.c \
	src/typo_check.c

OBJ_DIR := .obj
OBJ := $(SRC:src/%.c=$(OBJ_DIR)/%.o)
DEP := $(OBJ:.o=.d)

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

MLX_DIR := minilibx-linux
MLX := $(MLX_DIR)/libmlx_Linux.a

CPPFLAGS := -Iinc -I$(LIBFT_DIR) -I$(MLX_DIR)
LDLIBS := -L$(LIBFT_DIR) -lft \
	-L$(MLX_DIR) -lmlx_Linux \
	-lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(OBJ) $(LDLIBS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: all

-include $(DEP)

.PHONY: all clean fclean re bonus