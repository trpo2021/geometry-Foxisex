#include <libgeometry/geometry.h>

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
    float P = circle_p(v);
    printf("%f\n", P);
    float S = circle_s(v);
    printf("%f\n", S);
    return 0;
}