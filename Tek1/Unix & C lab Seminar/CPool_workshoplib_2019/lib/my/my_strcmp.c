/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** my str cmp
*/

int my_strcmp(char const *s1, char const *s2)
{
	for (int i = 0; s1[i] != '\0'; i += 1) {
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}