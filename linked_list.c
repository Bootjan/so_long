/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:13:26 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/18 20:24:47 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_lines	*create_element(char *line)
{
	t_lines	*element;

	element = malloc(sizeof(t_lines));
	if (!element)
		return (NULL);
	element->line = line;
	element->next = NULL;
	return (element);
}

void	free_list(t_lines **lines, int error_flag)
{
	t_lines	*current;
	t_lines	*next;

	current = *lines;
	while (current)
	{
		next = current->next;
		if (error_flag > 0 && current->line)
			free(current->line);
		free(current);
		current = next;
	}
}

void	ft_lpush_back(t_lines **lines, char *line, int *error_flag)
{
	t_lines	*current;
	t_lines	*element;

	element = create_element(line);
	if (!element)
	{
		*error_flag = 1;
		return ;
	}
	current = *lines;
	if (!current)
	{
		*lines = element;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = element;
}

char	*put_line_map(t_lines *lines, int index)
{
	t_lines	*current;
	int		i;

	current = lines;
	i = 0;
	while (current && i++ < index)
		current = current->next;
	return (current->line);
}
