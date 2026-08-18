/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_translation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:29:49 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/15 12:30:47 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../libft/libft.h"

int	arrays_to_data(t_Data *data, char **tab)
{
	int	i;

	data->info.element_counter++;
	i = which_typeid(data, tab[0]);
	if (i < 4)
		return (case_texture(data, tab, i));
	else
		return (case_color(data, tab, i));
}

int	which_typeid(t_Data *data, char *id)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(id, data->info.index_element[i], ft_strlen(id)))
			break ;
		i++;
	}
	return (i);
}

int	case_texture(t_Data *data, char **tab, int index_num)
{
	data->texture[index_num].typeid = index_num;
	data->texture[index_num].path = ft_substr(tab[1], 0, ft_strlen(tab[1]) - 1);
	if (!data->texture[index_num].path)
		return (error_message(2), -1);
	return (0);
}

int	case_color(t_Data *data, char **tab, int index_num)
{
	int	i;

	i = index_num - 4;
	data->color[i].typeid = index_num;
	if (tab_count(tab) == 2)
		return (insert_range(&data->color[i], ft_strdup(tab[1])));
	else
		return (insert_range(&data->color[i], join_range(tab)));
}

int	insert_range(t_Color *data, char *target)
{
	char	**tmp;
	int		i;

	if (!target)
		return (error_message(2), -1);
	tmp = ft_split(target, ',');
	if (!tmp)
		return (free(target), error_message(2), -1);
	i = 0;
	while (tmp[i])
	{
		data->range[i] = smart_atoi(tmp[i]);
		if (data->range[i] < 0)
			return (free_tab(tmp), free(target), error_message_in_read(3), -1);
		i++;
	}
	return (free_tab(tmp), free(target), 0);
}
