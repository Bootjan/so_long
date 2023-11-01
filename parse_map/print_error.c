/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:56:51 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/01 12:03:56 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	print_error(int error_flag)
{
	if (error_flag == 1)
		ft_printf("Error\nProgram encountered a malloc error.\n");
	if (error_flag == 2)
		ft_printf("Error\nIncorrect amount of starts were found.\n");
	if (error_flag == 3)
		ft_printf("Error\nIncorrect amount of exits were found.\n");
	if (error_flag == 4)
		ft_printf("Error\nNo collectibles were found.\n");
	if (error_flag == 5)
		ft_printf("Error\nThe borders of the map are incomplete.\n");
	if (error_flag == 6)
		ft_printf("Error\nThere is no path from start to exit.\n");
	if (error_flag == 7)
		ft_printf("Error\nAn incorrect character was found in the map.\n");
	if (error_flag == 8)
		ft_printf("Error\n2 arguments should be given on argment line.\n");
	if (error_flag == 9)
		ft_printf("Error\nFile not found.\n");
	if (error_flag == 10)
		ft_printf("Error\nMap is not a perfect rectangle.\n");
	if (error_flag == 12)
		ft_printf("Error\nMap is too small.\n");
	if (error_flag == 13)
		ft_printf("Error\nNo path to all collectables.\n");
	return (1);
}
