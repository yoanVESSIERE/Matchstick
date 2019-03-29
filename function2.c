/*
** EPITECH PROJECT, 2019
** function2.c
** File description:
** 
*/

int cheking(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == '-' || str[i] == '+' || (str[i] >= 48 && str[i] <= 57)) {
    }
    else
        return(i);
    }
    return(i);
}

int sign(int compt, char const *str)
{
    int si = 0;
    int j = 0;

    for (; compt != 0; compt--) {
        if (str[j] == '-') {
            if (si == 1)
                si = 0;
            else
                si = 1;
        }
        else if (str[j] == '+') {
            if (si == 0) {
                si = 0;
            } else
                si = 1;
        } else
            return(si);
    j++;
    }
    return (0);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int calc = 1;
    int result = 0;
    int transi = 0;

    for (; str[i] == '-' || str[i] == '+'; i++);
    transi = i;
    for (; transi != cheking(str); transi++) {
        calc = calc * 10;
    }
    for (; i != cheking(str); i++) {
        result = result + (str[i]-48)*calc;
        calc = calc / 10;
    }
        result = result / 10;
        if (sign(cheking(str), str) == 0) {
        result = result;
    } else
        result = result - (2 * result);
    return(result);
}