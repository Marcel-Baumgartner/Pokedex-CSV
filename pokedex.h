#ifndef POKEDEX_H
#define POKEDEX_H

#define MAX_POKEMON 1500
#define LINE_SIZE 256
#define HEIGHT 25
#define WIDTH 40

typedef struct {
    int id;
    int number;
    char name[50];
    char type1[20];
    char type2[20];
    int total;
    int hp;
    int atk;
    int def;
    int spatk;
    int spdef;
    int spd;
    char species[30];
    float height;
    float weight;
} Pokemon;

int load_pokedex(const char *filename, Pokemon pokedex[]);
void create_empty_pokedex(int height, int width, char grid[height][width]);
void create_pokedex_entry(int height, int width, char grid[height][width], Pokemon pokedex[], int id);
void print_pokedex(int height, int width, char grid[height][width]);

#endif
