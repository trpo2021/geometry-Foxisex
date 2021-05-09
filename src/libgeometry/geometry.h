#pragma once

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct circle {
	float x;
	float y;
	float radius;
};

float get_prmtr(const char *str, int i, char *cc);
void checkcircle(char* str, struct circle *v);
float circle_p(struct circle *v);
float circle_s(struct circle *v);