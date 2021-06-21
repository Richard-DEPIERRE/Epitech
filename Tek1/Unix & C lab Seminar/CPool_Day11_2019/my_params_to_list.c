/*
** EPITECH PROJECT, 2019
** my_params_to_list
** File description:
** my parameters to list
*/

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    struct linked_list *element;

    element = malloc(sizeof(*element));
    for (int i = 0; av[i] != 0; i++) {
        element->data = av[i];
        element->next = element;
    return (element);
}
