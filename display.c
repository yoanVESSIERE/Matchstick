/*
** EPITECH PROJECT, 2019
** display.c
** File description:
** 
*/
#include "my.h"

int fill_var(int var, int line)
{
    var = var;

    for (int i = 0; i != line; i += 1)
        var += 1;
    return (var);
}

int lines(int *line, char *buff, size_t size)
{
    my_putstr("Line: ");
    buff[0] = '\0';
    getline(&buff, &size, stdin);
    if (my_getnbr(buff) < 0) {
        my_putstr("Error: this line is out of range\n");
        return (84);
    }
    for (int i = 0; buff[i] != '\0'; i++) {
        if ((buff[i] < '0' || buff[i] > '9') && buff[i] != '\n') {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (84);
        }
    }
    *line = my_getnbr(buff);
    return (0);
}

int matches(int *match, char *buff, size_t size)
{
    my_putstr("Matches: ");
    buff[0] = '\0';
    getline(&buff, &size, stdin);
    for (int i = 0; buff[i] != '\0'; i++)
        if ((buff[i] < '0' || buff[i] > '9') && buff[i] != '\n') {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (84);
        }
    *match = my_getnbr(buff);
    return (0);
}

void space_right(int size, char **s)
{
    int i = 0;
    int e = 0;
    int f = 0;
    int nb_stickligne = size * 2 - 1;
    int nb_space = size * 2 - 1 - nb_stickligne / 2;
    int nb = 0;

    for (e = 1; e != size; e++) {
        for (i = ((size * 2 - 1) / 2 + 2 + nb), f = 1; f + nb !=\
        nb_space; i++, f++) {
            s[e][i] = ' ';
        }
        nb += 1;
    }
}

void space_left(int size, char **s)
{
    int i = 0;
    int e = 0;
    int nb_stickligne = size * 2 - 1;
    int nb_space = size * 2 - 1 - nb_stickligne / 2;
    int nb = 0;

    for (e = 1; e != size; e++) {
        for (i = 1; i != nb_space - nb; i++) {
            s[e][i] = ' ';
        }
        nb += 1;
    }
}
