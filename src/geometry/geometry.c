#include <libgeometry/geometry.h>

int main()
{
    int max_num_of_strings = 10, current_string = 1;
    int current_circle = 0;
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
    struct circle circles[max_num_of_strings];

    while (1) {
        if (current_string > max_num_of_strings) {
            printf("\nError.9. Entered too many strings\n");
            return 9;
        }

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

        if ((out = checkcircle(source_str, circles, current_circle)) != 0) {
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
            current_circle++;
            current_string++;
        }
    }

    printf("the data is entered correctly\n");
    for (int i = 0; i < current_circle; i++)
        printf("x = %f,y = %f,radius = %f\nPerimetr = %f,Square = %f\n",
               circles[i].x,
               circles[i].y,
               circles[i].radius,
               circle_p(&circles[i]),
               circle_s(&circles[i]));
    return 0;
}
