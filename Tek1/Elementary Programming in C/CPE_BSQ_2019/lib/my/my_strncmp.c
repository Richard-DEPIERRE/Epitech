/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** my str cmp for n
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i += 1) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}
