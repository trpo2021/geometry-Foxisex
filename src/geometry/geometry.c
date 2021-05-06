#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "geometry.h"

struct circle {
    float x;
    float y;
    float radius;
};

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

void checkcircle(char* str, struct circle *v)
{
    char cx[15] = "", cy[15] = "", cr[15] = "";
    char mainstr[] = "circle";
    int i = 0;
    printf("\n");

    while (str[i] == ' ') {
        i++;
    }

    for (i = 0; i < strlen(mainstr); i++) {
        if (str[i] != mainstr[i]) {
            printf("Invalid input: did you mean \"circle\"?\n");
            exit(0);
        }
    }

    while (str[i] == ' ') {
        i++;
    }

    if (str[i] != '(') {
        printf("Invalid input: expected \"(\"\n");
        exit(0);
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
            printf("Invalid input: expected space after first coordinate\n");
            exit(0);
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
            printf("Invalid input: expected space or \",\" after second "
                   "coordinate\n");
            exit(0);
        }
    }

    while ((str[i] != ' ') && (str[i] != ',')) {
        i++;
    }

    while (str[i] == ' ') {
        i++;
    }

    if (str[i] != ',') {
        printf("Invalid input: expected \",\"\n");
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
            printf("Invalid input: expected space or \")\" after radius\n");
            exit(0);
        }
    }

    while ((str[i] != ' ') && (str[i] != ')')) {
        i++;
    }

    if (str[i] != ')') {
        printf("Invalid input: expected \")\" after radius\n");
    }
    i++;
    while (str[i] != '\0') {
        i++;
    }
    if (str[i] == '\0') {
        printf("the data is entered correctly\n");
    }
} 

int main()
{
    struct circle *v = malloc(sizeof(struct circle));
    int max_size = 40;
    FILE* input;
    input = fopen("bin/input.txt", "r");
    if (input == NULL)
        printf("No input file\n");
    char source_str[max_size];
    fgets(source_str, max_size, input);
    fputs(source_str, stdout);
    checkcircle(source_str, v);
    printf("x = %f, y = %f, r = %f\n", v->x, v->y, v->radius);
    return 0;
}