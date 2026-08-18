/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:20:06 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/16 16:48:52 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"

typedef struct struct_list
{
	char				*contents;
	struct struct_list	*next;
}						t_prelist;

typedef enum s_Element
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
}						t_Element;

typedef struct s_Parse
{
	char				**copy;
	int					width;
	int					hight;
	int					flag;
}						t_Parse;

typedef struct s_MapContent
{
	char				**map;
	int					size;
}						t_MapContent;

typedef struct s_Texture
{
	t_Element			typeid;
	char				*path;
}						t_Texture;

typedef struct s_Color
{
	t_Element			typeid;
	int					range[3];
}						t_Color;

typedef struct s_info
{
	int					element_counter;
	char				*index_element[6];
}						t_info;

typedef struct s_Data
{
	t_MapContent		map;
	t_Texture			texture[4];
	t_Color				color[2];
	t_info				info;
}						t_Data;

void					error_message(int err_code);
t_Data					*prep_data(char *filename);
int						check_read_result(t_prelist *list);
int						check_array(int *index_array);
void					error_message_in_read(int error_code);
t_prelist				*make_new_node(char *content);
void					node_add_back(t_prelist **head, t_prelist *new, int fd);
void					free_list(t_prelist *head);
void					make_index_strings(char **index_strings);
void					make_index_array(int *index_array);
t_prelist				*skip_to_map(t_prelist *list);
int						skip_to_last(t_prelist *node);
void					check_typeid(char *typeid, int *index_array,
							int *element_count);
int						tab_count(char **tab);
void					free_tab(char **tab);
int						typo_check(char **table);
int						color_check(char **table);
int						comma_check(char **table);
int						num_check(char *target);
char					*join_range(char **tab);
int						arrays_to_data(t_Data *data, char **tab);
int						which_typeid(t_Data *data, char *id);
int						case_texture(t_Data *data, char **tab, int index_num);
int						case_color(t_Data *data, char **tab, int index_num);
int						insert_range(t_Color *data, char *target);
// static int	ft_isspace(char c);
int						protect_overflow(const char *nptr, int i, int sign);
int						smart_atoi(const char *nptr);
void					free_data(t_Data *data);
void					free_texture(t_Texture *texture);
void					free_map(t_MapContent node);
t_Data					*translate_into_data(t_prelist *list);
int						make_map(t_Data *data, t_prelist *head);
int						count_map_size(t_prelist *list);
int						map_copy(t_MapContent node, t_prelist *list);
void					free_map_reverse(char **tab, int i);
int						prep_pdata(t_MapContent *src, t_Parse *cpy);
size_t					max_width(char **map);
char					**make_square(char **src, size_t max, size_t size);
char					*extend_string(char *src, size_t max);
void					error_message_in_parse(int error_code);
int						parse_map(t_MapContent *data);
int						char_in_map(char **map);
int						player_check(int player);
int						go_through_indexarr(char c, int *player);
int						flood_fill(t_Parse *data);
void					flood(int x_pos, int y_pos, t_Parse *data);
int						char_check_in_flood(char c);
int						flood_fill_space(t_Parse *data);
void					flood_space(int x_pos, int y_pos, t_Parse *data);
int						*read_through_list(t_prelist *list);
int						prep_for_read_through_list(int **ret,
							int *element_count);
void					free_utils(char *str, char **tab);

void					print_info(t_Data *data);
#endif
