/*
** EPITECH PROJECT, 2019
** ia.c
** File description:
** 
*/
#include "my.h"

int check_intelligence_line(int *ia, int size, int tab[size])
{
    int e = 0;

    for (int i = 1; i != size + 1; i++)
        if (tab[i] == 0)
            e++;
    if (e > 3)
        return (84);
    return (0);
}

int ligne_ia(int *ia, char **s, int size)
{
    int i = 0;
    int e = 0;
    int tab[size];
    int size_match_rm = size;
    static int nb = 0;

    for (i = 1; i != size + 1; tab[i] = 0, i++);
    for (e = 1; e != size + 1; e++)
        for (i = 1; i != size * 2; i++)
            if (s[e][i] == '|')
                tab[e] += 1;
    check_intelligence_line(ia, size, tab);
    for (; tab[size_match_rm - nb] == 0; nb++);
    if (tab[size_match_rm - nb] != 0) {
        *ia = size_match_rm - nb;
    }
    else if (tab[size_match_rm - nb] == 0) {
        nb += 1;
        *ia = size_match_rm - nb;
    }
    return (0);
}

int check_intelligence_match(int *ia, int size, int tab[size], int max)
{
    int e = 0;

    for (int i = 1; i != size + 1; i++)
        if (tab[i] == 0)
            e++;
    if (e > 3)
        return (84);
    return (0);
}

int match_ia(int *ia, char **s, int size, int max)
{
    int i = 0;
    int e = 0;
    int tab[size];
    int line_ia = size;
    static int nb = 0;
    int maxi = max;

    for (i = 1; i != size + 1; tab[i] = 0, i++);
    for (e = 1; e != size + 1; e++)
        for (i = 1; i != size * 2; i++)
            if (s[e][i] == '|')
                tab[e] += 1;
    check_intelligence_match(ia, size, tab, max);
    for (; tab[line_ia - nb] == 0; nb++);
    if (tab[line_ia - nb] >= maxi) {
        *ia = maxi;
    }
    else if (tab[line_ia - nb] < maxi) {
        for (i = 0; tab[line_ia - nb] < maxi; maxi--);
        *ia = maxi;
        nb += 1;
    }
    return (0);
}

int artifice(char **s, int size, int max)
{
    int val_ia[2] = {0};
    int cpysize = size;

    my_putstr("\nAI's turn...\nAI removed ");
    ligne_ia(&val_ia[0], s, cpysize);
    match_ia(&val_ia[1], s, cpysize, max);
    my_put_nbr(val_ia[1]);
    my_putstr(" match(es) from line ");
    my_put_nbr(val_ia[0]);
    my_putchar('\n');
    remove_match(s, val_ia, size);
    return (0);
}