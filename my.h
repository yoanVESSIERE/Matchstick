/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** 
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(int nb);

int my_getnbr(char const *str);

int fill_var(int var, int line);

int lines(int *line, char *buff, size_t size);

int matches(int *match, char *buff, size_t size);

void space_right(int size, char **s);

void space_left(int size, char **s);

int checkline(int size, char buff[size], int tab[2], int size_buff);

int check_end(char **s, int size, int player_or_ia);

void remove_match(char **s, int tab[2], int size);

int artifice(char **s, int size, int max);

int match_ia(int *ia, char **s, int size, int max);

int ligne_ia(int *ia, char **s, int size);

void print_map(char **s, int size);

int ia_turn(char **s, int size, int max);

int loop_error(int tab[2], int size, int size_buff, char buff[size_buff]);