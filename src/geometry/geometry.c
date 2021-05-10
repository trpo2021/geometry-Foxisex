#include <libgeometry/geometry.h>

int main()
{
    struct circle* v = malloc(sizeof(struct circle));
    int max_size = 40;
    int out;
    char source_str[max_size];
    char* estr;
    FILE* input;

    input = fopen("bin/input.txt", "r");
    if (input == NULL) {
        printf("No input file\n");
        return 8;
    }

    while (1) {
        estr = fgets(source_str, max_size, input);
        if (estr == NULL) {
            if (feof(input) != 0)
                break;
            else {
                printf("\nError of file reading\n");
                break;
            }
        }
        fputs(source_str, stdout);

        if ((out = checkcircle(source_str, v)) != 0) {
            switch (out) {
            case 1:
                printf("Error.1. Invalid input: did you mean \"circle\"?\n");
                break;
            case 2:
                printf("Error.2. Invalid input: expected \"(\"\n");
                break;
            case 3:
                printf("Error.3. Invalid input: expected space after first "
                       "coordinate\n");
                break;
            case 4:
                printf("Error.4. Invalid input: expected space or \",\" after "
                       "second "
                       "coordinate\n");
                break;
            case 5:
                printf("Error.5. Invalid input: expected \",\"\n");
                break;
            case 6:
                printf("Error.6. Invalid input: expected space or \")\" after "
                       "radius\n");
                break;
            case 7:
                printf("Error.7. Invalid input: expected \")\" after radius\n");
                break;
            }
            return out;
        } else {
            printf("x = %f, y = %f, r = %f\n", v->x, v->y, v->radius);
            float P = circle_p(v);
            printf("Perimetr = %f\n", P);
            float S = circle_s(v);
            printf("Square = %f\n\n", S);
        }
    }
    return 0;
}
