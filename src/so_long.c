/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:43:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/03/04 17:12:36 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "MLX42.h"

int	main(int argc, char **argv)
{
	int			fd;
	char		*filename;
	const char	*extension;
	int			f_len;
	int			ext_len;
	int			comp_start;

	if (argc != 2)
	{
		ft_printf("Incorrect amount of arguments\n");
		return (1);
	}

	filename = argv[1];
	f_len = ft_strlen(filename);
	extension = ".ber";
	ext_len = ft_strlen(extension);
	comp_start = f_len - ext_len;
	if (f_len > ext_len && (ft_strncmp(filename + comp_start, extension, ext_len) == 0))
	{
		fd = open(filename, O_RDONLY);

	}
	else
	{
		ft_printf("Incorrect file format! Please provide a *.ber file.\n");
		return (1);
	}

	return (0);
}
