/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:56:51 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/24 18:21:32 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error(int error_flag)
{
	ft_putendl_fd("Error:", 1);
	if (error_flag == 1)
		ft_putendl_fd("Program encountered a malloc error.", 1);
	if (error_flag == 2)
		ft_putendl_fd("Incorrect amount of starts were found.", 1);
	if (error_flag == 3)
		ft_putendl_fd("Incorrect amount of exits were found.", 1);
	if (error_flag == 4)
		ft_putendl_fd("No collectibles were found.", 1);
	if (error_flag == 5)
		ft_putendl_fd("The borders of the map are incomplete.", 1);
	if (error_flag == 6)
		ft_putendl_fd("There is no path from start to exit.", 1);
	if (error_flag == 7)
		ft_putendl_fd("An incorrect character was found in the map.", 1);
	if (error_flag == 8)
		ft_putendl_fd("2 arguments should be given on argment line.", 1);
	if (error_flag == 9)
		ft_putendl_fd("File not found.", 1);
	if (error_flag == 10)
		ft_putendl_fd("Map is not a perfect square", 1);
}
