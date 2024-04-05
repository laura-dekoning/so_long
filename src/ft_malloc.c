/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/29 14:37:58 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/05 16:40:49 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc_errorcheck(size_t num_elem, size_t size_elem)
{
	void	*ptr;

	ptr = ft_calloc(num_elem, size_elem);
	if (!ptr)
		error_message("Allocation failed.");
	return (ptr);
}
