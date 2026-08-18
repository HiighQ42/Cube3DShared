/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 12:41:55 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/16 18:29:42 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <stdlib.h>

int	check_read_result(t_prelist *list)
{
	int	*index_array;

	index_array = read_through_list(list);
	if (!index_array)
		return (-1);
	if (check_array(index_array))
		return (free(index_array), -1);
	list = skip_to_map(list);
	if (!list)
		return (free(index_array), error_message_in_read(2), -1);
	return (free(index_array), 0);
}

int	*read_through_list(t_prelist *list)
{
	int		*ret;
	int		element_count;
	char	*without_newline;
	char	**check_tab;

	if (prep_for_read_through_list(&ret, &element_count))
		return (NULL);
	while (list && element_count != 6)
	{
		without_newline = ft_strtrim(list->contents, "\n");
		if (!without_newline)
			return (free(ret), NULL);
		check_tab = ft_split(without_newline, ' ');
		if (!check_tab)
			return (free(ret), NULL);
		if (typo_check(check_tab) != 2)
			return (free(ret), free_tab(check_tab), error_message_in_read(0),
				NULL);
		check_typeid(check_tab[0], ret, &element_count);
		free_utils(without_newline, check_tab);
		list = list->next;
	}
	return (ret);
}

int	prep_for_read_through_list(int **ret, int *element_count)
{
	*ret = (int *)ft_calloc(6, sizeof(int));
	if (!*ret)
		return (-1);
	*element_count = 0;
	return (0);
}

void	free_utils(char *str, char **tab)
{
	free(str);
	free_tab(tab);
}
