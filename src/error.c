/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/11 11:16:14 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *message)
{
	ft_printf(B_R"Error!\n"DEF);
	ft_putstr_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	invalid_content_message(int p, int e, int c)
{
	if (p > 1)
		error_message(DUP_P);
	if (e > 1)
		error_message(DUP_E);
	if (p > 1 || e > 1)
		error_message(DUP_P_E);
	if ((p > 1 || e > 1) && c < 1)
		error_message(DUP_NO_C);
	if (p < 1)
		error_message(NO_P);
	if (e < 1)
		error_message(NO_E);
	if (c < 1)
		error_message(NO_C);
}
