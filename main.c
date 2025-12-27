#include "pokedex.h"

int main() {
    Pokemon pokedex[MAX_POKEMON];
    load_pokedex("pokedex.csv", pokedex);

    return 0;
}
