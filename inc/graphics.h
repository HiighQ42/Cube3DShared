#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include "cub3d.h"
# include "mlx.h"
# define PI 3.14159265358979323846
# define CAMERA_SCALE 0.66
# define RAY_FAR 1.0e30
# define EPSILON 1.0e-9
# define DEBUG_CELL 12
# define VIEW_WIDTH 1280
# define VIEW_HEIGHT 720
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef enum e_side
{
    SIDE_X,
    SIDE_Y
}       t_side;

typedef enum e_face
{
    FACE_NORTH,
    FACE_SOUTH,
    FACE_WEST,
    FACE_EAST
}       t_face;

typedef struct s_point
{
    int x;
    int y;
}       t_point;

typedef struct s_vec
{
    double x;
    double y;
}       t_vec;

typedef struct s_line
{
    int start;
    int end;
    int fixed;
}       t_line;

typedef struct s_rect
{
    int x;
    int y;
    int width;
    int height;
}       t_rect;

typedef struct s_span
{
    int start;
    int end;
}       t_span;

typedef struct s_image
{
    void *handle;
    char *addr;
    int bpp;
    int line_len;
    int endian;
    int width;
    int height;
}       t_image;
typedef struct s_spawn
{
    int x;
    int y;
    char orientation;
}       t_spawn;

typedef struct s_camera
{
    t_vec pos;
    t_vec dir;
    t_vec plane;
}       t_camera;

typedef struct s_input
{
    int forward;
    int backward;
    int left;
    int right;
    int turn_left;
    int turn_right;
}       t_input;

typedef struct s_wall_texture
{
    t_image image;
}       t_wall_texture;

typedef struct s_ray
{
    t_vec dir;
    t_vec delta;
    t_vec side_dist;
    t_vec hit;
    t_point map;
    t_point step;
    double distance;
    double wall_x;
    t_side side;
    t_face face;
}       t_ray;

typedef struct s_trace
{
    t_point *cells;
    int count;
}       t_trace;

typedef struct s_sample
{
    t_wall_texture *texture;
    t_span raw;
    t_span visible;
    int line_height;
    int tex_x;
    double step;
    double position;
}       t_sample;

typedef struct s_game
{
    void *mlx;
    void *win;
    int width;
    int height;
    t_image frame;
    t_camera camera;
    t_input input;
    t_wall_texture walls[4];
    t_Data *scene;
}   t_game;

int init_mlx(t_game *game, t_Data *scene);
int open_window(t_game *game);
int create_frame(t_game *game);
int map_image_memory(t_image *image);
char *pixel_address(t_image *image, t_point point);
int write_pixel(t_image *image, t_point point, int color);
void present_frame(t_game *game);
int make_rgb(t_Color *color);
void fill_image(t_image *image, int color);
void draw_hline(t_image *image, t_line line, int color);
void draw_vline(t_image *image, t_line line, int color);
void fill_rect(t_image *image, t_rect rect, int color);
void draw_background(t_image *image, int ceiling, int floor);
void draw_debug_map(t_game *game, t_image *image);
int find_spawn(t_Data *scene, t_spawn *spawn);
void draw_vector(t_image *image, t_vec origin, t_vec vector,
int color);
t_vec start_direction(char orientation);
t_vec make_camera_plane(t_vec direction, double scale);
int init_camera(t_game *game);
double degrees_to_radians(double degrees);
t_vec rotated_vector(t_vec vector, double angle);
void rotate_direction(t_camera *camera, double angle);
void rotate_camera(t_camera *camera, double angle);
int valid_column(int x, int width);
double camera_position(int x, int width);
t_vec ray_direction(t_camera *camera, double camera_x);
void print_ray_sample(int x, double camera_x, t_vec ray_dir);
t_point ray_map_cell(t_vec position);
double next_x_gap(t_vec position, t_vec ray_dir);
double next_y_gap(t_vec position, t_vec ray_dir);
double boundary_distance(double gap, double component);
double delta_x(t_vec ray_dir);
double delta_y(t_vec ray_dir);
t_point ray_step(t_vec ray_dir);
void init_side_dist(t_ray *ray, t_camera *camera);
void init_ray(t_ray *ray, t_game *game, int x);
void advance_ray_x(t_ray *ray);
void advance_ray_y(t_ray *ray);
int next_ray_side(t_ray *ray);
void enter_next_cell(t_ray *ray, int side);
void record_hit_side(t_ray *ray, int side);
int cell_is_wall(t_Data *scene, t_point cell);
int run_dda(t_ray *ray, t_Data *scene);
int trace_matches(t_trace *actual, t_trace *expected);
double project_depth(double ray_length, double angle_offset);
double wall_distance(t_ray *ray);
int wall_height(double distance, int screen_height);
t_span wall_span(int line_height, int screen_height);
t_span clip_span(t_span span, int screen_height);
void draw_wall_slice(t_image *image, int x, t_span span,
int color);
t_face wall_face(t_ray *ray);
void render_flat_frame(t_game *game);
int set_key_state(int key, t_input *input, int pressed);
void move_forward(t_game *game, double amount);
void move_sideways(t_game *game, double amount);
void apply_rotation(t_game *game, double angle);
int render_loop(t_game *game);
int load_texture(t_game *game, t_wall_texture *texture,
char *path);
int map_texture_memory(t_wall_texture *texture);
int texture_pixel(t_wall_texture *texture, t_point point);
int load_textures(t_game *game);
t_wall_texture *select_texture(t_game *game, t_face face);
t_vec wall_hit(t_camera *camera, t_ray *ray);
double wall_fraction(t_vec hit, int side);
int texture_column(double wall_x, int texture_width);
int orient_texture_x(int tex_x, int width, t_ray *ray);
double texture_step(int texture_height, int wall_height);
double texture_start(t_span raw, t_span clipped, double step);
void draw_textured_slice(t_game *game, t_ray *ray, int x);
void render_frame(t_game *game);
void destroy_game(t_game *game);
int close_game(t_game *game, int exit_code);
int key_press(int key, t_game *game);
int key_release(int key, t_game *game);
int window_close(t_game *game);
void install_hooks(t_game *game);
int run_graphics(t_Data *scene);
#endif