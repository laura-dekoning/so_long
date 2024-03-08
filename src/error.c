/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/08 10:08:42 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *message)
{
	ft_printf("Error!\n");
	ft_putstr_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	invalid_content_message(int p, int e, int c)
{
	if ((p != 1 || e != 1) && c < 1)
		error_message("Map content is not valid!" \
		"Map contains duplicates and no collectables.");
	if (c < 1)
		error_message("Map content is not valid! No collectables available.");
	if (p != 1 || e != 1)
		error_message("Map content is not valid! Map contains duplicates.");
}
