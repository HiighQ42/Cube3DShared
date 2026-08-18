/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 12:15:16 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/16 18:29:22 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_typeid(char *typeid, int *index_array, int *element_count)
{
	int		i;
	char	*index_strings[6];

	i = 0;
	make_index_strings(index_strings);
	while (i < 6)
	{
		if (typeid && !ft_strncmp(typeid, index_strings[i], ft_strlen(typeid)))
		{
			*element_count = *element_count + 1;
			index_array[i]++;
		}
		i++;
	}
}

void	make_index_strings(char **index_strings)
{
	index_strings[0] = "NO";
	index_strings[1] = "SO";
	index_strings[2] = "WE";
	index_strings[3] = "EA";
	index_strings[4] = "F";
	index_strings[5] = "C";
}

void	make_index_array(int *index_array)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		index_array[i] = 0;
		i++;
	}
}

int	check_array(int index_array[7])
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < 6)
	{
		if (index_array[i] != 1)
			flag = -1;
		i++;
	}
	if (flag)
		return (error_message_in_read(1), -1);
	return (0);
}
