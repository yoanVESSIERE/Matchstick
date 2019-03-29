/*
** EPITECH PROJECT, 2019
** function.c
** File description:
** 
*/
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    if (nb < 0 && (nb * -1) > 9) {
        my_putchar(45);
        nb = nb * -1;
        my_put_nbr(nb / 10);
    }
    else if (nb < 0) {
        my_putchar(45);
        nb = nb * -1;
    }
    my_putchar(nb % 10 + '0');
    return (0);
}
