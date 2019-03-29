/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** 
*/
#include "my.h"

int call_line(int max, int tab[2], int size, char **s)
{
    size_t size_buff = 9000;
    char buff[size];
    int var = 5;
    int i = 0;
    int e = 0;
    int nb_match = 0;

    i = checkline(size, buff, tab, size_buff);
    if (i == 1)
        return (0);
    for (i = 0; s[tab[0]][i] != '\0'; i++)
        if (s[tab[0]][i] == '|')
            nb_match += 1;
    var = fill_var(var, tab[0]);
    i = matches(&tab[1], buff, size_buff);
    while ((tab[1] >= var || tab[1] <= 0 || tab[1] > max) && tab[1] != 0) {
        if (buff[0] == '\0') {
            return (0);
        }
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(max);
        e = loop_error(tab, size, size_buff, buff);
        if (e == 0)
            return (0);
    }
    while (i == 84 || tab[1] == 0 || tab[1] > nb_match) {
        if (tab[1] == 0)
            my_putstr("Error: you have to remove at least one match\n");
        if (tab[1] > nb_match)
            my_putstr("Error: not enough matches on this line\n");
        e = checkline(size, buff, tab, size_buff);
        if (e == 1)
            return (0);
        for (i = 0, nb_match = 0; s[tab[0]][i] != '\0'; i++)
            if (s[tab[0]][i] == '|')
                nb_match += 1;
        i = matches(&tab[1], buff, size_buff);
    }
    my_putstr("Player removed ");
    my_put_nbr(tab[1]);
    my_putstr(" match(es) from line ");
    my_put_nbr(tab[0]);
    my_putchar('\n');
    return (3);
}

void fill_match(int size, char **s)
{
    int i = 0;
    int e = 1;

    for (i = 1; i != size + 1; i++) {
        s[i][0] = '*';
        for (e = 1; e != size * 2; e++)
            s[i][e] = ' ';
        s[i][e] = '*';
    }
    for (e = size; e != 0; e--) {
        for (i = size * 2; i != 1; i--) {
            s[e][i - 1] = '|';
        }
    }
    space_left(size, s);
    space_right(size, s);
}

int game(char **s, int tab[2], int size, int max)
{
    int i = 0;
    int e = 1;

    while (1) {
        my_putstr("\nYour turn:\n");
        e = call_line(max, tab, size, s);
        if (e == 0)
            break;
        remove_match(s, tab, size);
        i = check_end(s, size, 1);
        print_map(s, size);
        if (i == 1) {
            my_putstr("You lost, too bad...\n");
            return (2);
        }
        if (ia_turn(s, size, max) == 1)
            return (1);
    }
    return (0);
}

int print_game_board(int size, int nb_line_to_remove_max)
{
    char **s = NULL;
    int i = 0;
    int x = size * 2 + 2;
    int tab[2] = {0, 0};

    s = malloc(sizeof(char *) * (size + 3));
    for (i = 0; i < x + 1; i++)
        s[i] = malloc(sizeof(char) * x);
    for (i = 0; i != x - 1; i++)
        s[0][i] = '*';
    for (i = 0; i != x - 1; i++)
        s[size + 1][i] = '*';
    for (i = 0; i != size + 2; i++)
        s[i][x - 1] = '\0';
    fill_match(size, s);
    print_map(s, size);
    i = game(s, tab, size, nb_line_to_remove_max);
    return (i);
}

int main(int ac, char *av[])
{
    int i = 0;

    if (ac != 3)
        return (84);
    if (my_getnbr(av[1]) >= 100 || my_getnbr(av[1]) <= 1 ||\
    my_getnbr(av[2]) <= 0)
        return (84);
    i = print_game_board(my_getnbr(av[1]), my_getnbr(av[2]));
    return (i);
}