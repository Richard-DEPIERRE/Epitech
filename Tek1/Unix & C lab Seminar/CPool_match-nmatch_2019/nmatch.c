/*
** EPITECH PROJECT, 2019
** nmatch
** File description:
** nmatch
*/

int nmatch(char const *s1, char const *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return (1);
    if (*s1 == '\0' && *s2 == '*')
        return (nmatch(s1, s2 + 1));
    if (*s1 != *s2 && *s2 != '*')
        return (0);
    if (*s1 != '\0' && *s2 == '*')
        return (nmatch(s1, s2 +1) + nmatch(s1 + 1, s2));
    if (*s1 != '\0' && *s2 == '\0')
        return (0);
    nmatch(s1 + 1, s2 + 1);
}