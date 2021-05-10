#pragma once

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct circle {
    float x;
    float y;
    float radius;
};

float get_prmtr(const char* str, int i, char* cc);
int checkcircle(char* str, struct circle* v);
float circle_p(struct circle* v);
float circle_s(struct circle* v);