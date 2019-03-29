/*
** EPITECH PROJECT, 2019
** checking.c
** File description:
** 
*/
#include "my.h"

int checkline(int size, char buff[size], int tab[2], int size_buff)
{
    int i = 0;

    i = lines(&tab[0], buff, size_buff);
    while (i == 84)
        i = lines(&tab[0], buff, size_buff);
    while (tab[0] >= 99 || tab[0] <= 0 || tab[0] > size) {
        if (buff[0] == '\0') {
            i = 1;
            break;
        }
        my_putstr("Error: this line is out of range\n");
        i = lines(&tab[0], buff, size_buff);
        while (i == 84)
            i = lines(&tab[0], buff, size_buff);
    }
    return (i);
}

int check_end(char **s, int size, int player_or_ia)
{
    int i = 0;
    int e = 0;

    for (e = 0; e != size + 2; e++)
        for (i = 0; i != (size * 2 + 1); i++)
            if (s[e][i] == '|')
                player_or_ia = 0;
    return (player_or_ia);
}


void remove_match(char **s, int tab[2], int size)
{
    int nb_stickmax = size * 2 - 1;
    int nb_space = size * 2 - 1 - nb_stickmax / 2;
    int nb_match = 0;
    int i = 1;

    for (i = 0; i != tab[0]; i++)
        nb_space -= 1;
    for (i = 0; s[tab[0]][i] != '\0'; i++)
        if (s[tab[0]][i] == '|')
            nb_match += 1;
    for (i = 0; i != tab[1]; i++, nb_match--)
        s[tab[0]][nb_space + nb_match] = ' ';
}

void print_map(char **s, int size)
{
    int i = 0;

    for (i = 0; i != size + 2; i++) {
            my_putstr(s[i]);
            my_putchar('\n');
        }
}

int ia_turn(char **s, int size, int max)
{
    int i = 0;

    artifice(s, size, max);
    i = check_end(s, size, 2);
    print_map(s, size);
    if (i == 2) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (0);
}