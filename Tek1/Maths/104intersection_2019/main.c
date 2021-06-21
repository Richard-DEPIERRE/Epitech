/*
** EPITECH PROJECT, 2019
** CPE_BSQ_bootstrap_2019
** File description:
**  fs_understand_return_of_ read.c
*/

#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void h_text(void)
{
    write(1, "USAGE\n\t./104intersection opt xp yp zp xv yv zv p\n\nDESCRIPTION\n\t", 63);
    write(1, "opt\t\tsurface option: 1 for a sphere, 2 for a cylinder, 3 for a cone\n", 69);
    write(1, "\t(xp, yp, zp)\tcoordinates of a point by which the light ray passes through\n", 75);
    write(1, "\t(xv, yv, zv)\tcoordinates of a vector parallel to the light ray\n", 64);
    write(1, "\tp\t\tparameter: radius of the sphere, radius of the cylinder, or\n", 65);
    write(1, "\t\t\tangle formed by the cone and the Z-axis\n", 44);
}

void sphere(char **av)
{
    float x0 = atof(av[2]);
    float y0 = atof(av[3]);
    float z0 = atof(av[4]);
    float xv = atof(av[5]);
    float yv = atof(av[6]);
    float zv = atof(av[7]);
    float p = atof(av[8]);

    float d_a = xv * xv + yv * yv + zv * zv;
    float d_b = 2 * xv * x0 + 2 * yv * y0 + 2 * zv * z0;
    float d_c = x0 * x0 + y0 * y0 + z0 * z0 - p * p;
    float delta = (d_b * d_b) - (4 * d_a * d_c);

    printf("Sphere of radius %.0f\n", p);
    printf("Line passing through the point (%.0f, %.0f, %.0f) and parallel to the vector (%.0f, %.0f, %.0f)\n", x0, y0, z0, xv, yv, zv);
    if (delta == 0) {
        printf("1 intersection point:\n");
        float x1 = -((d_b+sqrt(delta))/(2*d_a));
        float x = xv * x1 + x0;
        float y = yv * x1 + y0;
        float z = zv * x1 + z0;
        printf("(%.3f, %.3f, %.3f)\n", x, y, z);
    }
    if (delta > 0) {
        float x1 = -((d_b-sqrt(delta))/(2*d_a));
        float x2 = -((d_b+sqrt(delta))/(2*d_a));
        float x = xv * x1 + x0;
        float y = yv * x1 + y0;
        float z = zv * x1 + z0;
        float x3 = xv * x2 + x0;
        float y3 = yv * x2 + y0;
        float z3 = zv * x2 + z0;
        printf("2 intersection points:\n(%.3f, %.3f, %.3f)\n(%.3f, %.3f, %.3f)\n", x, y, z, x3, y3, z3);
    }
    if (delta < 0)
        printf("No intersection point.\n");
}

void cone(char **av)
{
    float x0 = atof(av[2]);
    float y0 = atof(av[3]);
    float z0 = atof(av[4]);
    float xv = atof(av[5]);
    float yv = atof(av[6]);
    float zv = atof(av[7]);
    float p = atof(av[8]);

    float d_a = pow(xv, 2) + pow(yv, 2) - (pow(zv, 2) * pow(tan(p * (M_PI / 180)), 2));
    float d_b = ((2 * x0 * xv) + (2 * y0 * yv) - ((2 * z0 * zv) * pow(tan(p * (M_PI / 180)), 2)));
    float d_c = pow(x0, 2) + pow(y0, 2) - pow(z0, 2) * pow(tan(p * (M_PI / 180)), 2);
    float delta = (d_b * d_b) - (4 * d_a * d_c);
    if (d_a == 0) {
        printf("Cone with a %0.f degree angle\nLine passing through the point (%.0f, %.0f, %.0f) and parallel to the vector (%.0f, %.0f, %.0f)\nThere is an infinite number of intersection points.\n", d_b, x0, y0, z0, xv, yv, zv);
        return;
    }
    printf("Cone with a %.0f degree angle\n", p);
    printf("Line passing through the point (%.0f, %.0f, %.0f) and parallel to the vector (%.0f, %.0f, %.0f)\n", x0, y0, z0, xv, yv, zv);
    if (delta == 0) {
        printf("1 intersection point:\n");
        float x1 = -((d_b+sqrt(delta))/(2*d_a));
        float x = xv * x1 + x0;
        float y = yv * x1 + y0;
        float z = zv * x1 + z0;
        printf("(%.3f, %.3f, %.3f)\n", x, y, z);
    }
    if (delta > 0) {
        float x1 = -((d_b-sqrt(delta))/(2*d_a));
        float x2 = -((d_b+sqrt(delta))/(2*d_a));
        float x = xv * x1 + x0;
        float y = yv * x1 + y0;
        float z = zv * x1 + z0;
        float x3 = xv * x2 + x0;
        float y3 = yv * x2 + y0;
        float z3 = zv * x2 + z0;
        printf("2 intersection points:\n(%.3f, %.3f, %.3f)\n(%.3f, %.3f, %.3f)\n", x, y, z, x3, y3, z3);
    }
    if (delta < 0)
        printf("No intersection point.\n");
}

