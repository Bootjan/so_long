/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:13:26 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/24 19:24:16 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_lines	*create_element(char *line)
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

char	*line_without_nl(int fd, int *error_flag)
{
	int		len;
	char	*str;
	char	*out;

	str = get_next_line(fd);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (str[len - 1] != '\n')
		return (str);
	out = ft_substr(str, 0, len - 1);
	free(str);
	if (!out)
	{
		*error_flag = 1;
		return (NULL);
	}
	return (out);
}
