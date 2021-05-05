#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkcircle(char* str)
{
    char mainstr[] = "circle";
    int i = 0;
    double x, y, r;
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
        x = strtod(tmp1, &tmp1);
        printf("x = %f\n", x);

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
    input = fopen("input.txt", "r");
    if (input == NULL)
        printf("No input file\n");
    char source_str[max_size];
    fgets(source_str, max_size, input);
    fputs(source_str, stdout);
    checkcircle(source_str);
    // printf("%f, %f, %f\n", x, y, r);
    return 0;
}