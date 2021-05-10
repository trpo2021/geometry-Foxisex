#include "geometry.h"

float circle_p(struct circle *v)
{
    float P = 2 * M_PI * v->radius;
    return P;
}

float circle_s(struct circle *v)
{
    float S = M_PI * v->radius * v->radius;
    return S;
}

float get_prmtr(const char *str, int i, char *cc)
{
    int j = 0;
    char s[15] = "";
    while ((str[i] != ' ') && (str[i] != ',') && (str[i] != ')')){
        s[j] = str[i];
        j++;
        i++;
    }
    strcpy(cc, s);
    float x = strtof(cc, NULL);
    return x;
}

int checkcircle(char* str, struct circle *v)
{
    char cx[15] = "", cy[15] = "", cr[15] = "";
    char mainstr[] = "circle";
    uint i = 0;
    printf("\n");

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
        v->x = x;

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
        v->y = y;

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
        v->radius = r;

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
    if (str[i] == '\0') {
        printf("the data is entered correctly\n");
    }
    return 0;
} 