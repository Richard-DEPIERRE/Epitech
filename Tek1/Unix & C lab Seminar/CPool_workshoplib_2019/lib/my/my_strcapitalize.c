/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** my strcapitalize
*/

char *my_strcapitalize(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		if (str[i] < 'A' || str[i] > 'z' || (str[i] > 'Z' && str[i] < 'a')) {
			if (str[i + 1] <= 'z' && str[i + 1] >= 'a')
				str[i +  1] = str[i + 1] - 32;
		}
	}
	return (str);
}