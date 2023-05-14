#include "so_long.h"

void	map_print(t_map *map)
{
	unsigned int	i;

	i = 0;
	// printf("Length: %u\n", map->cols);
	// printf("Width: %u\n", map->rows);
	// printf("Players: %u\n", map->num_players);
	// printf("Exits: %u\n", map->num_exits);
	// printf("Coins: %u\n", map->num_potions);
	while (i < map->rows)
		printf("%s\n", map->tiles[i++]);
}
