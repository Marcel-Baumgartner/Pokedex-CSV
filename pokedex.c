#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokedex.h"

int load_pokedex(const char *filename, Pokemon pokedex[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("File could not be opened or found.\n");
        return 0;
    }

    char line[LINE_SIZE];
    int count = 0;

    fgets(line, sizeof(line), file); // Header überspringen

    while (fgets(line, sizeof(line), file) && count < MAX_POKEMON) {
        sscanf(line, "%d,%d,%49[^,],%19[^,],%19[^,],%d,%d,%d,%d,%d,%d,%d,%29[^,],%f %*[^,],%f %*s",
               &pokedex[count].id,
               &pokedex[count].number,
               pokedex[count].name,
               pokedex[count].type1,
               pokedex[count].type2,
               &pokedex[count].total,
               &pokedex[count].hp,
               &pokedex[count].atk,
               &pokedex[count].def,
               &pokedex[count].spatk,
               &pokedex[count].spdef,
               &pokedex[count].spd,
               pokedex[count].species,
               &pokedex[count].height,
               &pokedex[count].weight);
        count++;
    }

    fclose(file);
    return count;
}

void create_empty_pokedex(int height, int width, char grid[height][width]) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (y == 0 || y == height-1) {
                grid[y][x] = '*';
            }
            else if (x == 0 || x == width-1) {
                grid[y][x] = '*';
            }
            else {
                grid[y][x] = ' ';
            }
        }
    }
}

void create_pokedex_entry(int height, int width, char grid[height][width], Pokemon pokedex[], int id) {

    char buffer[20];

    sprintf(buffer, "#%03d", pokedex[id].number);
    for (int i = 0; i < strlen(buffer); i++) {
        grid[2][3 + i] = buffer[i];
    }

    for (int i = 0; i < strlen(pokedex[id].name); i++) {
        grid[4][3 + i] = pokedex[id].name[i];
    }

    for (int i = 0; i < strlen(pokedex[id].species); i++) {
        grid[6][3 + i] = pokedex[id].species[i];
    }

    sprintf(buffer, "Height: %5.1fm", pokedex[id].height);
    for (int i = 0; i < strlen(buffer); i++) {
        grid[9][3 + i] = buffer[i];
    }

    sprintf(buffer, "Weight: %5.1fkg", pokedex[id].weight);
    for (int i = 0; i < strlen(buffer); i++) {
        grid[9][22 + i] = buffer[i];
    }

    strcpy(buffer, "Type1:");
    for (int i = 0; i < strlen(buffer); i++) {
        grid[12][8 + i] = buffer[i];
    }

    for (int i = 0; i < strlen(pokedex[id].type1); i++) {
        grid[13][8 + i] = pokedex[id].type1[i];
    }

    strcpy(buffer, "Type2:");
    for (int i = 0; i < strlen(buffer); i++) {
        grid[12][27 + i] = buffer[i];
    }

    for (int i = 0; i < strlen(pokedex[id].type2); i++) {
        grid[13][27 + i] = pokedex[id].type2[i];
    }

    sprintf(buffer, "Total: %3d", pokedex[id].total);
    for (int i = 0; i < strlen(buffer); i++) {
        grid[16][15 + i] = buffer[i];
    }

    sprintf(buffer, "Hp:     %3d", pokedex[id].hp);
    for (int i = 0; i < strlen(buffer); i++) {
        grid[18][6 + i] = buffer[i];
    }

    sprintf(buffer, "Atk:    %3d", pokedex[id].atk);
    for (int i = 0; i < strlen(buffer); i++) {
        grid[20][6 + i] = buffer[i];
    }

    sprintf(buffer, "Def:    %3d", pokedex[id].def);
    for (int i = 0; i < strlen(buffer); i++) {
        grid[22][6 + i] = buffer[i];
    }

    sprintf(buffer, "Sp.Atk: %3d", pokedex[id].spatk);
    for (int i = 0; i < strlen(buffer); i++) {
        grid[18][24 + i] = buffer[i];
    }

    sprintf(buffer, "Sp.Def: %3d", pokedex[id].spdef);
    for (int i = 0; i < strlen(buffer); i++) {
        grid[20][24 + i] = buffer[i];
    }

    sprintf(buffer, "Speed:  %3d", pokedex[id].spd);
    for (int i = 0; i < strlen(buffer); i++) {
        grid[22][24 + i] = buffer[i];
    }
}

void print_pokedex(int height, int width, char grid[height][width]) {

    for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                printf("%c", grid[y][x]);
            }
            printf("\n");
        }
}
