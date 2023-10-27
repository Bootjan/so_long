/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:56:51 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/27 16:46:38 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error(int error_flag)
{
	ft_printf("Error:\n");
	if (error_flag == 1)
		ft_printf("Program encountered a malloc error.\n");
	if (error_flag == 2)
		ft_printf("Incorrect amount of starts were found.\n");
	if (error_flag == 3)
		ft_printf("Incorrect amount of exits were found.\n");
	if (error_flag == 4)
		ft_printf("No collectibles were found.\n");
	if (error_flag == 5)
		ft_printf("The borders of the map are incomplete.\n");
	if (error_flag == 6)
		ft_printf("There is no path from start to exit.\n");
	if (error_flag == 7)
		ft_printf("An incorrect character was found in the map.\n");
	if (error_flag == 8)
		ft_printf("2 arguments should be given on argment line.\n");
	if (error_flag == 9)
		ft_printf("File not found.\n");
	if (error_flag == 10)
		ft_printf("Map is not a perfect rectangle.\n");
	if (error_flag == 12)
		ft_printf("Map is too small.\n");
}
