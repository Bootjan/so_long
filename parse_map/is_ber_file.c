/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:54:09 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/01 12:54:32 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_ber_file(const char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	if (len < 5)
		return (0);
	i = 0;
	while (i < 4)
	{
		if (str[len - i - 1] != ".ber"[3 - i])
			return (0);
		i++;
	}
	return (1);
}
