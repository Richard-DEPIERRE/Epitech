/*
** EPITECH PROJECT, 2019
** Final Stumper
** File description:
** Take rush 1 output and say sqaure size and type
*/

#include <unistd.h>
#include <stdlib.h>

char *cat_strcat(char *str, int width, int height);
char *my_strcat(char *dest, char *src);
char *get_str(int nb);
void my_putstr(char *str);
void my_putchar(char c);

int calculate_width(char * str)
{
    int count = 0;

    for (int i = 0; str[i] != '\n'; i += 1) {
        count += 1;
    }
    return (count);
}

int calculate_height(char * str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '\n') {
            count += 1;
        }
    }
    return (count);
}

char *square_type(char *str , int w, int h)
{
    char *type;
    char *type2;
    char *type3;

    if (str[0] == 'o')
        return (type = cat_strcat("[rush1-1] ", w, h));
    if ((w == 1 || h == 1) && str[0] == 'B') {
        type = cat_strcat("[rush1-3] ", w, h);
        type2 = my_strcat(type, cat_strcat(" || [rush1-4] ", w, h));
        type3 = my_strcat(type2, cat_strcat(" || [rush1-5] ", w, h));
        return(type3);
    }
    if (str[0] == '/' || str[0] == '*')
        return (type = cat_strcat("[rush1-2] ", w, h));
    if (str[0] == str[w - 1])
        return (type = cat_strcat("[rush1-3] ", w, h));
    if (str[0] == str[w * (h -1) + (h - 1)])
        return (type = cat_strcat("[rush1-4] ", w, h));
    if (str[0] != str[w - 1] && str[0] != str[w * (h - 1) + (h - 1)])
        return (type = cat_strcat("[rush1-5] ", w, h));
}

int rush3(char * str)
{
    int width = calculate_width(str);
    int height = calculate_height(str);

    if(!width || !height) {
        write(2, "none\n",6);
	return (84);
    }
    if (str[0] != 'A' && str[0] != 'B' && str[0] != 'C') {
        if (str[0] != '/' && str[0] != '*' && str[0] != 'o') {
            write(2, "none\n",6);
            return (84);
        }
    }
    my_putstr(square_type(str, width, height));
    my_putchar('\n');
}

int main(void)
{
    int BUFF_SIZE = 100000;
    char buff[BUFF_SIZE];
    int offset = 0;
    int len;

    while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0 ) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0) {
        return (84);
    }
    rush3(buff);
    return (0);
}
