/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_pdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 13:33:06 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/16 17:20:24 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	prep_pdata(t_MapContent *src, t_Parse *cpy)
{
	cpy->flag = 0;
	cpy->hight = (size_t)src->size - 1;
	cpy->width = max_width(src->map);
	cpy->copy = make_square(src->map, cpy->width, cpy->hight + 1);
	if (!cpy->copy)
		return (-1);
	return (0);
}

size_t	max_width(char **map)
{
	size_t	max;
	int		i;

	max = 0;
	i = 0;
	while (map[i])
	{
		if (max < ft_strlen(map[i]))
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

char	**make_square(char **src, size_t max, size_t size)
{
	char	**pmap;
	int		i;

	pmap = (char **)ft_calloc(size + 1, sizeof(char *));
	if (!pmap)
		return (error_message(2), NULL);
	i = 0;
	while (src[i])
	{
		pmap[i] = extend_string(src[i], max);
		if (!pmap[i])
			return (free_map_reverse(pmap, i), error_message(2), NULL);
		i++;
	}
	return (pmap);
}

char	*extend_string(char *src, size_t max)
{
	char	*ret;
	char	*tmp;
	size_t	gap;

	gap = max - ft_strlen(src);
	ret = ft_strdup(src);
	if (!ret)
		return (NULL);
	if (gap)
	{
		while (gap)
		{
			tmp = ret;
			ret = ft_strjoin(ret, " ");
			if (!ret)
				return (free(tmp), NULL);
			free(tmp);
			gap--;
		}
	}
	return (ret);
}
