/*
** EPITECH PROJECT, 2019
** my_print_params
** File description:
** my print params
*/

int my_putstr2(char const *str)
{
    int i = 0;
    
    while (str[i] != '\0') {
        write(1, str[i], 1);
        i++;
    }
    return (0);
}


int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        my_putstr2(argv[i]);
        write(1, '\n', 1);
    }
    return (0);
}
