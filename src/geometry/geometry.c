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

    struct circle *v;

// float get_prmtr(const char *str, int i, struct circle **v, float *z)
// {
//     int j = 0;
//     char s[15] = "";
//     while ((str[i] != ' ') && (str[i] != ',') && (str[i] != ')')){
//         s[j] = str[i];
//         j++;
//         i++;
//     }
//     for(int k = 0; k < strlen(s); k++)
//         printf("%d\n", s[k]);
//     char *tmp = &s[i];
//     float c = strtof(tmp, &tmp);
//     z = c;
//     printf("%f\n", z);
//     return i;
// }

char *get_prmtr(const char *str, int i, char *cc)
{
    int j = 0;
    char s[15] = "";
    while ((str[i] != ' ') && (str[i] != ',') && (str[i] != ')')){
        s[j] = str[i];
        j++;
        i++;
    }
    strcpy(cc, s);
    printf("%s\n", cc);
    return cc;
}

void checkcircle(char* str, struct circle *v)
{
    char cx[15] = "";//, cy[15] = "", r[15] = "";
    char mainstr[] = "circle";
    int i = 0;
    double y, r;
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
     strcpy(cx, get_prmtr(str, i, cx));
    }
    
    float x = strtof(cx, NULL);
    printf("%f\n", x);

    while (str[i] != ' ') {
        i++;
    }

    while (str[i] == ' ') {
        i++;
    }

    if (isdigit(str[i])) {
        char* tmp2 = &str[i];
        y = strtod(tmp2, &tmp2);
        printf("y = %f\n", y);

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
        r = strtod(tmp3, &tmp3);
        printf("radius = %f\n", r);

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

    int max_size = 40;
    FILE* input;
    input = fopen("bin/input.txt", "r");
    if (input == NULL)
        printf("No input file\n");
    char source_str[max_size];
    fgets(source_str, max_size, input);
    fputs(source_str, stdout);
    checkcircle(source_str, v);
    // printf("%f, %f, %f\n", x, y, r);
    return 0;
}