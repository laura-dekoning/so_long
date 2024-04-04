/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:46:22 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/04 19:31:51 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42.h"

# define PIXEL 64
// # define WIDTH 1920
// # define HEIGHT 1080

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct		s_images
{
	mlx_texture_t	*p;
	mlx_texture_t	*e;
	mlx_texture_t	*c;
	mlx_texture_t	*w;
	mlx_texture_t	*f;
	mlx_image_t		*player;
	mlx_image_t		*exit;
	mlx_image_t		*collectable;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
}					t_images;

typedef struct		s_game
{
	char			**map;
	int				width;
	int				height;
	t_point			player_pos;
	t_point			exit_pos;
	int				collectables;
	int				collected;
	int				steps;
	mlx_t			*mlx;
	t_images		img;
}					t_game;

/*MAP*/
char	*read_mapfile(const char *file);
void	init_game_data(t_game *game, const char *file);
void	init_game_struct(t_game *game, char **map_as_d_array, int width, int height);
int		count_rows(char **map_as_d_array);
t_point	find_position(char **map_as_d_array, char c);
int		find_amount_collectables(char **map_as_d_array);

void	error_message(char *message);

void	check_file(char *map);
void	check_content(char *map);
void	check_invalid_content(int i);
void	check_empty_lines(char *map);
void	check_empty_file(char *map);
void	check_map(char **map, int width, int height);
void	check_walls(char **map, int width, int height);
void	check_mapsize(int width, int height);
void	check_if_map_rectangular(char **map, int width);
void	invalid_content_message(int p, int e, int c);
bool	flood_fill(t_game *game, char **map, int x, int y);
char	**copy_map(t_game *game);

void	init_images(t_game *game);
void	get_texture(mlx_texture_t **txt, char *path);
void	get_image(t_game *game, mlx_image_t **img, mlx_texture_t *txt);

void	test_initialisation(t_game *game);
void	map_test(char **map);
void	print_map(char **map);
void	fill_background(t_game *game);
void	render_map(t_game *game);

void	keyhooks(mlx_key_data_t keydata, void *param);
void	move_up(t_game *game, char **map);
void	move_down(t_game *game, char **map);
void	move_left(t_game *game, char **map);
void	move_right(t_game *game, char **map);

#endif