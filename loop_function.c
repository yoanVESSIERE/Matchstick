/*
** EPITECH PROJECT, 2019
** loop_function.c
** File description:
** 
*/
#include "my.h"

int loop_error(int tab[2], int size, int size_buff, char buff[size_buff])
{
    int i = 0;
    int e = 0;

    my_putstr(" matches per turn\n");
    i = checkline(size, buff, tab, size_buff);
    if (i == 1)
        return (0);
    i = matches(&tab[1], buff, size_buff);
    while (i == 84) {
        e = checkline(size, buff, tab, size_buff);
        if (i == e)
            return (0);
        i = matches(&tab[1], buff, size_buff);
    }
    return (1);
}