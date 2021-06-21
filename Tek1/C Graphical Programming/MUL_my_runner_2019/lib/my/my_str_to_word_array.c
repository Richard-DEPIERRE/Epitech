/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** my getnbr
*/

#include <stdlib.h>

int count_words(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i - 1] != ' ')
            count += 1;
        if (str[i] != ' ' && str[i + 1] == '\0')
            count += 1;
    }
    return (count);
}

int count_letters(char *str)
{
    int letters = 0;
    int i = 0;

    for (; str[i] == ' '; i++) {
    }
    for (; str[i] != ' ' && str[i] != '\0'; i++) {
        letters += 1;
    }
    return (letters);
}

void change_dest_str(char *dest, char *src)
{
    int letter = 0;
    int i = 0;

    for (; src[i] == ' '; i++) {
    }
    for (; src[i] != ' ' && src[i] != '\0'; i++) {
        dest[letter] = src[i];
        letter += 1;
    }
    dest[letter] = '\0';
}

char **my_str_to_word_array(char *str)
{
    int nb_words = count_words(str);
    char **dest;
    int size2 = 0;
    int word_len = 0;
    int i = 0;

    dest = malloc(sizeof(*dest) * (nb_words + 1));
    for (; i != nb_words; i++) {
        size2 = word_len;
        word_len = count_letters(str) + word_len;
        dest[i] = malloc(sizeof(*dest[i]) * (word_len + 1));
        change_dest_str(dest[i], str);
    }
    dest[i] = NULL;
    return (dest);
}