#include <stdio.h>
#include "pokedex.h"

int main() {

    Pokemon pokedex[MAX_POKEMON];
    char grid[HEIGHT][WIDTH];

    load_pokedex("pokedex.csv", pokedex);

    int id;
    printf("Enter any ID of a Pokemon: ");
    scanf("%d", &id);
    id = id - 1;

    create_empty_pokedex(HEIGHT, WIDTH, grid);
    create_pokedex_entry(HEIGHT, WIDTH, grid, pokedex, id);
    print_pokedex(HEIGHT, WIDTH, grid);

    return 0;
}
