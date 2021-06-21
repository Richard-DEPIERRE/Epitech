/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <tetris.h>

void opt_letters2(int tmp, tetris_t *tetris)
{
    switch (tmp) {
        case 'q':
            tetris->keys[5] = (keys_t){"key-quit", 1, optarg};
            break;
        case 'w':
            tetris->keys[8] = (keys_t){"without-next", 1, "optarg"};
            break;
        case 'D':
            tetris->keys[10] = (keys_t){"debug", 1, "optarg"};
            break;
        case 'p':
            tetris->keys[9] = (keys_t){"key-pause", 1, optarg};
            break;
        case '?':
            tetris->tmp = 84;
            write(1, "Bad Parameter\n", 14);
            break;
    }
}

void opt_letters(int tmp, tetris_t *tetris)
{
    switch (tmp) {
        case 'L':
            tetris->keys[0] = (keys_t){"level", 1, optarg};
            break;
        case 'l':
            tetris->keys[1] = (keys_t){"key-left", 1, optarg};
            break;
        case 'r':
            tetris->keys[2] = (keys_t){"key-right", 1, optarg};
            break;
        case 't':
            tetris->keys[3] = (keys_t){"key-turn", 1, optarg};
            break;
        case 'd':
            tetris->keys[4] = (keys_t){"key-drop", 1, optarg};
            break;
        default:
            opt_letters2(tmp, tetris);
    }
}

void get_opt2(int ac, char **av, tetris_t *tetris,
struct option *long_option)
{
    int tmp = 0;
    int option_index = 0;

    for (int i = 0; i < 12; i += 1)
        tetris->keys[i] = (keys_t){NULL, 0, NULL};
    tmp = getopt_long(ac, av, "L:l:r:t:d:q:wDp:", long_option, &option_index);
    while (tmp != -1) {
        if (tmp == 0)
            tetris->keys[6] = (keys_t){"map-size", 1, optarg};
        else if (tmp == 1)
            tetris->keys[7] = (keys_t){"help", 1, "optarg"};
        else
            opt_letters(tmp, tetris);
        tmp = getopt_long(ac, av, "L:l:r:t:d:q:wDp:",
        long_option, &option_index);
    }
    if (optind < ac) {
        tetris->tmp = 84;
        write(1, "Bad Parameter\n", 14);
    }
}

int check_arg_error(int ac, char **av)
{
    for (int i = 1; i < ac; i += 1)
        if (av[i][0] == '-' && av[i][1] != 'L' && av[i][1] != 'l' &&
        av[i][1] != 'r' && av[i][1] != 't' && av[i][1] != 'd' &&
        av[i][1] != 'q' && av[i][1] != 'p' && av[i][1] != 'w' &&
        av[i][1] != 'D' && av[i][1] != '-')
            return (84);
        else if (av[i][0] == '-' && av[i][1] == '-' &&
        my_strcmp("--level", av[i]) != 0 &&
        my_strcmp("--key-left", av[i]) != 0 &&
        my_strcmp("--key-right", av[i]) != 0 &&
        my_strcmp("--key-turn", av[i]) != 0 &&
        my_strcmp("--key-drop", av[i]) != 0 &&
        my_strcmp("--key-quit", av[i]) != 0 &&
        my_strcmp("--key-pause", av[i]) != 0 &&
        my_strcmp("--map-size", av[i]) != 0 &&
        my_strcmp("--help", av[i]) != 0 &&
        my_strcmp("--without-next", av[i]) != 0 &&
        my_strcmp("--debug", av[i]) != 0)
            return (84);
    return (0);
}

void get_opt(int argc, char **argv, tetris_t *tetris)
{
    static struct option long_option[] = {
        {"level", required_argument, 0, 'L'},
        {"key-left", required_argument, 0, 'l'},
        {"key-right", required_argument, 0, 'r'},
        {"key-turn", required_argument, 0, 't'},
        {"key-drop", required_argument, 0, 'd'},
        {"key-quit", required_argument, 0, 'q'},
        {"key-pause", required_argument, 0, 'p'},
        {"map-size", required_argument, 0, 0},
        {"help", no_argument, 0, 1},
        {"without-next", no_argument, 0, 'w'},
        {"debug", no_argument, 0, 'D'},
        {0, 0, 0, 0}
    };
    if (check_arg_error(argc, argv) == 84) {
        tetris->tmp = 84;
        write(1, "Bad Parameter\n", 14);
        return;
    }
    get_opt2(argc, argv, tetris, long_option);
}