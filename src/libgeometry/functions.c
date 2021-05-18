#include "geometry.h"

void checkforcollisions(
        struct circle* v, int num_of_circles, int collisions[][num_of_circles])
{
    float dbc, dbx, dby; // distance between centres, Xes, Ys
    float sor;           // sum of radiuses

    for (int i = 0; i < num_of_circles; i++) {
        for (int j = 0; j < num_of_circles; j++)
            collisions[i][j] = 0;
    }

    for (int i = 0; i < num_of_circles - 1; i++) {
        for (int j = i + 1; j < num_of_circles; j++) {
            dbx = v[i].x - v[j].x;
            dby = v[i].y - v[j].y;
            dbc = sqrt(fabs((dbx * dbx) + (dby * dby)));
            sor = v[i].radius + v[j].radius;

            if (dbc <= sor && i != j) {
                collisions[i][j] = 1;
                printf("\nCircles %d and %d have collisions\n", i + 1, j + 1);
                printf("Dist btw centres = %f, sum of radiuses = %f\n",
                       dbc,
                       sor);
            }
        }
    }
}

float circle_p(struct circle* v)
{
    float P = 2 * M_PI * v->radius;
    return P;
}

float circle_s(struct circle* v)
{
    float S = M_PI * v->radius * v->radius;
    return S;
}

float get_prmtr(const char* str, int i, char* var_array)
{
    int j = 0;
    char s[15] = "";
    while ((str[i] != ' ') && (str[i] != ',') && (str[i] != ')')) {
        s[j] = str[i];
        j++;
        i++;
    }
    strcpy(var_array, s);
    float x = strtof(var_array, NULL);
    return x;
}

int checkcircle(char* str, struct circle* v, int cur_circle)
{
    char cx[15] = "", cy[15] = "", cr[15] = "";
    char mainstr[] = "circle";
    uint i = 0;

    while (str[i] == ' ') {
        i++;
    }

    for (i = 0; i < strlen(mainstr); i++) {
        if (str[i] != mainstr[i]) {
            return 1;
        }
    }

    while (str[i] == ' ') {
        i++;
    }

    if (str[i] != '(') {
        return 2;
    }
    i++;

    while (str[i] == ' ') {
        i++;
    }

    if (isdigit(str[i])) {
        char* tmp1 = &str[i];
        strtod(tmp1, &tmp1);
        float x = get_prmtr(str, i, cx);
        v[cur_circle].x = x;

        if (*tmp1 != ' ') {
            return 3;
        }
    }

    while (str[i] != ' ') {
        i++;
    }

    while (str[i] == ' ') {
        i++;
    }

    if (isdigit(str[i])) {
        char* tmp2 = &str[i];
        strtod(tmp2, &tmp2);
        float y = get_prmtr(str, i, cy);
        v[cur_circle].y = y;

        if ((*tmp2 != ' ') && (*tmp2 != ',')) {
            return 4;
        }
    }

    while ((str[i] != ' ') && (str[i] != ',')) {
        i++;
    }

    while (str[i] == ' ') {
        i++;
    }

    if (str[i] != ',') {
        return 5;
    } else {
        i++;
    }

    while (str[i] == ' ') {
        i++;
    }

    if (isdigit(str[i])) {
        char* tmp3 = &str[i];
        strtod(tmp3, &tmp3);
        float r = get_prmtr(str, i, cr);
        v[cur_circle].radius = r;

        if ((*tmp3 != ' ') && (*tmp3 != ')')) {
            return 6;
        }
    }

    while ((str[i] != ' ') && (str[i] != ')')) {
        i++;
    }

    if (str[i] != ')') {
        return 7;
    }
    i++;
    while (str[i] != '\0') {
        i++;
    }
    return 0;
}
