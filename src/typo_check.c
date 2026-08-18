/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typo_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 19:00:29 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/16 17:56:37 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	typo_check(char **table)
{
	if (!ft_strncmp(table[0], "\n", ft_strlen(table[0])))
		return (2);
	if (ft_strncmp(table[0], "F", ft_strlen(table[0])) && ft_strncmp(table[0],
			"C", ft_strlen(table[0])))
		return (tab_count(table));
	else
		return (color_check(table));
}

int	color_check(char **table)
{
	if (tab_count(table) < 2)
		return (-1);
	if (comma_check(table))
		return (-1);
	if (tab_count(table) == 2)
		return (num_check(ft_strdup(table[1])));
	else
		return (num_check(join_range(table)));
}

int	comma_check(char **table)
{
	int		comma_counter;
	int		i;
	char	*search_pos;

	comma_counter = 0;
	i = 1;
	search_pos = NULL;
	while (table[i])
	{
		if (!search_pos)
			search_pos = table[i];
		search_pos = ft_strchr(search_pos, ',');
		if (search_pos)
		{
			comma_counter++;
			search_pos++;
		}
		else
			i++;
	}
	if (comma_counter != 2)
		return (-1);
	return (0);
}

int	num_check(char *target)
{
	int		i;
	int		j;
	char	**tab;

	if (!target)
		return (-1);
	i = 0;
	tab = ft_split(target, ',');
	if (!tab)
		return (free(target), -1);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] && tab[i][j] != '\n')
		{
			if (!ft_isdigit(tab[i][j]))
				return (error_message_in_read(3), free(target), free_tab(tab),
					-1);
			j++;
		}
		i++;
	}
	if (i != 3)
		return (-1);
	return (free(target), free_tab(tab), 2);
}

char	*join_range(char **tab)
{
	char	*prev;
	char	*target;
	int		i;

	i = 2;
	prev = ft_strdup(tab[1]);
	if (!prev)
		return (NULL);
	while (tab[i])
	{
		target = ft_strjoin(prev, tab[i]);
		if (!target)
			return (free(prev), NULL);
		free(prev);
		prev = target;
		i++;
	}
	return (target);
}
