/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 17:46:22 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/04/18 15:32:57 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42.h"
# include "colors.h"
# include "errors.h"

# define PIXEL 64

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_images
{
	mlx_texture_t	*p;
	mlx_texture_t	*e;
	mlx_texture_t	*c;
	mlx_texture_t	*w;
	mlx_texture_t	*f;
	mlx_image_t		*player;
	mlx_image_t		*exit;
	mlx_image_t		*flower;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
}					t_images;

typedef struct s_game
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

/*Map*/
char	*read_mapfile(const char *file);
void	init_game_data(t_game *game, const char *file);
void	init_game_struct(t_game *game, char **map_arr, int width, int height);
int		count_rows(char **map_arr);
t_point	find_position(char **map_arr, char c);
int		find_amount_collectables(char **map_arr);
bool	flood_fill(t_game *game, char **map, int x, int y);
char	**copy_map(t_game *game);

/*Error*/
void	error_message(char *message);
void	invalid_content_message(int p, int e, int c);
void	*ft_calloc_errorcheck(size_t num_elem, size_t size_elem);

/*Check data*/
void	check_file(char *map);
void	check_content(char *map);
void	check_invalid_content(int i);
void	check_empty_lines(char *map);
void	check_empty_file(char *map);
void	check_map(char **map, int width, int height);
void	check_walls(char **map, int width, int height);
void	check_mapsize(int width, int height);
void	check_if_map_rectangular(char **map, int width);
void	check_path(t_game *game);

/*Initializing*/
void	init_images(t_game *game);
void	get_texture(mlx_texture_t **txt, char *path);
void	get_image(t_game *game, mlx_image_t **img, mlx_texture_t *txt);
void	check_if_collectable_or_exit(t_game *game, char **map, int x, int y);

/*Rendering map*/
void	fill_background(t_game *game);
void	render_map(t_game *game);
void	place_floor_or_exit(t_game *game, char c, int x, int y);
void	place_flower_or_player(t_game *game, char c, int x, int y);

/*Movements*/
void	do_movements(mlx_key_data_t keydata, void *param);
void	move_up(t_game *game, char **map, int x, int y);
void	move_down(t_game *game, char **map, int x, int y);
void	move_left(t_game *game, char **map, int x, int y);
void	move_right(t_game *game, char **map, int x, int y);

/*Free*/
void	free_all(t_game *game);
void	free_map(char **map);

#endif