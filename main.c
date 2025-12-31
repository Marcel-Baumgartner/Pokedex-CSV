#include <stdio.h>
#include <string.h>
#include "pokedex.h"

int main() {

    Pokemon pokedex[MAX_POKEMON];
    char grid[HEIGHT][WIDTH];

    int countPokemon = load_pokedex("pokedex.csv", pokedex);

    while (1) {
        char searchby[5];
        printf("Enter 'name' if you want to search by name.\n");
        printf("Enter 'type' if you want to search by type.\n");
        printf("Enter 'end' if you want to end the program.\n");
        printf("\n");
        scanf("%s", searchby);

        printf("\n");

        if (strcasecmp(searchby, "end") == 0) {
            break;
        }
        else if (strcasecmp(searchby, "name") == 0) {
            search_name(grid, pokedex, countPokemon);
        }
        else if (strcasecmp(searchby, "type") == 0) {
            search_typ(grid, pokedex, countPokemon);
        }
        else {
            printf("Not valid.\n");
        }

        printf("\n");
    }

    return 0;
}
