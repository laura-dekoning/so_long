#include "so_long.h"

void	test_initialisation(t_game *game)
{
	//Test if data is correctly initiliazed//
	printf("Width:[%i]\n", game->width);
	printf("Height:[%i]\n", game->height);
	printf("Collectables:[%i]\n", game->collectables);
	printf("Collected:[%i]\n", game->collected);
	printf("Steps:[%i]\n", game->steps);
	printf("Player position:[%i][%i]\n", game->player_pos.y, game->player_pos.x);
	printf("Exit position:[%i][%i]\n", game->exit_pos.y, game->exit_pos.x);

	return ;
}
