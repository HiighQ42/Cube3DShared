/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 10:29:56 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/08/15 18:10:04 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_prelist	*make_new_node(char *content)
{
	t_prelist	*new;

	new = ft_calloc(1, sizeof(t_prelist));
	if (!new)
		return (NULL);
	new->contents = content;
	new->next = NULL;
	return (new);
}

void	node_add_back(t_prelist **head, t_prelist *new, int fd)
{
	t_prelist	*tmp;

	if (!new)
	{
		free_list(*head);
		close(fd);
		error_message(1);
		exit(1);
	}
	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	free_list(t_prelist *head)
{
	t_prelist	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->contents);
		free(tmp);
	}
}

t_prelist	*skip_to_map(t_prelist *list)
{
	char	*tmp;

	if (!list)
		return (list);
	while (list)
	{
		tmp = ft_strtrim(list->contents, " ");
		if (ft_strncmp(tmp, "\n", ft_strlen(tmp)) && ft_strncmp(tmp, "",
				ft_strlen(tmp)))
		{
			free(tmp);
			break ;
		}
		free(tmp);
		list = list->next;
	}
	return (list);
}

int	skip_to_last(t_prelist *node)
{
	char	*tmp;

	while (node)
	{
		tmp = ft_strtrim(node->contents, " ");
		if (!tmp)
			return (error_message(2), -1);
		if (ft_strncmp(tmp, "\n", ft_strlen(tmp)))
			return (error_message_in_read(4), -1);
		free(tmp);
		node = node->next;
	}
	return (0);
}
