/*
** EPITECH PROJECT, 2019
** match
** File description:
** match
*/

int match(char const *s1, char const *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return (1);
    if (*s1 == '\0' && *s2 == '*')
        return (match(s1, s2 + 1));
    if (*s1 != *s2 && *s2 != '*')
        return (0);
    if (*s1 != '\0' && *s2 == '*')
        return (match(s1, s2 +1) || match(s1 + 1, s2));
    if (*s1 != '\0' && *s2 == '\0')
        return (0);
    match(s1 + 1, s2 + 1);
}
