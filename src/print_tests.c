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
	int		i = 0;
	while (game->map[i] != NULL)
	{
		printf("[%s]\n", game->map[i]);
		i++;
	}
	return ;
}

void	map_test(char **map)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
	{
		printf("[%s]\n", map[i]);
		i++;
	}
}

void print_map(char **map) {
    // Initialize row index
    int i = 0;
    // Start looping through the rows
    while (map[i] != NULL) {
        // Initialize column index
        int j = 0;
        // Start looping through the characters in the row
        while (map[i][j] != '\0') {
            // Print the character
            printf("%c", map[i][j]);
            // Move to the next column
            j++;
        }
        // Move to the next row
        i++;
        // Print a newline after each row
        printf("\n");
    }
}