void cylindre(char **av)
{
    float x0 = atof(av[2]);
    float y0 = atof(av[3]);
    float z0 = atof(av[4]);
    float xv = atof(av[5]);
    float yv = atof(av[6]);
    float zv = atof(av[7]);
    float p = atof(av[8]);

    float d_a = pow(xv, 2) + pow(yv, 2);
    float d_b = (2 * x0 * xv) + (2 * y0 * yv);
    float d_c = pow(x0, 2) + pow(y0, 2) - pow(p, 2);
    float delta = (d_b * d_b) - (4 * d_a * d_c);
    if (d_a == 0) {
        printf("Cylinder of radius %.0f\nLine passing through the point (%.0f, %.0f, %.0f) and parallel to the vector (%.0f, %.0f, %.0f)\nThere is an infinite number of intersection points.\n", p, x0, y0, z0, xv, yv, zv);
        return;
    }
    printf("Cylinder of radius %.0f\n", p);
    printf("Line passing through the point (%.0f, %.0f, %.0f) and parallel to the vector (%.0f, %.0f, %.0f)\n", x0, y0, z0, xv, yv, zv);
    if (delta == 0) {
        printf("1 intersection point:\n");
        float x1 = -((d_b+sqrt(delta))/(2*d_a));
        float x = xv * x1 + x0;
        float y = yv * x1 + y0;
        float z = zv * x1 + z0;
        printf("(%.3f, %.3f, %.3f)\n", x, y, z);
    }
    if (delta > 0) {
        float x1 = (-(d_b-sqrt(delta))/(2*d_a));
        float x2 = (-(d_b+sqrt(delta))/(2*d_a));
        float x = xv * x1 + x0;
        float y = yv * x1 + y0;
        float z = zv * x1 + z0;
        float x3 = xv * x2 + x0;
        float y3 = yv * x2 + y0;
        float z3 = zv * x2 + z0;
        printf("2 intersection points:\n(%.3f, %.3f, %.3f)\n(%.3f, %.3f, %.3f)\n", x, y, z, x3, y3, z3);
    }
    if (delta < 0)
        printf("No intersection point.\n");
}

int check(char **av)
{
    for (int i = 1; av[i]; i += 1)
        for (int j = 0; av[i][j]; j += 1)
            if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '-')
                return 84;
    if (av[5][0] == '0' && av[6][0] == '0' && av[7][0] == '0')
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 9 && ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        h_text();
        return (0);
    }
    if (check(av) == 84)
        return 84;
    if (av[1][0] != '3' && av[1][0] != '2' && av[1][0] != '1')
        return (84);
    float a = atof(av[8]);
    if (a <= 0)
        return (84);
    if (av[1][0] == '1')
        sphere(av);
    if (av[1][0] == '2')
        cylindre(av);
    if (av[1][0] == '3')
        cone(av);
    return (0);
}